/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#include <string.h>
#include <stdlib.h>

#include "rpi-gpio.h"
#include "rpi-systimer.h"

volatile unsigned int *gpio = (unsigned int *)GPIO_BASE;

void kernel_main(unsigned int r0, unsigned int r1, unsigned int atags)
{
    int brightness = 255;
    int speed = 16;
    int up = 0;

    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

    while (1)
    {
        if (brightness > 0)
        {
            LED_OFF();
            RPI_WaitMicroSeconds(brightness);
        }

        if ((255 - brightness) >= 0)
        {
            LED_ON();
            RPI_WaitMicroSeconds(255 - brightness);
        }

        speed--;
        if (speed == 0)
        {
            speed = 16;

            if (up)
            {
                if (brightness < 255)
                    brightness++;
                if (brightness == 255)
                    up = 0;
            }
            else
            {
                if (brightness)
                    brightness--;
                if (brightness == 0)
                    up = 1;
            }
        }
    }
}