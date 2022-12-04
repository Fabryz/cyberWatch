#pragma once

#include "config.h"

class BatteryManager {

	public:

		static BatteryManager *getInstance();

		uint8_t getCapacity();

		bool isCharging();

		bool handleCablePlugInIRQ();

		bool handleCablePlugRemoveIRQ();

		void energyConsumptionSavingsSettings();

		void updateCapacity();

		uint8_t getUpdatedCapacity();

	protected:

			static BatteryManager *inst;

			int lastCapacity = 0;

			BatteryManager();
};
