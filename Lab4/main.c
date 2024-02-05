/**
 * main.c
 */

#include "stdint.h"
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "Pin/pin.h"
#include "Pin/EXTI_pin.h"
#include "UART/uart.h"

Std_ReturnType ret = E_NOT_OK;


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

pin_t led_red = {
  .port = PORT_F,
  .pin = PIN_1,
  .direction = PIN_OUTPUT,
  .state = PIN_LOW
};


uart_t uart = {
  .uart_Select =UART_0 ,
  .baud_rate = UART_BAUD_RATE_115200,
  .data_length = LENGTH_8_BIT ,
  .stopBit_length = PARITY_NONE ,
  .parity_type = STOP_BIT_ONE
};

void main(void)
{

    ret = SysClock_Init();

    ret = Pin_Init(&led_green);
    ret = Pin_Init(&led_blue);
    ret = Pin_Init(&led_red);
    ret = UART_Init(&uart);


    while(1){
        uint8_t chr = UART_ReceiveChar(&uart,&ret);
        switch(chr){
            case 'r':
                ret = Pin_Write(&led_green, PIN_LOW);
                ret = Pin_Write(&led_blue, PIN_LOW);
                ret = Pin_Write(&led_red, PIN_HIGH);
                ret = UART_SendString(&uart, "Red is ON -rl");
                break;
            case 'g':
                ret = Pin_Write(&led_green, PIN_HIGH);
                ret = Pin_Write(&led_blue, PIN_LOW);
                ret = Pin_Write(&led_red, PIN_LOW);
                ret = UART_SendString(&uart, "green is ON -rl");
                break;
            case 'b':
                ret = Pin_Write(&led_green, PIN_LOW);
                ret = Pin_Write(&led_blue, PIN_HIGH);
                ret = Pin_Write(&led_red, PIN_LOW);
                ret = UART_SendString(&uart, "blue is ON-rl");
                break;
            case 'o':
                ret = Pin_Write(&led_green, PIN_LOW);
                ret = Pin_Write(&led_blue, PIN_LOW);
                ret = Pin_Write(&led_red, PIN_LOW);
                ret = UART_SendString(&uart, "All is OFF");
                break;
            default:
                break;


        }
    }


}


