/*
 * watchdog.h
 *
 *  Created on: 4 may. 2024
 *      Author: Dr. Carlos Romero
 *
 *      Fichero de encabezamiento de controlador del periférico Watchdog
 */

#ifndef KERNEL_INCLUDES_PRIVATED_WATCHDOG_H_
#define KERNEL_INCLUDES_PRIVATED_WATCHDOG_H_

#include    <kernel_types.h>
#include    <system.h>

#define     MAX_WATCHDOG_PERIOD         (Uint16) (262.144/CLOCKIN_MHZ)
#define     MIN_WATCHDOG_PERIOD         10
#define     KMULT                       (Uint32)(CLOCKIN_MHZ*1000)

typedef struct
{
    // Atributos
    Uint16 periodo;

    //Métodos
    void (* Configure_Watchdog)(void);
    void (* Start_Watchdog)(void);
    void (* Stop_Watchdog)(void);
    void (* Calm_Watchdog)(void);

} clase_watchdog;

extern clase_watchdog watchdog;

#endif /* KERNEL_INCLUDES_PRIVATED_WATCHDOG_H_ */
