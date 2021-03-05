/*
 * Autor: marvin.x64 (Marvin Minato) 
 * Email: marvin.x64@pm.me
*/

#ifndef RPI_BASE_H
#define RPI_BASE_H

#include <stdint.h>

// The base address of the GPIO peripheral (ARM Physical Address)
#if defined (RPI0) || defined (RPI1)
    #define PER_BASE       0x20200000UL
#elif defined (RPI2) || defined (RPI3)
    #define PER_BASE       0x3F200000UL
#elif defined (RPI4)
    #define PER_BASE       0xFE200000UL
#else
    #error Unknown RPI Model!
#endif

typedef volatile uint32_t rpi_reg_rw_t;
typedef volatile const uint32_t rpi_reg_ro_t;
typedef volatile uint64_t rpi_wreg_rw_t;
typedef volatile const uint64_t rpi_wreg_ro_t;

#endif