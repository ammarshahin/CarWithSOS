/*
 * Ultrasonic.h
 *
 *  Created on: Oct 28, 2019
 *      Author: AVE-LAP-070
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void UltraSonic_Init(void);

void Ultrasonic_Trigger(void);

uint32 Ultrasonic_CalculateDistance(void);


#endif /* ULTRASONIC_H_ */
