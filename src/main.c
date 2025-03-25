#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/types.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/bluetooth/conn.h>

#define DEVICE_NAME "Zephyr_BLE"  //for the nordic dongle
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

static void connected(struct bt_conn *con, uint8_t err) {
	if(err) {
		printk("The connection failed\n");
	} else {
		printk("Connection established\n");
	}

	static void disconnected(struct bt_conn *conn, uint8_t reason) {
		printk("Disconnected: reasons: %s\n", reason);
	}

	BT_CONN_CB_DEFINE(conn_callbacks) = {
		.connected = connected,
		.disconnected = disconnected,
	};
}