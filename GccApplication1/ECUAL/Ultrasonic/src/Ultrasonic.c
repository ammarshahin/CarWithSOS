/*
 * Ultrasonic.c
 *
 * Created: 11/5/2019 2:20:05 PM
 *  Author: Ammar Shahin
 */ 
#include "Gpio.h"
#include "Sw_ICU.h"
#include "Ultrasonic_Cfg.h"
#include "Ultrasonic.h"
#include "SwDelay.h"



#define NANOSECONDS_FACTOR 1000000000.0
#define SOUNDSPEED_FACTOR  (34300/2)

void UltraSonic_Init(void)
{
	SwICU_Init();
	Gpio_PinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,SET_OUT);
	Gpio_PinDirection(ULTRASONIC_ECHO_PORT,ULTRASONIC_ECHO_PIN,SET_IN);
}

void Ultrasonic_Trigger(void)
{
	Gpio_PinWrite(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,HIGH);
	SwDelay_ms(10);
	Gpio_PinWrite(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOW);
}

uint32 Ultrasonic_CalculateDistance(void)
{
	uint32 theDistance;
	uint64 raising_time_ns;
	SwICU_Read(&raising_time_ns);
	theDistance = ( ( raising_time_ns / NANOSECONDS_FACTOR ) * SOUNDSPEED_FACTOR );
	return theDistance;	
}