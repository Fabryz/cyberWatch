#include "config.h"
#include "Logo.h"
#include <LilyGoWatch.h>
#include "splash.h"

void Logo::render() {
	TTGOClass::getWatch()->tft->drawXBitmap(0, 0, splash_xbm, splash_width, splash_height, TFT_BLACK, TFT_GREEN);
};
