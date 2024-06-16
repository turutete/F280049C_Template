/** \page   page_watchdog   Controlador Watchdog
 *
 *
 *
 *  Este módulo SW implementa el controlador del periferico Watchdog.
 *
 *  En esta versión, el Watchdog funciona provocando un reset. No permite la configuración como interrupcion.
 *
 * El controlador crea la clase Watchdog con los siguientes atributos y métodos:
 *
 * Atributos
 * ---------
 * periodo: (Uint16) Periodo en ms del temporizador del watchdog. Su valor está limitado al rango [10ms 266144/CLOCKIN].
 *
 *  Implementa los métodos:
 *
 *  - Configure_Watchdog
 *  - Start_Watchdog
 *  - Stop_Watchdog
 *  - Calm_Wathdog
 *
 *
 * Configure_Wathdog
 * -----------------
 *
 *  Nmi.Configure_Watchdog() inicializa y configura el periférico Watchdog. El valor que configura al periodo será
 *  el que tenga almacenado el atributo periodo. Por defecto tendrá el valor máximo MAX_WATCHDOG_PERIOD.
 *
 * Start_Wathdog
 * -------------
 *
 * Activa la ejecucion del watchdog.
 *
 * Stop_Watchdog
 * -------------
 *
 * Desactiva la ejecución del Watchdog
 *
 * Calm_Watchdog
 * -------------
 *
 * Este método debe ser usado por la aplicación y/o el Kernel para evitar el reset
 *
 *
 *  Historial de Cambios
 *  --------------------
 *  | Fecha | Autores | Versión | Descripción |
 *  |:--: |:--:|:--:|:--:|
 *  | 04/05/2024| Dr. Carlos Romero |1.0.0.0|Primera edición|
 *
 *  ToDos
 *  -----
 *
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

#include    <watchdog.h>

// Métodos
void ConfiguraWatchdog(void);
void IniciaWatchdog(void);
void ParaWatchdog(void);
void CalmaWatchdog(void);

clase_watchdog watchdog={MAX_WATCHDOG_PERIOD,&ConfiguraWatchdog,&IniciaWatchdog,&ParaWatchdog,&CalmaWatchdog};



void ConfiguraWatchdog(void)
{
    Uint16 aux;
    Uint16 prediv, prescaler;
    int32 errornext, errorprev;
    Uint32 temp32;

    if(watchdog.periodo<MIN_WATCHDOG_PERIOD)
    {
        watchdog.periodo=MIN_WATCHDOG_PERIOD;
        prediv=3;
        prescaler=1;
    }
    else if(watchdog.periodo>MAX_WATCHDOG_PERIOD)
    {
        prediv=3;       // 3-> 1/4096
        prescaler=7;    // 7 > 1/64
    }
    else
    {
        temp32=((Uint32)watchdog.periodo)*KMULT;
        prescaler=7;
        temp32>>=6;
        if(temp32>=4096)
            prediv=3;
        else if (temp32>=2048)
        {
        errornext=(Uint32)4096-temp32;
        errorprev=temp32-(Uint32)2046;
        if(errornext<errorprev)
            prediv=3;
        else
            prediv=2;
        }
        else if(temp32>=1024)
        {
        errornext=(Uint32)2048-temp32;
        errorprev=temp32-(Uint32)1024;
        if(errornext<errorprev)
            prediv=2;
        else
            prediv=1;
        }

    }


    aux=(prediv<<8)+0x0028+prescaler;

    EALLOW;
    // Configura el periodo del Watchdog al máximo posible (INTOSC1/(4096*64)-->26ms si INTOSC1=1MHz)
    WdRegs.WDCR.all=aux;

    EDIS;
}

void IniciaWatchdog(void)
{
    EALLOW;
    WdRegs.WDCR.all|=0x0068;
    EDIS;
}


void ParaWatchdog(void)
{
    Uint16 aux;

    aux=WdRegs.WDWCR.all;
    aux&=0xFFBF;
    aux|=0x0028;

    EALLOW;
    WdRegs.WDCR.all=aux;
    EDIS;
}




void CalmaWatchdog(void)
{
    EALLOW;
    WdRegs.WDKEY.bit.WDKEY = 0x0055;
    WdRegs.WDKEY.bit.WDKEY = 0x00AA;
    EDIS;
}
