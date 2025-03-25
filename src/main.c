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
}

	static void disconnected(struct bt_conn *conn, uint8_t reason) {
		printk("Disconnected: reasons: %s\n", reason);
	}

	BT_CONN_CB_DEFINE(conn_callbacks) = {
		.connected = connected,
		.disconnected = disconnected,
	};

	int main() {
		int err; 

		printk("Starting Bluetooth scan...\n");
        err = bt_enable(NULL);
		if(err) {
			printk("Bluetooth init failed.\n");
			return;
		}
		printk("Bluetooth initialised\n");

		struct bt_le_adv_param *adv_params = BT_LE_ADV_CONN;
		struct bt_data ad[] = {
			BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR),
        BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
		};

		err = bt_le_adv_start(adv_params, ad, ARRAY_SIZE(ad), NULL, 0);
		if(err) {
			printk("Advertisement failed\n");
			return;
		}

		printk("Advertisment started\n");
		return 0;
	}
