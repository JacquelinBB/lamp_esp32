#ifndef LED
#define LED

#include <esp_err.h>
#include <driver/gpio.h>
#include <rom/ets_sys.h>
#include "driver/uart.h"

#define LUMINARIA GPIO_NUM_18

#define HIGH 1
#define LOW 0

esp_err_t gpio_configure(void);
esp_err_t basic_gpio_set(void);

#endif