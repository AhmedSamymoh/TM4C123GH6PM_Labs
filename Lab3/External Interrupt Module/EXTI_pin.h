/*
 * EXTI_pin.h
 *
 *  Created on: Feb 5, 2024
 *      Author: AhmedSamy
 */

#ifndef PIN_EXTI_PIN_H_
#define PIN_EXTI_PIN_H_




//----------------------------------------------- Include Files ------------------------------------
#include "pin.h"
#include "inc/hw_types.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"

//---------------------------------------------- Macros --------------------------------------------

// interrupt types
#define GPIO_FALLING_EDGE_    GPIO_FALLING_EDGE         // Interrupt on falling edge
#define GPIO_RISING_EDGE_     GPIO_RISING_EDGE          // Interrupt on rising edge
#define GPIO_BOTH_EDGES_      GPIO_BOTH_EDGES           // Interrupt on both edges
#define GPIO_LOW_LEVEL_       GPIO_LOW_LEVEL            // Interrupt on low level
#define GPIO_HIGH_LEVEL_      GPIO_HIGH_LEVEL           // Interrupt on high level
#define GPIO_DISCRETE_INT_    GPIO_DISCRETE_INT         // Interrupt for individual pins

//------------------------------- User define datatypes ------------------------


//----------------------- Functions Decelarations ------------------------------
Std_ReturnType Pin_INT_Config(pin_t *pin);

#endif /* PIN_EXTI_PIN_H_ */
