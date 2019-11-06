/*
 * CarDirection.c
 * Description : This File is to control the Direction of the Car
 * Created: 11/5/2019 12:42:44 PM
 *  Author: Ammar Shahin
 */


/************************************************************************/
/*                        Files Includes                                */
/************************************************************************/
#include "DC_Motor.h"
#include "DC_Motor_cfg.h"


/************************************************************************/
/*                        Functions Definitions                         */
/************************************************************************/
/**
 * Function : Move_Forward
 * Description: This function is to make car move forward
 *  it take nothing and returns nothing
 */

void Move_Forward(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : Move_Backward
 * Description: This function is to make car move Backward
 *  it take nothing and returns nothing
 */
void Move_Backward(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}

/**
 * Function : Move_RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void Move_RotateRight(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}

/**
 * Function : move_RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void Move_RotateLeft(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}


/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */

void Stop(void)
{
	DC_Motor_Stop(DC_MOTOR_CHANNEL_0);
	DC_Motor_Stop(DC_MOTOR_CHANNEL_1);
}
