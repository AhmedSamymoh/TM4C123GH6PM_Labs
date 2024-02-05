/*
 * EXTI_pin.c
 *
 *  Created on: Feb 5, 2024
 *      Author: AhmedSamy
 */
#include "EXTI_pin.h"

Std_ReturnType Pin_INT_Config(pin_t *pin){

    Std_ReturnType ret_status = E_NOT_OK;
    uint32_t port_Select =0;
        if(NULL == pin){
                ret_status = E_NOT_OK;
        }
        else
        {
            switch(pin->port){

                case PORT_A:
                   port_Select = INT_GPIOA;
                   break;
                case PORT_B:
                   port_Select = INT_GPIOB;
                   break;
                case PORT_C:
                   port_Select = INT_GPIOC;
                   break;
                case PORT_D:
                   port_Select = INT_GPIOD;
                   break;
                case PORT_E:
                    port_Select = INT_GPIOE;
                    break;
                case PORT_F:
                    port_Select = INT_GPIOF;
                    break;
                default :
                    port_Select = INT_GPIOF;
                    break;
         }


        IntMasterDisable();
        GPIOIntClear(pin->port, pin->pin);
        IntRegister(port_Select, pin->PORT_InterruptHandler);
        GPIOIntTypeSet(pin->port, pin->pin, pin->INT_Type);
        IntPrioritySet(port_Select, pin->INT_priority);
        GPIOIntEnable(pin->port, pin->pin);
        IntEnable(port_Select);
        IntMasterEnable();

            ret_status = E_OK;
        }
        return ret_status;
}

