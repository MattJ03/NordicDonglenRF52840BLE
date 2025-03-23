#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <stdio.h>

#define LED_NODE_DT_ALIAS(led0)  //will get the dongle from the DT, led0 is the first device 

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

void main(void) {

	if(!device_is_ready(led.port)) {
		printf("The device is not in a state to be configured%s\n");
		return;  //led not ready try again 
	}

	gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

	while(1) {
		gpio_pin_toggle_dt(&led);
		k_msleep(500);
	}

}