/*
 * Timers_PCFG.c
 *
 * Created: 11/4/2019 2:04:00 PM
 *  Author: Ammar Shahin
 */ 

#include "Gpio_Registers.h"
#include "Timers_Lcfg.h"
#include "MCU_Frequency.h"

#define Counter_Default 20000

Timers_CFG_S cfg_s = {
    TIMER0,
    Timers_MODE,
    Counter_Default,
    INTERRUPT,
    F_CPU,
}; 