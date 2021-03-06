/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#include <stdint.h>

#include "rpi-armtimer.h"

static rpi_arm_timer_t *rpiArmTimer = (rpi_arm_timer_t *)RPI_ARMTIMER_BASE;

rpi_arm_timer_t *RPI_GetArmTimer(void)
{
    return rpiArmTimer;
}

void RPI_ArmTimerInit(void)
{
}