/*
 * Created: 10/22/2019 2:03:42 PM
 * Author : Ammar Shahin
 */ 

/************************************************************************/
/*                            Includes                                  */
/************************************************************************/

#include "SOS.h"
#include "LCD.h"
#include "App.h"
#include "pushButton.h"
#include "CarControl.h"
#include "Ultrasonic.h"

/************************************************************************/
/*                            Private Macros                            */
/************************************************************************/
#define TASK_SYSINIT_PRIORITY 5
#define TASK_PBAndLCD_PRIORITY 3

#define TASK_SYSINIT_PERIODICITY  2
#define TASK_PBAndLCD_PERIODICITY 100

#define SYSTEM_FINISH_INITIALIZATION 4
#define LCD_SHIFT_FACTOR 4

/************************************************************************/
/*                       Static(Private) variables                      */
/************************************************************************/
static EnumSysState_type SysStatus = SystemNotInitalized;

/************************************************************************/
/*                            SOS Tasks                                 */
/************************************************************************/

/* Task: SystemInit_Task 
 * Description : This task is to initialize the System [LCD and PushButton]
 * it takes 5 Systicks and deletes it self afterward */
void SystemInit_Task(void)
{
	static uint8 CounterFinishInit = INITIAL_ZERO;
	LCD_Init();
	pushButton_Init();
	Car_Init();
	Ultrasonic_Init();
	CounterFinishInit++;
	
	if (CounterFinishInit == SYSTEM_FINISH_INITIALIZATION )
	{
		SysStatus = SystemInitialized;
		Sos_Delete_Task(SystemInit_Task);
	}
	else
	{
		// Do Nothing
	}
}


/* Task: PushButtonAndLCD_Task           
 * Description : This task is to Test the PushButton and the LCD by Showing the number of times the Switch is pressed*/
void PushButtonAndLCD_Task(void)
{	
	if( SystemInitialized == SysStatus )
	{	
			Car_Action();
			Ultrasonic_Display();
	}
	else
	{
		// Do Nothing
	}
	
}

/************************************************************************/
/*                          Main Function                               */
/************************************************************************/
int main(void)
{
	/* Init the OS Scheduler */
	Sos_Init();	
	
	/* Create the System Tasks */
	Sos_Create_Task(SystemInit_Task,TASK_SYSINIT_PRIORITY,TASK_SYSINIT_PERIODICITY);
	Sos_Create_Task(PushButtonAndLCD_Task,TASK_PBAndLCD_PRIORITY,TASK_PBAndLCD_PERIODICITY);
		
	/* Start the OS */
	Sos_Run();
}