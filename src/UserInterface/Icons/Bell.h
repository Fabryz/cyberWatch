#pragma once

#include <pgmspace.h>
#include "IconStruct.h"
#include <Arduino.h>

const IconStruct iconBell PROGMEM = {
	24,
	24,
	{
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x08,0x07e0,0x07e0,0x08,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x0c,0x07e0,0x07e0,0x07e0,0x07e0,0x0c,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x18,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0c,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0c,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x10,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x10,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x10,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x10,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x18,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x18,0x0000,0x0000,0x0000
,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000
,0x0000,0x0000,0x10,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x10,0x0000,0x0000
,0x0000,0x08,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x08,0x0000
,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0
,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0
,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0
,0x07e0,0x0c,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x0c,0x07e0
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0c,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0c,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x07e0,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000



	}
};