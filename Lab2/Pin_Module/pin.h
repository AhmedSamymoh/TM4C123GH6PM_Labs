/*
 * pin.h
 *
 *  Created on: Feb 4, 2024
 *      Author: AhmedSamy
 */

#ifndef PIN_PIN_H_
#define PIN_PIN_H_

/* Section : Includes */

#include "stdint.h"
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"

/* Section: Macro Declarations */


#define PORT_A        GPIO_PORTA_BASE
#define PORT_B        GPIO_PORTB_BASE
#define PORT_C        GPIO_PORTC_BASE
#define PORT_D        GPIO_PORTD_BASE
#define PORT_E        GPIO_PORTE_BASE
#define PORT_F        GPIO_PORTF_BASE

#define PIN_0         GPIO_PIN_0
#define PIN_1         GPIO_PIN_1
#define PIN_2         GPIO_PIN_2
#define PIN_3         GPIO_PIN_3
#define PIN_4         GPIO_PIN_4
#define PIN_5         GPIO_PIN_5
#define PIN_6         GPIO_PIN_6
#define PIN_7         GPIO_PIN_7


#define PIN_INPUT     GPIO_DIR_MODE_IN
#define PIN_OUTPUT    GPIO_DIR_MODE_OUT
#define NULL          (void *)0

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

typedef struct{
    uint32_t port;
    uint32_t pin;
    uint32_t direction;
    uint32_t state;
} pin_t;


typedef enum{
    E_NOT_OK,
    E_OK
} Std_ReturnType;

typedef enum{
    PIN_LOW = 0,
    PIN_HIGH
} state_t;

Std_ReturnType SysClock_Init(void);
Std_ReturnType Pin_Init(pin_t * _pin);
Std_ReturnType Pin_Write(pin_t * _pin , state_t state);
state_t Pin_Read(pin_t * _pin ,  Std_ReturnType * ret);
void Delay_ms(uint32_t Delayms);

/* Section: Function Declarations */














#endif /* PIN_PIN_H_ */
