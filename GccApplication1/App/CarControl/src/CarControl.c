/*
* Car_Control.c
*
* Created: 11/5/2019 1:51:29 PM
*  Author: Ammar Shahin
*/


/************************************************************************/
/*                        Files Includes                                */
/************************************************************************/
#include "DC_Motor.h"
#include "CarDirection.h"
#include "CarControl.h"
#include "pushButton.h"


/************************************************************************/
/*                         Macros and Defines                           */
/************************************************************************/
#define SLOW_SPEED 30
#define FAST_SPEED 100
#define NORMAL_SPEED 50

#define CAUTIOUS_DISTANCE 60
#define DENGEROUS_DISTANCE 30
/************************************************************************/
/*                        Functions Definitions                         */
/************************************************************************/

/**
 * Function : Car_Init
 * Description: This function is to initialize the car 
 *  it Don't take any thing and returns nothing
 */
void Car_Init(void)
{
	DC_Motor_Init(DC_MOTOR_CHANNEL_0);
	DC_Motor_Init(DC_MOTOR_CHANNEL_1);
	DC_Motor_Start(DC_MOTOR_CHANNEL_0);
	DC_Motor_Start(DC_MOTOR_CHANNEL_1);
}


/**
 * Function : Car_Action
 * Description: This function is to Implement the car logic 
 *  it Don't take any thing and returns nothing
 */
void Car_Action(void)
{	
	if(pushButton_Get_Status(PUSH_BUTTON0)) /* No obstacle Go Forward */
	{
		Move_Forward();
	}
	
	if (pushButton_Get_Status(PUSH_BUTTON1))  /* Obstacle on the near range */
	{
		Move_Backward();
	}
}