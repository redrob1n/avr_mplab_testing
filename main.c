/* 
 * File:   main.c
 * Author: cellis
 *
 * Created on September 9, 2018, 4:29 PM
 */

#include <avr/io.h>
#include "drivers/clock_control.h"

static void system_initialize(void);

/*
 * 
 */
int main(void) 
{
    PORTQ.DIR |= 0x08;
    PORTQ.OUT |= 0x08;
    
    system_initialize();
    
    for(;;)
    {
        PORTQ.OUT ^= 0x08;
        _delay_ms(1000);
    }
}

void system_initialize(void)
{
    clock_config clk = {
        .src = CLK_SCLKSEL_RC32M_gc,
        .prescalerA = 0x00,
        .prescalerBC = 0x00,
        .lock = 0x0
    };
    
    clock_init(&clk);
}

