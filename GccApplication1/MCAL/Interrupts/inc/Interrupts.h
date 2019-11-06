/*
 * interrupt_Lib.h
 *
 * Created: 10/26/2019 2:15:28 AM
 *  Author: ammarPC
 */ 


#ifndef INTERRUPT_LIB_H_
#define INTERRUPT_LIB_H_

#include "BitMasking_Macros.h"

/* defines for the External Interrupt Registers */
#define SREG_T  *((reg_type)0X5F)
#define GICR_T  *((reg_type)0X5B)
#define MCUCR_T *((reg_type)0X55)


/* Bit numbers */

/* GICR_T */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* On and of the global interrupt mask */
 
#define Interrupts_On()     SET_BIT(SREG_T,7)

#define interrupts_Off()    CLR_BIT(SREG_T,7)


/* Initialize the interrupt 0 */
#define INT0_Init_LowLevel()    SET_BIT(GICR_T,INT0);     \
								CLR_BIT(MCUCR_T,ISC00);     \
								CLR_BIT(MCUCR_T,ISC01) 

#define INT0_Init_AnyChange()   SET_BIT(GICR_T,INT0);     \
								SET_BIT(MCUCR_T,ISC00);   \
								CLR_BIT(MCUCR_T,ISC01)

#define INT0_Init_FallingEdge()   SET_BIT(GICR_T,INT0);     \
								  SET_BIT(MCUCR_T,ISC01);   \
								  CLR_BIT(MCUCR_T,ISC00)

#define INT0_Init_RisingEdge()    SET_BIT(GICR_T,INT0);     \
								  SET_BIT(MCUCR_T,ISC01);   \
								  SET_BIT(MCUCR_T,ISC00)

/* Initialize the interrupt 1 */
#define INT1_Init_LowLevel()	    SET_BIT(GICR_T,INT1);     \
									CLR_BIT(MCUCR_T,ISC10);   \
									CLR_BIT(MCUCR_T,ISC11)

#define INT1_Init_AnyChange()       SET_BIT(GICR_T,INT1);     \
									SET_BIT(MCUCR_T,ISC10);   \
									CLR_BIT(MCUCR_T,ISC11)

#define INT1_Init_FallingEdge()     SET_BIT(GICR_T,INT1);     \
									SET_BIT(MCUCR_T,ISC11);  \
									CLR_BIT(MCUCR_T,ISC10)

#define INT1_Init_RisingEdge()      SET_BIT(GICR_T,INT1);     \
									SET_BIT(MCUCR_T,ISC11);  \
									SET_BIT(MCUCR_T,ISC10)

/* Initialize the interrupt 2 */
#define INT2_Init_Edge()      SET_BIT(GICR_T,INT2)


/* defines for the interrupt handler */				
#define _VECTOR(n)  __vector_##n  
#define INT0_vect	_VECTOR(1)
#define TIMER0_OVF_vect			_VECTOR(11)
#define TIMER1_OVF_vect			_VECTOR(9)
#define TIMER2_OVF_vect			_VECTOR(5)

#define __INTR_ATTRS used, externally_visible

#define ISR_T(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

#endif /* INTERRUPT_LIB_H_ */