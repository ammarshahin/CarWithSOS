/*
 * registers_ATmega32.h
 *
 * Created: 10/21/2019 3:31:12 PM
 *  Author: Ammar Shahin
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Typedefs.h"

/********* Memory GPIO Register Maping *************/ 
#define PORT_A  *((reg_type)0X3B)
#define DDR_A   *((reg_type)0X3A)
#define PIN_A   *((reg_type)0X39)
#define PORT_B  *((reg_type)0X38)
#define DDR_B   *((reg_type)0X37)
#define PIN_B   *((reg_type)0X36)
#define PORT_C  *((reg_type)0X35)
#define DDR_C   *((reg_type)0X34)
#define PIN_C   *((reg_type)0X33)
#define PORT_D  *((reg_type)0X32)
#define DDR_D   *((reg_type)0X31)
#define PIN_D   *((reg_type)0X30)

#endif /* REGISTERS_H_ */