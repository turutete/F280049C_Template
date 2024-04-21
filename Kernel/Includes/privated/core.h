/*
 * core.h
 *
 *  Created on: 12 nov. 2022
 *  Author: Dr. Carlos Romero
 */

#ifndef INCLUDES_PRIVATED_CORE_H_
#define INCLUDES_PRIVATED_CORE_H_

#include    <kernel_types.h>
#include    <system.h>
#include    <diagnosys.h>

#define DCDC_POWERON_TRIALS     5                   // Reintentos de lectura de DCDCSTS.SWSEQDON=1. No hay una especificaci�n
                                                    // concreta en el datasheet. Probablemente deba ser inmediato.
#define DCDC_POWERON_80us       (80*CLOCKIN_MHZ)    //  Valor aproximado para contador de 80us en DCDC poweron

#define TRIAL_10ms              25                  // TRIAL_10ms=Round(10e-3/(1024*4/10e6)). Apróximadamente 10ms con INTOSC2=10e6 Hz


#define LOCK_TRIAL              5

#define TRIAL_INITRAMS          5                   // Número máximo de espera de inicialización de RAM


enum DCDC_1200mV_VALUES
{
    DCDC_EXTERNAL,
    DCDC_INTERNAL,
    LDO_INTERNAL
};
struct  KERNEL_STATUS
{
    uint32 DCDC_1200mV:2;
    uint32 CLA1_VIOLATION:1;
    uint32 DMA_WRITE_VIOLATION:1;
    uint32 RESET_BY_WATCHDOG:1;
    uint32 RESET_BY_UPGRADING:1;
    uint32 UPGRADING_IN_PROGRESS:1;
    uint32 RESERVED:25;
};

typedef struct
{
    //Atributos públicos
    union
    {
        uint32 all;
        struct KERNEL_STATUS bits;

    } kernel_status;

    //Métodos públicos
    void (* Pre_Kernel)(void);        // Método preparatorio de kernel
    void (* Kernel)(void);            // Método público Kernel

} clase_kernel;


typedef struct
{
    uint16 cpu_id;
    uint32 device_id;
}device_info;



extern device_info dispositivo;
extern uint32 * _FlashinitLoadStart;
extern uint32 *_FlashinitRunStart;
extern uint16 _FlashinitLoadSize;

extern uint32 * _CpuinramLoadStart;
extern uint32 * _CpuinramRunStart;
extern uint16 _CpuinramLoadSize;


// Método público para Kernel, pero no accesible a Aplicación
extern void CalmDown_Watchdog(void);
extern void Failure_System_Reboot(void);

#endif

