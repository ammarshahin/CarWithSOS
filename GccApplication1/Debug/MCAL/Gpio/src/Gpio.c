/*
 * gpio.c
 *
 * Created: 10/21/2019 3:00:07 PM
 *  Author: Ammar Shahin
 */ 

#include "Gpio.h"

/************************************************************************/
/*				 GPIO functions' Definitions                            */
/************************************************************************/
/*===========================PORT Control===============================*/
/**
 * Description: Used to set the Direction of the PORT
 * @param port : the port Name [MYPORTA,MYPORTB,MYPORTC, or MYPORTD]
 * @param direction : the Direction
 */
void Gpio_PortDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case MYPORTA : 
						DDR_A = direction;
						break;
		case MYPORTB :
						DDR_B = direction;
						break;
		case MYPORTC :
						DDR_C = direction;
						break;
		case MYPORTD :
						DDR_D = direction;
						break;	
	}
}

/**
 * Description: Write A value to the Port that has been selected as an output
 * @param port : the Port that I want to write to
 * @param value : the value to set (0 >> 128)
 */
void Gpio_PortWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case MYPORTA :
			PORT_A = value;
			break;
		case MYPORTB :
			PORT_B = value;
			break;
		case MYPORTC :
			PORT_C = value;
			break;
		case MYPORTD :
			PORT_D = value;
			break;
	}
}
/**
 * Description: toggle the value of the port
 * @param port : the port
 */
void Gpio_PortToggle(uint8 port)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A ^= 0xff;
		break;
		case MYPORTB :
		PORT_B ^= 0xff;
		break;
		case MYPORTC :
		PORT_C ^= 0xff;
		break;
		case MYPORTD :
		PORT_D ^= 0xff;
		break;
	}
}

/**
 * Description: Read the value of the port (PIN Reg)
 * @param port : the Port that I want to Read from (PIN Reg only)
 * @return the value of the Reg
 */
uint8 Gpio_PortRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case MYPORTA :
		result =  PIN_A;
		break;
		case MYPORTB :
		result = PIN_B;
		break;
		case MYPORTC :
		result = PIN_C;
		break;
		case MYPORTD :
		result = PIN_D;
		break;
	}
	return result;
}

/*===========================PIN Control===============================*/
/**
 * Description:
 * @param port
 * @param pins
 * @param direction
 */
void Gpio_PinDirection(uint8 port, uint8 pins, uint8 direction)
{
	switch(port)
	{
		case MYPORTA :
		{
		switch(direction)
		{
		case SET_IN : 
		DDR_A &= ~(pins);
		break;
		case SET_OUT : 
		DDR_A |= (pins);
		break;
		}
		}
		break;
		
		case MYPORTB :
		{
		switch(direction)
		{
		case SET_IN :
			DDR_B &= ~(pins);
			break;
		case SET_OUT :
			DDR_B |= (pins);
			break;
		}
		}
		break;
		case MYPORTC :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_C &= ~(pins);
				break;
				case SET_OUT :
				DDR_C |= (pins);
				break;
			}
		}
		break;
		case MYPORTD :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_D &= ~(pins);
				break;
				case SET_OUT :
				DDR_D |= (pins);
				break;
			}
		}
		break;
	}
}

/**
 * Description:
 * @param port
 * @param pins
 * @param value
 */
void Gpio_PinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch(value)
	{
		case HIGH:
			switch(port)
			{
					case MYPORTA :
						PORT_A |= (pins);
						break;
					case MYPORTB :
						PORT_B |= (pins);
						break;
					case MYPORTC :
						PORT_C |= (pins);
						break;
					case MYPORTD :
						PORT_D |= (pins);
						break;
		}
		break;
		
		case LOW : 
		switch(port)
		{
			case MYPORTA :
			PORT_A &= ~(pins);
			break;
			case MYPORTB :
			PORT_B &= ~(pins);
			break;
			case MYPORTC :
			PORT_C &= ~(pins);
			break;
			case MYPORTD :
			PORT_D &= ~(pins);
			break;
		}
		break;	
	}
}
/**
 * Description:
 * @param port
 * @param pins
 */
void Gpio_PinToggle(uint8 port, uint8 pins)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A ^= (pins);
		break;
		case MYPORTB :
		PORT_B ^= (pins);
		break;
		case MYPORTC :
		PORT_C ^= (pins);
		break;
		case MYPORTD :
		PORT_D ^= (pins);
		break;
	}
}
/**
 * Description:
 * @param port
 * @param pin
 * @return
 */
