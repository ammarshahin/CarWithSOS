/*
 * Ultrasonic.h
 *
 *  Created on: Oct 28, 2019
 *      Author: AVE-LAP-070
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


/************************************************************************/
/*				          Functions Prototype                           */
/************************************************************************/

/**
 * Function : Ultrasonic_Init
 * Description : This function is used to initialize the UltraSonic module.
 * Return : the function Returns nothing
 */
void Ultrasonic_Init(void);

/**
 * Function : Ultrasonic_Trigger
 * Description : This function is used to Trigger the UltraSonic module by sending a High
 *	    for at least a 10 micro seconds and then pull it low.
 * Return : the function Returns nothing
 */
void Ultrasonic_Trigger(void);

/**
 * Function : Ultrasonic_CalculateDistance
 * Description : This function is used to Calculate the Distance by receiving the Ton from the ICU Unit
 *                           and then returning the Distance.
 * Return : the function Returns the Distance in centimeters.
 */
uint32 Ultrasonic_CalculateDistance(void);

/**
 * Function : Ultrasonic_Display
 * Description : This function is used to Display the Distance of the Measurement on LCD
 * Return void
 */
void Ultrasonic_Display(void);

#endif /* ULTRASONIC_H_ */
