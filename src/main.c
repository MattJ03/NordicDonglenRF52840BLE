#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/hci.h>

void main(void)
{
    int err;

    // Initialize Bluetooth stack
    err = bt_enable(NULL);
    if (err) {
        printk("Bluetooth initialization failed (err %d)\n", err);
        return;
    }
    printk("Bluetooth initialized\n");

    // Define advertising parameters
    const struct bt_le_adv_param *adv_param = BT_LE_ADV_PARAM(
        BT_LE_ADV_OPT_CONN, 0x20, 0x40, NULL);  // 32ms to 64ms interval

    // Advertising data (including name)
    static const struct bt_data ad[] = {
        BT_DATA_BYTES(BT_DATA_FLAGS, BT_LE_AD_NO_BREDR),
        BT_DATA(BT_DATA_NAME_COMPLETE, "Zephyr_Device", 14),  // Advertise with name
    };

    // Start advertising
    err = bt_le_adv_start(adv_param, ad, ARRAY_SIZE(ad), NULL, 0);
    if (err) {
        printk("Advertising failed to start (err %d)\n", err);
    } else {
        printk("Advertising started\n");
    }

    // Main loop
    while (1) {
        k_sleep(K_SECONDS(1));
    }
}