#if !defined(RACECHRONO_BIY_BLE_DEVICE_CONFIG_H)
#define RACECHRONO_BIY_BLE_DEVICE_CONFIG_H

// Change the value
#define DEVICE_NAME "CAN2BLEv2"
#define EZSBC_BOARD

// OTA updates over wifi if the OTA_UPDATES flag is defined.
// At bootup the device will search for the defined SSID and start up a webserver upon connection.
// The new .bin file can be uploaded by navigating to http://<ip address>/update
#define OTA_UPDATES
#define OTA_WIFI_SSID "JDUB2"
#define OTA_WIFI_PASSWORD "5127899241"

// We use RaceChronoPidMap to keep track of stuff for each CAN ID.
// In this implementation, we're going to ignore "update intervals" requested by
// RaceChrono, and instead send every Nth CAN message we receive, per CAN ID, where
// N is different for different PIDs.
const uint8_t DEFAULT_UPDATE_RATE_DIVIDER = 10;

// You need to pick one of the provided configurations below, or define your own
// configuration. Your configuration should define the following two functions:

// Returns an "update rate divider for a given CAN ID.
// If the value is N, only every Nth message received from the CAN bus will be
// communicated to RaceChrono via BLE.
uint8_t getUpdateRateDivider(uint32_t can_id);

// Here are some configurations you can pick from by uncommenting one of the
// following lines:
//#include "configs/ft86_gen1.h"
//#include "configs/ft86_gen2.h"
#include "configs/e46.h"

// Once you read all the comments and address what they asked of you, please
// uncomment the nest line:
#define I_READ_THE_COMMENTS

#if !defined(I_READ_THE_COMMENTS)
#error Please open config.h and read all the comments!
#endif // I_READ_THE_COMMENTS

#endif // RACECHRONO_BIY_BLE_DEVICE_CONFIG_H