uint8 Gpio_PinRead(uint8 port, uint8 pin)
{
	uint8 result = 0;
	switch(port)
	{
		case MYPORTA :
		result = ((PIN_A >> pin) & 0x01);
		break;
		case MYPORTB :
		result = ((PIN_B >> pin) & 0x01);
		break;
		case MYPORTC :
		result = ((PIN_C >> pin) & 0x01);
		break;
		case MYPORTD :
		result = ((PIN_D >> pin) & 0x01);
		break;
	}
	return result;
}
/*===========================Upper Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Gpio_UpperNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case MYPORTA :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_A &= 0x0f;
				break;
				case SET_OUT :
				DDR_A |= 0xf0;
				break;
			}
		}
		break;
		case MYPORTB :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_B &= 0x0f;
				break;
				case SET_OUT :
				DDR_B |= 0xf0;
				break;
			}
		}
		break;
		case MYPORTC :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_C &= 0x0f;
				break;
				case SET_OUT :
				DDR_C |= 0xf0;
				break;
			}
		}
		break;
		case MYPORTD :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_D &= 0x0f;
				break;
				case SET_OUT :
				DDR_D |= 0xf0;
				break;
			}
		}
		break;
	}
}
/**
 * Description:
 * @param port
 * @param value
 */
void Gpio_UpperNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A = ((PORT_A & 0x0f) | (value << 4));
		break;
		case MYPORTB :
		PORT_B = ((PORT_B & 0x0f) | (value << 4));
		break;
		case MYPORTC :
		PORT_C = ((PORT_C & 0x0f) | (value << 4));
		break;
		case MYPORTD :
		PORT_D = ((PORT_D & 0x0f) | (value << 4));
		break;
	}
}
/**
 * Description:
 * @param port
 */
void Gpio_UpperNibbleToggle(uint8 port)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A ^= 0xf0;
		break;
		case MYPORTB :
		PORT_B ^= 0xf0;
		break;
		case MYPORTC :
		PORT_C ^= 0xf0;
		break;
		case MYPORTD :
		PORT_D ^= 0xf0;
		break;
	}
}

/**
 * Description:
 * @param port
 * @return
 */
uint8 Gpio_UpperNibbleRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case MYPORTA :
		result = (PIN_A >> 4);
		break;
		case MYPORTB :
		result = (PIN_B >> 4);
		break;
		case MYPORTC :
		result = (PIN_C >> 4);
		break;
		case MYPORTD :
		result = (PIN_D >> 4);
		break;
	}
	return result;
}

/*===========================Lower Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Gpio_LowerNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case MYPORTA :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_A &= 0xf0;
				break;
				case SET_OUT :
				DDR_A |= 0x0f;
				break;
			}
		}
		break;
		case MYPORTB :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_B &= 0xf0;
				break;
				case SET_OUT :
				DDR_B |= 0x0f;
				break;
			}
		}
		break;
		case MYPORTC :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_C &= 0xf0;
				break;
				case SET_OUT :
				DDR_C |= 0x0f;
				break;
			}
		}
		break;
		case MYPORTD :
		{
			switch(direction)
			{
				case SET_IN :
				DDR_D &= 0xf0;
				break;
				case SET_OUT :
				DDR_D |= 0x0f;
				break;
			}
		}
		break;
	}
}

/**
 * Description:
 * @param port
 * @param value
 */
void Gpio_LowerNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A = (PORT_A & 0xf0) | (value & 0x0f);
		break;
		case MYPORTB :
		PORT_B = (PORT_B & 0xf0) | (value & 0x0f);
		break;
		case MYPORTC :
		PORT_C = (PORT_C & 0xf0) | (value & 0x0f);
		break;
		case MYPORTD :
		PORT_D = (PORT_D & 0xf0) | (value & 0x0f);
		break;
	}
}

/**
 * Description:
 * @param port
 */
void Gpio_LowerNibbleToggle(uint8 port)
{
	switch(port)
	{
		case MYPORTA :
		PORT_A ^= 0x0f;
		break;
		case MYPORTB :
		PORT_B ^= 0x0f;
		break;
		case MYPORTC :
		PORT_C ^= 0x0f;
		break;
		case MYPORTD :
		PORT_D ^= 0x0f;
		break;
	}
}
/**
 * Description:
 * @param port
 * @return
 */
uint8 Gpio_LowerNibbleRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case MYPORTA :
		result = (PIN_A & 0x0f);
		break;
		case MYPORTB :
		result = (PIN_B & 0x0f);
		break;
		case MYPORTC :
		result = (PIN_C & 0x0f);
		break;
		case MYPORTD :
		result = (PIN_D & 0x0f);
		break;
	}
	return result;
}
