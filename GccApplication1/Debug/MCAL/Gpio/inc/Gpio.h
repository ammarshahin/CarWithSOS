/*
 * gpio.h
 *
 * Created: 10/21/2019 3:00:30 PM
 *  Author: Ammar Shahin
 */ 


#ifndef T_GPIO_H_
#define T_GPIO_H_

#include "Typedefs.h"
#include "Gpio_Registers.h"
#include "MCU_Frequency.h"

/************************************************************************/
/*				 		defining the PORTS Numbers                      */
/************************************************************************/
#define MYPORTA  0
#define MYPORTB  1
#define MYPORTC  2
#define MYPORTD  3


/************************************************************************/
/*				 Enum for defining PIN numbers                          */
/************************************************************************/
typedef enum EN_PINS
{
	PIN0 = 0,	// defines BIT0 in a register
	PIN1 = 1,	// defines BIT1 in a register
	PIN2 = 2,	// defines BIT2 in a register
	PIN3 = 3,	// defines BIT3 in a register
	PIN4 = 4,	// defines BIT4 in a register
	PIN5 = 5,	// defines BIT5 in a register
	PIN6 = 6,	// defines BIT6 in a register
	PIN7 = 7,	// defines BIT7 in a register
}EN_PINS;

/************************************************************************/
/*				 GPIO functions' prototypes	                            */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Gpio_PortDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Gpio_PortWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Gpio_PortToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Gpio_PortRead(uint8 port);

/*===========================PIN Control===============================*/
/**
 * Description:
 * @param port
 * @param pins
 * @param direction
 */
void Gpio_PinDirection(uint8 port, uint8 pins, uint8 direction);

/**
 * Description:
 * @param port
 * @param pins
 * @param value
 */
void Gpio_PinWrite(uint8 port, uint8 pins, uint8 value);

/**
 * Description:
 * @param port
 * @param pins
 */
void Gpio_PinToggle(uint8 port, uint8 pins);

/**
 * Description:
 * @param port
 * @param pin
 * @return
 */
uint8 Gpio_PinRead(uint8 port, uint8 pin);

/*===========================Upper Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Gpio_UpperNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Gpio_UpperNibbleWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Gpio_UpperNibbleToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Gpio_UpperNibbleRead(uint8 port);

/*===========================Lower Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Gpio_LowerNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Gpio_LowerNibbleWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Gpio_LowerNibbleToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Gpio_LowerNibbleRead(uint8 port);


#endif /* T_GPIO_H_ */