/*
 * softwareDelay.c
 *
 * Created: 10/21/2019 9:16:41 PM
 *  Author: Ammar Shahin 
 */ 

#include "MCU_Frequency.h"
#include "Typedefs.h"
#include "SwDelay.h"

/* 9 is a factor that we find by try and error to simulate 
 *   how many cycles before counter is decremented.          */
#define  CYCLE_DELAY_FACTOR 9


/*===========================SW_Delay Functions===============================*/
/**
 * Description: Function to make a software Delay in the Melli seconds 
 * @param n_ms the number of ms to delay
 */
void SwDelay_ms(uint32 NoOfMilleSeconds)
{
	sint32 counter;
	counter = NoOfMilleSeconds * (F_CPU / 1000);
	while(counter > 0)
	{
			counter =  counter - CYCLE_DELAY_FACTOR;
	}
}