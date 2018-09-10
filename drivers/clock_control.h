/* 
 * File:   clock_control.h
 * Author: cellis
 *
 * Created on September 9, 2018, 4:36 PM
 */

#ifndef CLOCK_CONTROL_H
#define	CLOCK_CONTROL_H

#define F_CPU   32000000UL // F_CPU must be set to the cpu clock speed for delay routines to be psuedo-accurate
#include <util/delay.h>

typedef struct CLK_config 
{
    uint8_t src;
    uint8_t prescalerA;
    uint8_t prescalerBC;
    uint8_t lock;    
}clock_config;

void clock_init(clock_config *config_clock);

#endif	/* CLOCK_CONTROL_H */

