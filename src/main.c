#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/types.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/blueooth/gap.h>
#include <zephyr/bluetooth/conn.h>

#define DEVICE_NAME "Zephyr_BLE"  //for the nordic dongle
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)