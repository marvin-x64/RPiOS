/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#include <string.h>
#include <stdlib.h>

#include "rpi-gpio.h"

volatile unsigned int *gpio = (unsigned int *)GPIO_BASE;


void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
    int loop;
    unsigned int *counters;

    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

    counters = malloc(1024 * sizeof(unsigned int));
    if (counters == NULL)
        while (1)
            LED_ON();

    for (loop = 0; loop < 1024; loop++)
        counters[loop] = 0;

    while (1)
    {
        LED_ON();
        for (counters[0] = 0; counters[0] < 500000; counters[0]++) ;

        LED_OFF();
        for (counters[1] = 0; counters[1] < 500000; counters[1]++) ;
    }
}