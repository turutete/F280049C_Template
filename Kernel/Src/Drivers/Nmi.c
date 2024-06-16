/** \page   page_nmi   NMI
 *
 *
 *
 * Controlador del recurso HW NMI
 *
 *
 * [Explicar con un poco mas de detalle las funcionalidades o servicios que hay en este módulo SW]
 *
 
 *
 *
 *  Historial de Cambios
 *  --------------------
 *  | Fecha | Autores | Versión | Descripción |
 *  |:--: |:--:|:--:|:--:|
 *  | 03/05/2024| Dr. Carlos Romero |1.0.0.0|Primera edición|
 *
 *  ToDos
 *  -----
 *
 *  Bugs Conocidos
 *  --------------
 *
 *  \bug        Sin bugs conocidos
 *
 *  Notas para el Desarrollador
 *  ----------------------------
 *  \warning    Sin notas de alertas para el desarrollador
 *
 *
 *  \copyright  ZIGOR R&D AIE
 *
 */

#include "nmi.h"
#include "diagnosys.h"

// Métodos públicos sólo para Kernel
interrupt void Nmi_Check_Source(void);
void Configure_Nmi(void);
void Nmi_SW(void);

// Definición de la clase Nmi e Inicialización
clase_nmi Nmi={&Configure_Nmi, &Nmi_SW};


void Configure_Nmi(void)
{
    EALLOW;
    PieVectTable.NMI_INT=&Nmi_Check_Source;
    EDIS;
}

interrupt void Nmi_Check_Source(void)
{
    // Se atiende la interrupción, pero no se limpia el bit FLAG en NMIFLGCLR
    // Por lo que al expirar timer del watchdog del NMI, se provoca un reset

    if(NmiIntruptRegs.NMIFLG.bit.SWERR==1)
        Diagnosys.Write_Event(NMI_SW_RESET);

    if(NmiIntruptRegs.NMIFLG.bit.CLBNMI==1)
        Diagnosys.Write_Event(NMI_CLB_RESET);

    if(NmiIntruptRegs.NMIFLG.bit.PIEVECTERR==1)
        Diagnosys.Write_Event(NMI_PIEVECT_RESET);

    if(NmiIntruptRegs.NMIFLG.bit.FLUNCERR==1)
        Diagnosys.Write_Event(NMI_FLASH_RESET);

    if(NmiIntruptRegs.NMIFLG.bit.RAMUNCERR==1)
        Diagnosys.Write_Event(NMI_RAM_RESET);

    if(NmiIntruptRegs.NMIFLG.bit.CLOCKFAIL==1)
        Diagnosys.Write_Event(NMI_CLOCK_RESET);

    //Fuerza el reset del Watchdog del NMI
    EALLOW;
    NmiIntruptRegs.NMIWDPRD=(NmiIntruptRegs.NMIWDCNT-1);
    EDIS;
}

void Nmi_SW(void)
{
    EALLOW;
    NmiIntruptRegs.NMIFLGFRC.bit.SWERR=true;
    EDIS;
}
