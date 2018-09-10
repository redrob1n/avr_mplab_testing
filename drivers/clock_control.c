/*
 *
 */

#include "clock_control.h"
#include <avr/io.h>

static void clock_set_config(clock_config* config_clock)
{
    CLK.CTRL    |= (config_clock->src << CLK_SCLKSEL_gp);
    CLK.PSCTRL  |= (config_clock->prescalerA << CLK_PSADIV_gp);
    CLK.PSCTRL  |= (config_clock->prescalerBC << CLK_PSBCDIV_gp);
    CLK.LOCK    |= (config_clock->lock << CLK_LOCK_bp);
}

void clock_init(clock_config* config_clock)
{
    clock_set_config(config_clock);
}
