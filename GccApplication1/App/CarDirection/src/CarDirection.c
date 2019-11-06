/*
 * CarDirection.c
 *
 * Created: 11/5/2019 12:42:44 PM
 *  Author: Ammar Shahin
 */

#include "DC_Motor.h"
#include "DC_Motor_cfg.h"

void Move_Forward(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}
void Move_Backward(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}

void Move_RotateRight(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_BACK);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_FORWARD);
}
void move_RotateLeft(void)
{
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_0, DC_MOTOR_FORWARD);
	DC_Motor_Set_Direction(DC_MOTOR_CHANNEL_1, DC_MOTOR_BACK);
}
void Stop(void)
{
	DC_Motor_Stop(DC_MOTOR_CHANNEL_0);
	DC_Motor_Stop(DC_MOTOR_CHANNEL_1);
}
