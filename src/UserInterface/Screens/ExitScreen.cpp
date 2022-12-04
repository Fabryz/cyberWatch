#include "config.h"
#include "ExitScreen.h"
#include <LilyGoWatch.h>
#include "UserInterface/Components/Logo.h"

void ExitScreen::show() {

	TTGOClass::getWatch()->tft->fillRect(
		0,
		0,
		TTGOClass::getWatch()->tft->width(),
		TTGOClass::getWatch()->tft->height(),
		COLOR_BACKGROUND
	);

	Logo *logo = new Logo();
	logo->render();

	char message[20] = "Bye bye";
	TTGOClass::getWatch()->tft->drawString(
		message,
		0,
		TTGOClass::getWatch()->tft->height() - 30
	);
}
