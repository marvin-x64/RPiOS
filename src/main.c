/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#include <string.h>
#include <stdlib.h>

#include "gic-400.h"

#include "rpi-gpio.h"
#include "rpi-armtimer.h"
#include "rpi-systimer.h"
#include "rpi-interrupts.h"

extern void _enable_interrupts(void);

void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
    RPI_SetGpioPinFunction(LED_GPIO, FS_OUTPUT);
    RPI_SetGpioHi(LED_GPIO);

#ifdef RPI4
    gic400_init(0xFF840000UL);
#endif

    RPI_EnableARMTimerInterrupt();

#if defined(RPI4)
    RPI_GetArmTimer()->Load = 0x4000;
#else
    RPI_GetArmTimer()->Load = 0x400;
#endif

    RPI_GetArmTimer()->Control =
        RPI_ARMTIMER_CTRL_23BIT |
        RPI_ARMTIMER_CTRL_ENABLE |
        RPI_ARMTIMER_CTRL_INT_ENABLE |
        RPI_ARMTIMER_CTRL_PRESCALE_256;

    _enable_interrupts();

    while (1)
    {
    }
}