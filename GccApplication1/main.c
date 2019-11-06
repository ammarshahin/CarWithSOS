/*
 * Car_Static_Design.c
 *
 * Created: 11/5/2019 12:29:26 PM
 * Author : Ammar Shahin
 */ 

#include "CarControl.h"

int main(void)
{
	Car_Init();
    while (1) 
    {
		Car_Action();
    }
}

