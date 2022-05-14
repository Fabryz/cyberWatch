#include "config.h"

#include <LilyGoWatch.h>

#include "CyberWatch.h"

#include "Display/Display.h"
#include "System/InactivityWatcher.h"
#include "System/Esp32.h"
#include "System/BatteryManager.h"
#include "System/MoveSensor.h"
#include "System/MotorController.h"

CyberWatch* CyberWatch::_inst;

CyberWatch *CyberWatch::getInstance() {
	if (CyberWatch::_inst == nullptr) {
CyberWatch::_inst = new CyberWatch();
	}
	return CyberWatch::_inst;
}

void CyberWatch::init() {
	Serial.begin(9600);
	Serial.println("cyberWatch starting");

	TTGOClass::getWatch()->begin();
	TTGOClass::getWatch()->motor_begin();
	Display::getInstance()->init();

	BatteryManager::getInstance()->energyConsumptionSavingsSettings();
	Esp32::getInstance()->initIRQ();
	MoveSensor::getInstance()->initIRQ();
	Display::getInstance()->showSplashScreen();
};

void CyberWatch::loop() {
	int16_t x, y;

	while(1) {
		bool PEKshort = false;

		_handleBatteryLowActions();
		_handleEsp32IRQ(PEKshort);

		if (
			InactivityWatcher::getInstance()->isInactive()
			&& MoveSensor::getInstance()->isTilt()
		) {
			InactivityWatcher::getInstance()->markActivity();
		}
		if (
			(
				TTGOClass::getWatch()->getTouch(x, y)
				&& (x != 257 && y != 2) //some kind of HW error in my LILLYGO T-Watch (short circuit?)
			)
			|| PEKshort
		) {
			InactivityWatcher::getInstance()->markActivity();
		}
		if (InactivityWatcher::getInstance()->isInactive()) {
			Display::getInstance()->turnDisplayOff();
			esp_sleep_enable_timer_wakeup(TICK_SLEEP);
			esp_sleep_enable_ext1_wakeup(GPIO_SEL_39, ESP_EXT1_WAKEUP_ANY_HIGH);
			esp_light_sleep_start();
		} else {
		if (!Display::getInstance()->isDisplayOn()) {
			Display::getInstance()->turnDisplayOn();
		}
		Display::getInstance()->render();
		delay(TICK_WAKEUP);
		}
	}
};

void CyberWatch::turnOff() {
	Display::getInstance()->turnDisplayOn();
	Display::getInstance()->showExitScreen();
	MotorController::vibrate(2);
	delay(2000);
	TTGOClass::getWatch()->shutdown();
}



void CyberWatch::_handleCabelConnection() {
	if (BatteryManager::getInstance()->handleCabelPlugInIRQ()) {
		MotorController::vibrate();
	}
	if (
		BatteryManager::getInstance()->handleCabelPlugInIRQ()
		|| BatteryManager::getInstance()->handleCabelPlugRemoveIRQ()
	) {
		InactivityWatcher::getInstance()->markActivity();
	}
}

void CyberWatch::_handleEsp32IRQ(bool &PEKshort) {
	if (Esp32::getInstance()->isIRQ()) {
		TTGOClass::getWatch()->power->readIRQ();
		if( TTGOClass::getWatch()->power->isPEKLongtPressIRQ()) {
			turnOff();
		}
		_handleCabelConnection();
		if(TTGOClass::getWatch()->power->isPEKShortPressIRQ()) {
			PEKshort = true;
		}
		Esp32::getInstance()->cleanIRQ();
	}
}


void CyberWatch::_handleBatteryLowActions() {
	uint8_t vibrationCount = 0;
	uint8_t capacity = BatteryManager::getInstance()->getCapacity();
	if (BatteryManager::getInstance()->isCharging()) {
		_batteryLowWarnVibrateOnLevel = 101;
		return;
	}
	if (capacity == BATTERY_LOW) {
		vibrationCount = 1;
	}

	if (capacity == BATTERY_VERY_LOW) {
		vibrationCount = 2;
	}

	if (
		vibrationCount > 0
		&& capacity < _batteryLowWarnVibrateOnLevel
	) {
		InactivityWatcher::getInstance()->markActivity();
		MotorController::vibrate(vibrationCount);
		_batteryLowWarnVibrateOnLevel = capacity;
	}
}

CyberWatch::CyberWatch() {
}
