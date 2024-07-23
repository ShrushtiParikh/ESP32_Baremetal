#include <stdio.h>
#include <stdint.h>
#include "esp32/rom/ets_sys.h"

#define GPIO_OUT_W1TS_REG  0x3FF44008
#define GPIO_OUT_W1TC_REG  0x3FF4400C
#define GPIO_ENABLE_REG    0x3FF44020
#define GPIO2              2
#define DELAY_MS           500

void delay_ms(uint32_t milliseconds) {
    ets_delay_us(milliseconds * 1000);
}

void app_main(void)
{
    volatile uint32_t* gpio_out_w1ts_reg = (volatile uint32_t*)GPIO_OUT_W1TS_REG;
    volatile uint32_t* gpio_out_w1tc_reg = (volatile uint32_t*)GPIO_OUT_W1TC_REG;
    volatile uint32_t* gpio_enable_reg = (volatile uint32_t*)GPIO_ENABLE_REG;

    *gpio_enable_reg = (1 << 2);
    while(1)
    {
        *gpio_out_w1ts_reg = (1 << 2);
        delay_ms(DELAY_MS);
        *gpio_out_w1tc_reg = (1 << 2);
        delay_ms(DELAY_MS);
    }
    
}
