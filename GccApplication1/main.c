/*
 * main.c
 * Description : The main File that runs first in the project
 * Created: 11/5/2019 12:29:26 PM
 * Author : Ammar Shahin
 */ 

/************************************************************************/
/*                           Files Includes                             */
/************************************************************************/
#include "CarControl.h"

/************************************************************************/
/*                        Functions Definitions                         */
/************************************************************************/
int main(void)
{
	/* Initializing the car */
	Car_Init();
	
    while (1) 
    {
	/* Applying the Car moving logic */
		Car_Action();
    }
}

