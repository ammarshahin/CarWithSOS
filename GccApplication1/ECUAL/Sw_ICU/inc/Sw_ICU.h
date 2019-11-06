/*
 * icu.h
 *
 * Created: 11/5/2019 12:29:51 PM
 *  Author: AVE-LAP-025
 */ 

#ifndef ICU_H_
#define ICU_H_


/************************************************************************/
/*				           Files Includes                               */
/************************************************************************/
#include "Typedefs.h"

/************************************************************************/
/*				          Functions Prototype                           */
/************************************************************************/

/*
 * Description: This function initializes the ICU module 
 * Parameter: void
 * Return : The status of the function [OK or NOT_OK]
 */
uint8 SwICU_Init(void);
/*
 * Description: This function Reads all Timer 0 counts (Including overflow ) 
 * Parameter: 
				Output :  Reading_value >> used to return the value of the value Ton 
 * Return : The status of the function [OK or NOT_OK]
 */
uint8 SwICU_Read(uint64* Reading_value);
/*
 * Description: This function enables the ICU functionality 
 * Parameter: void
 * Return : The status of the function [OK or NOT_OK]
 */
uint8 SwICU_Enable(void);
/*
 * Description: This function disables the ICU functionality
 * Parameter: void 
 * Return : The status of the function [OK or NOT_OK]
 */
uint8 SwICU_Disable(void);

#endif /* ICU_H_ */