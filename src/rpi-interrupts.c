/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#include <stdint.h>

#include "rpi-armtimer.h"
#include "rpi-base.h"
#include "rpi-gpio.h"
#include "rpi-interrupts.h"

void __attribute__((interrupt("ABORT"))) reset_vector(void)
{
}

void __attribute__((interrupt("UNDEF"))) undefined_instruction_vector(void)
{
    while (1)
    {
    }
}

void __attribute__((interrupt("SWI"))) software_interrupt_vector(void)
{
    while (1)
    {
    }
}

void __attribute__((interrupt("ABORT"))) prefetch_abort_vector(void)
{
}

void __attribute__((interrupt("ABORT"))) data_abort_vector(void)
{
}

void __attribute__((interrupt("IRQ"))) interrupt_vector(void)
{
    static int lit = 0;

    if (RPI_GetArmTimer()->MaskedIRQ)
    {
        RPI_GetArmTimer()->IRQClear = 1;

        if (lit)
        {
            LED_OFF();
            lit = 0;
        }
        else
        {
            LED_ON();
            lit = 1;
        }
    }
}

void __attribute__((interrupt("FIQ"))) fast_interrupt_vector(void)
{
}