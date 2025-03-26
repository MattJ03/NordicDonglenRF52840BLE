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

    // Define advertising parameters correctly
    struct bt_le_adv_param *adv_param = BT_LE_ADV_PARAM(
        BT_LE_ADV_OPT_CONNECTABLE, BT_GAP_ADV_FAST_INT_MIN_2, BT_GAP_ADV_FAST_INT_MAX_2, NULL);

    // Start advertising
    err = bt_le_adv_start(adv_param, NULL, 0, NULL, 0);
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