/*
 * nmi.h
 *
 *  Created on: 3 may. 2024
 *      Author: Dr. Carlos Romero
 */

#ifndef KERNEL_INCLUDES_PRIVATED_NMI_H_
#define KERNEL_INCLUDES_PRIVATED_NMI_H_

#include    "kernel_types.h"

typedef struct
{
    void (* Configure_NMI)(void);
    void (* Force_System_Reset)(void);
} clase_nmi;


// Clase pública
extern clase_nmi Nmi;

#endif /* KERNEL_INCLUDES_PRIVATED_NMI_H_ */
