/*
 * CarDirection.h
 * Description : This File is to control the Direction of the Car
 * Created: 11/5/2019 12:34:23 PM
 *  Author: Ammar Shahin
 */ 


#ifndef DIR_CONTROL_H_
#define DIR_CONTROL_H_

/************************************************************************/
/*				 Direction Control functions' Prototypes                */
/************************************************************************/
/**
 * Function : Move_Forward
 * Description: This function is to make car move forward
 *  it take nothing and returns nothing
 */
void Move_Forward(void);

/**
 * Function : Move_Backward
 * Description: This function is to make car move Backward
 *  it take nothing and returns nothing
 */
void Move_Backward(void);


/**
 * Function : Move_RotateRight
 * Description: This function is to make car Rotate Right
 *  it take nothing and returns nothing
 */
void Move_RotateRight(void);

/**
 * Function : move_RotateLeft
 * Description: This function is to make car Rotate Left
 *  it take nothing and returns nothing
 */
void Move_RotateLeft(void);

/**
 * Function : Stop
 * Description: This function is to make car Stop
 *  it take nothing and returns nothing
 */
void Stop(void);

#endif /* DIR_CONTROL_H_ */