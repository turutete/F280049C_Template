/** \page   page_diagnosys   Diagnosys
 *
 *  \version    1.0.0.0
 *
 *  Atributos:
 *  ---------
 *
 *  * num_events
 *
 *  Métodos públicos
 *  ----------------
 *
 * * Write_Event()
 * * Reset_System_Log()
 *
 * Métodos y atributos privados
 * ----------------------------
 *
 * Init_System_Log()
 *
 * Formato de datos del log
 * ------------------------
 *
 * El log del sistema es una tabla de tamaño ***SIZE_SYSTEM_LOG*** de objetos *EVENTOS*:
 *
 * * Marca de tiempo:   hora:min:sec:msec desde el último reset
 *
 * * Código del evento: (enumerado. POWERON=0)
 *  * POWER_ON
 *  * WATCHDOG_RESET
 *  * NMI_RESET
 *
 *  Los eventos que ocurran desde el reset hasta que se inicie el reloj del sistema se marcarán todos con marca de tiempo
 *  hora=0, min=0, sec=0 y msec=0.
 *
 *  El log del sistema es un buffer circular. De esta forma, cuando el número de eventos almacenados supera el tamaño del
 *  buffer, los eventos más antiguos se pierden.
 *
 *  Historial de Cambios
 *  --------------------
 *  | Fecha | Autores | Versión | Descripción |
 *  |:--: |:--:|:--:|:--:|
 *  | 13/11/2022| Dr. Carlos Romero |1.0.0.0|Primera edición|
 *
 *  ToDos
 *  -----
 *
 *  \todo   Lista de características futuras
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
 */


#include <kernel_types.h>
#include <diagnosys.h>
#include <realtime.h>


// Definición de atributos privados

#pragma DATA_SECTION    (system_log,".kernelvar")
#pragma DATA_SECTION    (index_oldest,".kernelvar")
#pragma DATA_SECTION    (index_newest,".kernelvar")
#pragma DATA_SECTION    (Diagnosys,".kernelvar")


typedef struct
{
    TIME_STAMPING tiempo;
    enum SYSTEM_LOG_EVENTS evento;
} EVENT;

EVENT system_log[SIZE_SYSTEM_LOG];

uint16 index_oldest;
uint16 index_newest;


// Definición de la clase Diagnosys
clase_diagnosys Diagnosys;

// Métodos privados
void Init_System_Log(void);
void Write_Event(enum SYSTEM_LOG_EVENTS);
void Reset_System_Log(void);


// Código
void Init_System_Log(void)
{
    Reset_System_Log();
    Diagnosys.Write_Event=&Write_Event;
    Diagnosys.Reset_System_Log=&Reset_System_Log;
}


void Reset_System_Log(void)
{
    index_oldest=0;
    index_newest=0;
    Diagnosys.num_events=0;
}

void Write_Event(enum SYSTEM_LOG_EVENTS event)
{
    if(Diagnosys.num_events<=SIZE_SYSTEM_LOG)
        Diagnosys.num_events++;

    RealTime.GetClock(&system_log[index_newest].tiempo);
    system_log[index_newest++].evento=event;

    if(index_newest==SIZE_SYSTEM_LOG)
           index_newest=0;

    if(Diagnosys.num_events==SIZE_SYSTEM_LOG+1)
    {
        index_oldest++;
        if(index_oldest==SIZE_SYSTEM_LOG)
                index_oldest=0;
    }


}



