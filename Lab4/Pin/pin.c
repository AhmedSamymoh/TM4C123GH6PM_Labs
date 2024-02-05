/*
 * pin.c
 *
 *  Created on: Feb 4, 2024
 *      Author: AhmedSamy
 */

#include "pin.h"



Std_ReturnType Pin_Init(pin_t * _pin){
    Std_ReturnType ret = E_NOT_OK;

    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

        switch(_pin->port){
            case PORT_A:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_A, _pin->pin);
                    GPIOPinWrite(PORT_A, _pin->pin , 0);
                    GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_A, _pin->pin);
                    GPIOPadConfigSet(PORT_A, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

                }else{/* Nothing */}

                break;


            case PORT_B:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_B, _pin->pin);
                    GPIOPinWrite(PORT_B, _pin->pin , 0);
                    GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_B, _pin->pin);
                    GPIOPadConfigSet(PORT_B, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
                }else{/* Nothing */}


                break;
            case PORT_C:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_C, _pin->pin);
                    GPIOPinWrite(PORT_C, _pin->pin , 0);
                    GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_C, _pin->pin);
                    GPIOPadConfigSet(PORT_C, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
                }else{/* Nothing */}


                break;

            case PORT_D:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_D, _pin->pin);
                    GPIOPinWrite(PORT_D, _pin->pin , 0);
                    GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_D, _pin->pin);
                    GPIOPadConfigSet(PORT_D, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
                }else{/* Nothing */}


                break;

            case PORT_E:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_E, _pin->pin);
                    GPIOPinWrite(PORT_E, _pin->pin , 0);
                    GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_E, _pin->pin);
                    GPIOPadConfigSet(PORT_E, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
                }else{/* Nothing */}


                break;

            case PORT_F:
                SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
                while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
                if( PIN_OUTPUT == _pin->direction){
                    GPIOPinTypeGPIOOutput(PORT_F, _pin->pin);
                   GPIODirModeSet(_pin->port, _pin->pin, GPIO_DIR_MODE_OUT);
                }else if (PIN_INPUT == _pin->direction){
                    GPIOPinTypeGPIOInput(PORT_F, _pin->pin);
                    GPIOPadConfigSet(PORT_F, _pin->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
                }else{/* Nothing */}

                break;
            default:
                break;
        }
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType SysClock_Init(void){
    Std_ReturnType ret = E_NOT_OK;
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5);
    ret = E_OK;
    return ret;
}


Std_ReturnType Pin_Write(pin_t * _pin , state_t state){

    Std_ReturnType ret = E_NOT_OK;

    if(NULL == _pin){
        ret = E_NOT_OK;
    }else{

        switch(state){
        case PIN_HIGH:
            GPIOPinWrite(_pin->port, _pin->pin, _pin->pin);
            break;
        case PIN_LOW:
            GPIOPinWrite(_pin->port, _pin->pin, 0x00);
            break;
        default:
            GPIOPinWrite(_pin->port, _pin->pin, 0x00);
            break;
        }
    }
    return ret;
}

state_t Pin_Read(pin_t * _pin ,  Std_ReturnType * ret){

    Std_ReturnType L_ret = E_NOT_OK;
    uint8_t L_state = 0x00;
    state_t Output = PIN_LOW;
    if(NULL == _pin){
        L_ret = E_NOT_OK;
    }else{

        L_state = GPIOPinRead(_pin->port, _pin->pin );
        Output = (state_t)((L_state >> _pin->pin) & 0x01);
        L_ret = E_OK;
    }

    *ret = L_ret;
    return Output;
}
void Delay_ms(uint32_t Delayms){

    uint32_t Loops = (Delayms * (SysCtlClockGet() / 6 / 1000));

    SysCtlDelay(Loops);
}
