#include "config.h"

#include "MainScreen.h"

#include "UserInterface/Components/InfoPanel.h"
#include "UserInterface/Components/Toolbar.h"

MainScreen* MainScreen::inst;

MainScreen *MainScreen::getInstance() {
	if (MainScreen::inst == nullptr) {
		MainScreen::inst = new MainScreen();
	}
	return MainScreen::inst;
}

void MainScreen::render() {
	this->getCurrentApp()->render();
	if (this->getCurrentApp()->hasToolbar()) {
		this->toolbar->render();
	}
	this->infoPanel->render();
}

MainScreen::MainScreen() {
	this->createApps();
	this->toolbar = new Toolbar();
	this->infoPanel = new InfoPanel();
}

void MainScreen::handleSwipeHorizontal(int vector) {
	this->getCurrentApp()->setIsActive(false);
	this->currentApp += vector;
	if (this->currentApp > APPS) {
		this->currentApp = 0;
	}

	if (this->currentApp < 0) {
		this->currentApp = APPS;
	}

	this->getCurrentApp()->setShouldReRender(true);
	this->toolbar->setShouldReRender(true);
	this->getCurrentApp()->setIsActive(true);
	this->clear();
	this->render();
}

void MainScreen::handleSwipeVertical(int vector) {
	if (this->getCurrentApp()->handleSwipeVertical(vector) == true) {
		this->clear();
	}
}

void MainScreen::handlePEKShort() {
	if (this->getCurrentApp()->handlePEKShort() == true) {
		this->clear();
	}
}

bool MainScreen::isSleepForbidden() {
	bool rslt = false;
	for (int8_t i = 0; i <= APPS; i++) {
		if (apps[i]->isSystemSleepForbidden() == true) {
			rslt = true;
		}
	}
	return rslt;
}

void MainScreen::handleTouch(uint8_t x, uint8_t y) {
	if (this->getCurrentApp()->controlModeIsTouch() == true) {
		if (this->getCurrentApp()->handleTouch(x, y) == true) {
			this->clear();
		}
	}
}

void  MainScreen::setToDefaultApp() {
	if (this->currentApp != 0) {
		this->clear();
		this->currentApp = 0;
		this->apps[0]->setShouldReRender(true);
	}
}

void MainScreen::clear() {
	TTGOClass::getWatch()->tft->fillRect(
		0,
		0,
		TTGOClass::getWatch()->tft->width(),
		TTGOClass::getWatch()->tft->height(),
		COLOR_BACKGROUND
	);
}

App *MainScreen::getCurrentApp() {
	return this->apps[this->currentApp];
}