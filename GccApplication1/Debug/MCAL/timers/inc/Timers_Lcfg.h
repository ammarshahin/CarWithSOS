/*
 * Timers_LCFG.h
 *
 * Created: 11/4/2019 2:04:00 PM
 *  Author: Ammar Shahin
 */ 
#ifndef  _Timers_LCFG_H
#define  _Timers_LCFG_H

#include "Typedefs.h"

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2

#define Timers_MODE    0
#define Counter_MODE  1

#define INTERRUPT     1
#define POLLING       0

typedef struct Timers_CFG_S{
	uint8  ch_no;
	uint8  Timers_Mode;
	uint16 Timers_count;
	uint8  Timers_Interrupt;
	uint32 CPU_CLK;
}Timers_CFG_S;

extern Timers_CFG_S cfg_s;

#endif /* _Timers_LCFG_H */
