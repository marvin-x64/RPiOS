/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#ifndef RPI_BASE_H
#define RPI_BASE_H

#include <stdint.h>

// The base address of the GPIO peripheral (ARM Physical Address)
#if defined(RPI0) || defined(RPI1)
    #define PERIPHERAL_BASE 0x20000000UL
#elif defined(RPI2) || defined(RPI3)
    #define PERIPHERAL_BASE 0x3F000000UL
#elif defined(RPI4)
    #define PERIPHERAL_BASE 0xFE000000UL
    #define GIC400_BASE (0xFF840000UL)
#else
    #error Unknown RPI Model!
#endif

#if defined(RPI0) || defined(RPI3)
    #define SYSFREQ 400000000UL
#elif defined(RPI1) || defined(RPI2)
    #define SYSFREQ 250000000UL
#elif defined(RPI4)
    #define SYSFREQ 500000000UL
#else
    #error Unknown RPI Model!
#endif

typedef volatile uint32_t rpi_reg_rw_t;
typedef volatile const uint32_t rpi_reg_ro_t;
typedef volatile uint32_t rpi_reg_wo_t;

typedef volatile uint64_t rpi_wreg_rw_t;
typedef volatile const uint64_t rpi_wreg_ro_t;

#endif