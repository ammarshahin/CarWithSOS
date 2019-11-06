/*
* Car_Control.c
*
* Created: 11/5/2019 1:51:29 PM
*  Author: Ammar Shahin
*/
#include "DC_Motor.h"
#include "Ultrasonic.h"
#include "CarDirection.h"
#include "CarControl.h"
#include <SwDelay.h>


void Car_Init(void)
{
	UltraSonic_Init();
	DC_Motor_Init(DC_MOTOR_CHANNEL_0);
	DC_Motor_Init(DC_MOTOR_CHANNEL_1);
	DC_Motor_Start(DC_MOTOR_CHANNEL_0);
	DC_Motor_Start(DC_MOTOR_CHANNEL_1);
}


void Car_Action(void){
	uint8 distance = 200;
	Ultrasonic_Trigger();
	distance = Ultrasonic_CalculateDistance();
	if(distance > 60)
	{
		Move_Forward();
		DC_Motor_Set_Speed(95);
	}
	else if ( (distance < 60) && (distance > 30) )
	{
		Move_RotateRight();
		DC_Motor_Set_Speed(50);
		SwDelay_ms(100);
	}
	else if(distance < 30)
	{
		DC_Motor_Set_Speed(30);
		Move_Backward();
		SwDelay_ms(100);
	}
}