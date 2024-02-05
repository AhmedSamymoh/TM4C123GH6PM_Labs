/**
* main.c
*/

#include "stdint.h"
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "pin.h"
#include "EXTI_pin.h"

Std_ReturnType ret = E_NOT_OK;
void ISR();

pin_t led_green = {
 .port = PORT_F,
 .pin = PIN_3,
 .direction = PIN_OUTPUT,
 .state = PIN_LOW
};

pin_t led_blue = {
 .port = PORT_F,
 .pin = PIN_2,
 .direction = PIN_OUTPUT,
 .state = PIN_LOW
};

pin_t Btn1 = {
 .port = PORT_F,
 .pin = PIN_4,
 .direction = PIN_INPUT,
 .state = PIN_LOW,

 .INT_Type= GPIO_RISING_EDGE_,
 .INT_priority = 0x00,
 .PORT_InterruptHandler = ISR
};

void ISR(){
   uint8_t ExtIntPin = 0;

   ExtIntPin = GPIOIntStatus(Btn1.port, true);

   if(ExtIntPin == Btn1.pin ){
       GPIOIntClear(Btn1.port, Btn1.pin);
       ret = Pin_Write(&led_green, PIN_LOW);
       ret = Pin_Write(&led_blue, PIN_HIGH);
       SysCtlDelay(10000000);
       ret  = Pin_Write(&led_blue, PIN_LOW);
   }
}


void main(void)
{

   ret = SysClock_Init();

   ret = Pin_Init(&led_green);
   ret = Pin_Init(&led_blue);
   ret = Pin_Init(&Btn1);
   ret = Pin_INT_Config(&Btn1);
   while(1){

       ret  = Pin_Write(&led_green, PIN_LOW);
       Delay_ms(500);
       ret = Pin_Write(&led_green, PIN_HIGH);
       Delay_ms(500);
   }


}


