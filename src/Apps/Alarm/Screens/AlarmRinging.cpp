#include "config.h"

#include "AlarmRinging.h"

#include <LilyGoWatch.h>

#include "Apps/Alarm/AlarmModel.h"
#include "Core/InactivityWatcher.h"
#include "UserInterface/AppRunner.h"
#include "Core/Hardware/MotorController.h"
#include "Core/Hardware/Display.h"

void AlarmRinging::render() {
	if (this->lastVibrationTime == 0) {
		this->renderMsgBox();
	}
	if (millis() - 400 > this->lastVibrationTime) {
		InactivityWatcher::getInstance()->markActivity();
		MotorController::vibrate(1);
		this->lastVibrationTime = millis();
	}
}

bool AlarmRinging::handlePEKShort() {
	AppRunner::getInstance()->setToDefaultApp();
	return false;
}

bool AlarmRinging::handleLongTouch(uint8_t x, uint8_t y) {
	AppRunner::getInstance()->setToDefaultApp();
	return false;
}

void AlarmRinging::renderMsgBox() {
	TTGOClass::getWatch()->tft->setTextSize(3);
	TTGOClass::getWatch()->tft->drawRect(
		10,
		30,
		TTGOClass::getWatch()->tft->width() - 20,
		40 + TTGOClass::getWatch()->tft->fontHeight() * 2,
		COLOR_MAIN_1
	);
	TTGOClass::getWatch()->tft->drawString(
		"Alarm",
		(TTGOClass::getWatch()->tft->width() - TTGOClass::getWatch()->tft->textWidth("Alarm")) / 2,
		50
	);

	char timeStr[6];
	(void)snprintf(timeStr, sizeof(timeStr), "%02d:%02d", this->alarmHour, this->alarmMinute);
	TTGOClass::getWatch()->tft->drawString(
		timeStr,
		(TTGOClass::getWatch()->tft->width() - TTGOClass::getWatch()->tft->textWidth(timeStr)) / 2,
		50 + TTGOClass::getWatch()->tft->fontHeight()
	);
	Display::getInstance()->resetTypographySettings();
}

AlarmRinging::AlarmRinging(uint8_t alarmHour, uint8_t alarmMinute) {
	this->alarmHour = alarmHour;
	this->alarmMinute = alarmMinute;
}
