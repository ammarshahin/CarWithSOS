/*
 * DC_Motor.c
 *
 * Created: 11/5/2019 1:06:51 PM
 *  Author: AVE-LAP-44
 */ 

#include "Typedefs.h"
#include "Gpio.h"
#include "Timers.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor.h"

#define MOTOR_FREQUENCY_IN_HZ 500


void DC_Motor_Init(uint8 Channel)
{
	Av_timer1Init(T1_PWM_PhaseCorrect_ICR1_MODE,T1_OC1A_CLEAR,T1_PRESCALER_1024,0,0,0,0,T1_POLLING);
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 : 
					/* Initiate the Motor pin Direction */
					Gpio_PinDirection(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_1,SET_OUT);
					Gpio_PinDirection(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_2,SET_OUT);
	
					/* Initiate the Motor pin  */
					Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_1,LOW);
					Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_2,LOW);
		break;
		case DC_MOTOR_CHANNEL_1 : 
					/* Initiate the Motor pin Direction */
					Gpio_PinDirection(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_1,SET_OUT);
					Gpio_PinDirection(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_2,SET_OUT);
		
					/* Initiate the Motor pin  */
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_1,LOW);
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_2,LOW);
		break;
		default:
		break;
	}
}


uint8 DC_Motor_Set_Speed(uint8 Speed)
{
	if(Speed <= 100)
	{
		Av_timer1PWM(Speed,MOTOR_FREQUENCY_IN_HZ);
		return OK;
	}
	else
	{
		return NOT_OK;
	}
}


uint8 DC_Motor_Set_Direction(uint8 Channel , uint8 Direction)
{
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 :
			switch(Direction)
			{
				case DC_MOTOR_FORWARD :
						/* Set the Motor pin */
						Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_1,HIGH);
						Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_2,LOW);
				break;
				case DC_MOTOR_BACK : 
						/* Set the Motor pin */
						Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_1,LOW);
						Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_2,HIGH);
				break;
				default:
				break;
			}
		break;
		case DC_MOTOR_CHANNEL_1 :
			switch(Direction)
			{
				case DC_MOTOR_FORWARD :
					/* Set the Motor pin */
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_1,HIGH);
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_2,LOW);
				break;
				case DC_MOTOR_BACK :
					/* Set the Motor pin */
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_1,LOW);
					Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_2,HIGH);
				break;
				default:
				break;
		}
		break;
	}
	return OK;
}


void DC_Motor_Stop(uint8 Channel)
{
	switch(Channel)
	{
		case DC_MOTOR_CHANNEL_0 : 
		Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_1,LOW);
		Gpio_PinWrite(DC_MOTOR_CHANNEL_0_PORT,DC_MOTOR_CHANNEL_0_PIN_2,LOW);
		break;
		case DC_MOTOR_CHANNEL_1 : 
		Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_1,LOW);
		Gpio_PinWrite(DC_MOTOR_CHANNEL_1_PORT,DC_MOTOR_CHANNEL_1_PIN_2,LOW);
		break;
		default:
		break;	
	}		
}


void DC_Motor_Start(uint8 Channel)
{
	DC_Motor_Set_Speed(50); // 50 As a default speed
	Av_timer1Start();
	DC_Motor_Set_Direction(Channel,DC_MOTOR_FORWARD); // Move Forward as A default Direction
}