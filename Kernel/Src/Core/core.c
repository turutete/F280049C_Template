/** \page   page_kernel   Kernel
 *
 *
 *
 *  Kernel es un conjunto de aplicaciones comunes a cualquier aplicación para la familia C2000 de TI, que ofrecen
 *  métodos y servicios que facilitan la implementación de cualquier aplicación de tiempo real.
 *
 *  Está compuesto por los siguientes módulos:
 *
 *  -\subpage    page_config
 *  -\subpage    page_core
 *  -\subpage    page_realtime
 *  -\subpage    page_scheduler
 *  -\subpage    page_threads
 *  -\subpage    page_hal
 *  -\subpage    page_boot
 *  -\subpage    page_diagnosys
 *  -\subpage    page_upgrader
 *  -\subpage    page_services
 *
 *  En particular, este Kernel ofrece los siguientes servicios:
 *
 *  * Configuración del microprocesador (Flash, Memorias, Periféricos, Relojes)
 *  * Implementa la capa HAL (Hardware Abstraction Level), suministrando métodos para la utilización de los recursos HW
 *      del microcontrolador (periféricos).
 *  * Implementa diferentes tipos de hilos (threads), y mecanismos de sincronización entre hilos.
 *  * Implementa un planificador de tareas que puede configurarse para ser o no preemtivo.
 *  * Implementa un mecanismo de actualización de SW
 *  * Implementa un mecanismo de diagnóstico, para permitir la identificación de problemas en ejecución.
 *  * Implementa diversos servicios que pueden ser utilizados por la aplicación:
 *  > * Protocolos de comunicación
 *  > * Cálculo matemático
 *  > * Procesado de señales
 *
 *  Aplicaciones con Kernel
 *  -----------------------
 *  El proyecto *_Project_Template_* es una plantilla para crear aplicaciones empotradas para la famlia C28X
 *  de Texas Instruments. De esta manera, para crear un nuevo proyecto, basta:
 *
 *  1. Clonar la versión más actualizada del proyecto *_F280049C_Template_* del repositorio oficial en el Workspace de nuestro
 *  ordenador.
 *  2. Configurar en ***system.h*** las definiciones que se ajusten al HW real en el que se ejecutará la aplicación
 *  3. Desarrollar la aplicación dentro de la carpeta  ***Application***, de acuerdo con las reglas de
 *  desarrollo de código de UTI-SW.
 *
 *  \image  html    arquitectura_proyecto.jpg
 *  \image  latex   arquitectura_proyecto.jpg
 *
 *  El usuario sólo debe modificar el contenido del fichero ***system.h***. No debe modificar ningún otro
 *  fichero de **Kernel**.
 *
 *  En la carpeta ***Application/Src*** se ecuentra el fichero *main.c*, que lo suministra también la
 *  plantilla. En este fichero se encuentra la función main(), que incluye 2 llamadas a
 *  métodos públicos del Kernel, *_kernel.Pre_kernel()_* y *_kernel.Kernel()_*. Estas 2 llamadas deben
 *  conservarse, y en el misma posición donde están, es decir, lo primero que debe efectuarse tras un power up
 *  de la aplicación es una llamada a kernel.Prekernel(), y la última línea de main() debe ser
 *  la llamada a kernel.Kernel().
 *
 *  Entre ambas llamadas, el usuario deberá incluir las llamadas a métodos públicos de creación de
 *  tareas que necesite la aplicación, así como los mecanismos de sincronización entre tareas.
 *
 *  Tareas
 *  ======
 *  El diseño de aplicaciones con kernel debe efectuarse mediante el uso de ***Tareas***, prioridades
 *  y mecanismos de sincronización, suministrados y gestionados por el Kernel.
 *
 *  Tipos de Tareas
 *  ---------------
 *
 *  *HWI*: Interrupciones HW. Son las rutinas de servicio de interrupción que ofrece la familia de
 *  microcontroladores C28X. Todas estas rutinas son parte de la capa ***HAL*** del kernel. Estas tareas
 *  se lanzan mediante el mecanismo de interrupciones asíncronas del procesador. Cada una de estas rutinas
 *  de interrupción tienen asociados **semáforos**, que permiten sincronizar su ejecución con la activación
 *  de tareas de la aplicación.
 *
 *  *SWI*:  Interrupciones SW. Son rutinas de interrupción utilizadas por el Kernel para sincronizar
 *  tareas internas del kernel.
 *
 *  *PRD*:   Tareas periódicas. Son tareas de la aplicación, que se ejecutan periódicamente.
 *
 *  *TSK*: Son tareas de la aplicación, que se activan mediente mecanismos de sincronización con
 *  procesos o tareas del kernel, o bien con otras tareas de la aplicación.
 *
 *  Sincronismo entre Tareas
 *  ------------------------
 *  El Kernel ofrece los siguientes mecanismos de sincronización entre tareas.
 *
 *  *Semáforos*: Este mecanismo permite a cualquier tarea, de la aplicación o del kernel, crear un objeto
 *  semáforo, y permite que otra tarea se suscriba a este semáforo. El semáforo tiene un estado que puede
 *  ser *ON* o *OFF*. El estado *ON* sólo lo puede poner la tarea que crea el semáforo. El estado
 *  es *OFF* tras crear el semáforo, o bien tras ejecutarse la tarea suscrita.
 *
 *  El mecanismo de semáforos permite gestionar a un mismo semáforo diveras suscripciones. El máximo
 *  número de suscriptores viene descrito por la constante ***MAX_NUMERO_SUSCRIPTORES_SEMAFORO***, en el
 *  fichero  *semaphores.h*.
 *
 *  Mutex
 *  ------
 *  Este mecanismo suspende la ejecución de una tarea el tiempo (en ms) indicado. Es decir, cuando en una tarea
 *  se activa un mecanismo de mutex, la tarea deja de ejecutarse hasta pasado el tiempo indicado.
 *
 *  \page       page_core   Core
 *
 *
 *  CORE es un componente del Kernel, que realiza la inicialización del sistema tras un power-up o reset
 *  e imlementa la máquina de estados del funcionamiento del Kernel.
 *
 *  Implementa 2 métodos públicos, que **deben ser ejecutados en la función main()**:
 *
 *  * Pre_Kernel()
 *  * Kernel()
 *
 *  De esta forma, en la función ***main()*** la primera instrucción que se realiza es una llamada a ***Pre_Kernel()***,
 *  y la última instrucción que se efectúa es una llamada a ***Kernel()***.
 *
 *  Son 2 métodos sin parámetros de llamada, ni tampoco retornan ningún valor. En el caso de producirse alguna excepción
 *  durante su ejecución, dichas excepciones se reflejarán en la variable de estado del Kernel, ***kernel.kernel_status***,
 *  así como en el logger del sistema.
 *
 *  Pre_Kernel()
 *  ------------
 *
 *  Este método supervisa el estado del microcontrolador e inicializa el sistema:
 *
 *  1. Resetea el Log del sistema
 *  2. Comprueba si el sistema está configurado para usar DCDC de 1.2V externo o interno
 *  3. Si es DCDC interno, activa el DCDC, y si no es posible arrancarlo, deja el LDO
 *  4. Comprueba el estado del microcontrolador
 *  5. Comprueba cuál fue el motivo del power on y lo anota en el log del sistema
 *  6. Inicializa la Flash
 *  7. Inicializa relojes del sistema
 *  8. Configura las distintas RAMs
 *  9. Copia en RAM el código definido en Flash para ser ejecutado en RAM
 *  10. Inicializa periféricos
 *  11. Configura el Watchdog
 *  12. Crea la tabla de vectores de interrupción
 *  12. Inicializa la clase Kernel
 *
 *  En caso de que al comprobar el estado del microcontrolador identificara un fallo catastrófico, aborta el arranque
 *  y ejecuta el procedimiento de *Fallo en el arranque*
 *
 *  Kernel()
 *  --------
 *
 *  (Pendiente de explicar)
 *
 *
 *  Historial de Cambios
 *  --------------------
 *  | Fecha | Autores | Versión | Descripción |
 *  |:--: |:--:|:--:|:--:|
 *  | 10/12/2022| Dr. Carlos Romero |1.0.0.0|Primera edición|
 *
 *  ToDos
 *  -----
 *
 *  \todo   Create_Vector_Table
 *  \todo   Init_Kernel_Object
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


#include <core.h>
#include <nmi.h>
#include <watchdog.h>

// Definiciones locales
#define CPU1_ID     1

//  Establecimiento de variables en la sección .kernelvar reservada para el kernel en RAMM1
#pragma DATA_SECTION(kernel,".kernelvar")

// Establecimiento de métodos en la sección .flashinit del kernel
#pragma CODE_SECTION(Configure_Flash,".flashinit")

// Definición de atributos públicos y privados
clase_kernel kernel;
device_info dispositivo;

// Declaración de métodos públicos
void Pre_Kernel(void);
void Kernel(void);

// Declaración de métodos privados
void Power_On(void);
int16 Check_Processor(void);
void Check_Reset_Cause(void);
void Init_Flash(void);
void Configure_Flash(void);
void Configure_Clocks(void);
void Configure_RAM(void);
void Copy_FastApp_to_RAM(void);
void Copy_Flash_to_RAM(Uint32 *,Uint32 *,Uint16);
void Init_Peripherals(void);
void Create_Vector_Table(void);
void Init_Kernel_Object(int16);
void Failure_System_Reboot(void);


// Métodos de core.c
void Pre_Kernel(void)
{
    int16 estado;

    Diagnosys.Init_System_Log();

    Nmi.Configure_NMI();

    Power_On();

    estado=Check_Processor();

    if(estado!=ERROR)
    {
        Check_Reset_Cause();
        Init_Flash();

        Configure_Clocks();
        Configure_RAM();

        Copy_FastApp_to_RAM();
        Init_Peripherals();

        watchdog.Configure_Watchdog();

        Create_Vector_Table();
        Init_Kernel_Object(estado);
    }
    else
    {
        Diagnosys.Write_Event(UNEXPECTED_PROCESSOR);
        Failure_System_Reboot();
    }

}


// Métodos Privados

void Kernel(void)
{

}

void Power_On(void)
{
 #if (DCDC_1200mV_EXTERNO==false) //if (1)

    int16 counter;
    int16 flag;
    uint16 value;

    EALLOW;
    AnalogSubsysRegs.DCDCCTL.bit.DCDCEN=ON;
    flag=OFF;
    counter=DCDC_POWERON_TRIALS;
    while (flag==OFF)
    {
        value=AnalogSubsysRegs.DCDCSTS.bit.SWSEQDONE;
        if (value==OK)
            flag=OK;
        else
        {
            counter--;
            if(counter<=0)
            {
                flag=ERROR;
            }
        }
    }

    if(flag==OK)
    {
        value=AnalogSubsysRegs.DCDCSTS.bit.INDDETECT;
        if(value==OFF)
            flag=ERROR;
        else
        {
            counter=DCDC_POWERON_80us;
            while(counter>=0)
                counter--;
        }
    }

    if(flag==OK)
    {
        kernel.kernel_status.bits.DCDC_1200mV=DCDC_INTERNAL;
        Diagnosys.Write_Event(POWER_ON_OK);
    }
    else
    {
        kernel.kernel_status.bits.DCDC_1200mV=LDO_INTERNAL;
        Diagnosys.Write_Event(POWER_ON_KO);
    }

    EDIS;



#else
    kernel.kernel_status.bits.DCDC_1200mV=DCDC_EXTERNAL;
    Diagnosys.Write_Event(POWER_ON_OK);

#endif //If (1)

}

int16 Check_Processor(void)
{
    int16 resultado;

    dispositivo.device_id=DevCfgRegs.PARTIDH.all;
    dispositivo.cpu_id=CPU1_ID;

    if(dispositivo.device_id==0x01FF0500)
       resultado=OK;
    else
        resultado=ERROR;

    return(resultado);
}

void Check_Reset_Cause(void)
{
    if(CpuSysRegs.RESC.bit.POR)
        Diagnosys.Write_Event(POWER_ON_RESET);
    else
    {
        if(CpuSysRegs.RESC.bit.NMIWDRSn)
            Diagnosys.Write_Event(NMI_RESET);
        if(CpuSysRegs.RESC.bit.WDRSn)
            Diagnosys.Write_Event(WATCHDOG_RESET);
        if(CpuSysRegs.RESC.bit.XRSn)
            Diagnosys.Write_Event(EXTERNAL_RESET);
    }

    CpuSysRegs.RESCCLR.all=0x0000010F;

}


void Init_Flash(void)
{

    Copy_Flash_to_RAM(_FlashinitLoadStart,_FlashinitRunStart,_FlashinitLoadSize);
    Configure_Flash();
}

void Configure_Flash(void)
{
    uint16 clk=CLOCKSYS_MHZ;

    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN=0;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN=0;

    if(clk>80)
        Flash0CtrlRegs.FRDCNTL.bit.RWAIT=4;
    else if (clk>60)
        Flash0CtrlRegs.FRDCNTL.bit.RWAIT=3;
    else if (clk>40)
        Flash0CtrlRegs.FRDCNTL.bit.RWAIT=2;
    else if (clk>20)
        Flash0CtrlRegs.FRDCNTL.bit.RWAIT=1;
    else
        Flash0CtrlRegs.FRDCNTL.bit.RWAIT=0;


    Flash0CtrlRegs.FRD_INTF_CTRL.bit.DATA_CACHE_EN=1;
    Flash0CtrlRegs.FRD_INTF_CTRL.bit.PREFETCH_EN=1;

    Flash0CtrlRegs.FBAC.bit.BAGP=0;

    Flash0CtrlRegs.FBFALLBACK.bit.BNKPWR0=3;
    Flash0CtrlRegs.FBFALLBACK.bit.BNKPWR1=3;

}


void Configure_Clocks(void)
{

    Uint16 temporizador;
    Uint16 trial;
    Uint16 pll_timeout=10;
    Uint16 flag_pllon=false;
    float cociente, fraccion;
    Uint16 multint, multfrac;
    Uint16 mult;

    EALLOW;

#if (CLOCK_EXTERN==true) // if (2)
#if (SINGLE_ENDED==false) // if(2.1)
    // External oscilator
    ClkCfgRegs.XTALCR.bit.OSCOFF=0;
    ClkCfgRegs.XTALCR.bit.SE=1;

    for(trial=0;trial<4;trial++)
    {

    ClkCfgRegs.X1CNT.bit.CLR=1;

    while(ClkCfgRegs.X1CNT.bit.X1CNT<1023);
    }

    ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL=SOURCE_CLK;

    if(ClkCfgRegs.MCDCR.bit.MCLKSTS==0)
        flag_pllon=true;

    if(flag_pllon==false)
        Diagnosys.Write_Event(PLL_KO);
    else
        Diagnosys.Write_Event(PLL_OK);
#else
    //External crystal o resonator
    ClkCfgRegs.XTALCR.bit.OSCOFF=0;

    while(flag_pllon==false && pll_timeout>0)
    {
        pll_timeout--;

        temporizador=CLOCKIN_MHZ*1000;     // 1ms

        while((temporizador--)>0);

        for(trial=0;trial<LOCK_TRIAL;trial++)
        {

        ClkCfgRegs.X1CNT.bit.CLR=1;

        while(ClkCfgRegs.X1CNT.bit.X1CNT<1023);
        }

        ClkCfgRegs.CLKSRCCTL1.bit.OSCCLKSRCSEL=SOURCE_CLK;

        if(ClkCfgRegs.MCDCR.bit.MCLKSTS==0)
            flag_pllon=true;
        else
            ClkCfgRegs.MCDCR.bit.MCLKCLR=1;
    }

    if(flag_pllon==false)
        Diagnosys.Write_Event(PLL_KO);
    else
        Diagnosys.Write_Event(PLL_OK);

    // Configuración del PLL
    cociente=(float)(CLOCKSYS_MHZ)/(float)(CLOCKIN_MHZ);
    multint=(Uint16)cociente;
    fraccion=cociente-(float)multint;

    if(fraccion>=0.75)
        multfrac=3;
    else if(fraccion>=0.5)
        multfrac=2;
    else if(fraccion>=0.25)
        multfrac=1;
    else
        multfrac=0;

    mult=(multfrac<<8)+multint;
    ClkCfgRegs.SYSPLLMULT.all=(Uint32)mult;
#endif // if 2.1

#if (CANA_PERIPHERAL==true)
    ClkCfgRegs.CLKSRCCTL2.bit.CANABCLKSEL=SOURCE_CLK;
#endif

#if (CANB_PERIPHERAL==true)
    ClkCfgRegs.CLKSRCCTL2.bit.CANBBCLKSEL=SOURCE_CLK;
#endif


#endif // if(2)


    EDIS;
}


void Configure_RAM(void)
{
    Uint16 flag_initm0m1=false;
    Uint16 flag_initlsx=false;
    Uint16 flag_initgsx=false;
    Uint16 trial;
    Uint32 aux;


    // Inicializa M0 y M1 (RAM de CPU)
    MemCfgRegs.DxINIT.bit.INIT_M0=ON;
    MemCfgRegs.DxINIT.bit.INIT_M1=ON;

    trial=TRIAL_INITRAMS;

    do
    {
        if(flag_initm0m1==false)
            if(MemCfgRegs.DxINITDONE.all==0x0003)
                flag_initm0m1=true;
        trial--;
    } while(flag_initm0m1==false && trial>0);


    // Inicializa LS0 - LS7 (RAM CPU y CLA)
    MemCfgRegs.LSxMSEL.all=LS_CONFIG;
    MemCfgRegs.LSxCLAPGM.all=LS_IS_PROGRAM;

    aux=(Uint32)LSXACCPROT0_H;
    aux<<=16;
    aux|=(Uint32)LSXACCPROT0_L;
    MemCfgRegs.LSxACCPROT0.all=aux;

    aux=(Uint32)LSXACCPROT1_H;
    aux<<=16;
    aux|=(Uint32)LSXACCPROT1_L;
    MemCfgRegs.LSxACCPROT1.all=aux;

    MemCfgRegs.LSxINIT.all=LS_RAM_ON;

    trial=TRIAL_INITRAMS;

    do
    {
        if(flag_initlsx==false)
            if(MemCfgRegs.LSxINITDONE.all==0x000F)
                flag_initlsx=true;
        trial--;
    } while(flag_initlsx==false && trial>0);

    // Inicializa GS0 -- GS3

    MemCfgRegs.GSxINIT.all=0x000F;          // Inicializa todos los bloques de memoria GSx

    trial=TRIAL_INITRAMS;

    do
    {
        if(flag_initgsx==false)
            if(MemCfgRegs.LSxINITDONE.all==0x000F)
                flag_initgsx=true;
        trial--;
    } while(flag_initgsx==false && trial>0);

    // Comprobación de inicialización de memoria RAM
    if(flag_initm0m1==false)
    {
        Diagnosys.Write_Event(M0M1_RAM_KO);
        Failure_System_Reboot();
    }

    if(flag_initlsx==false)
    {
        Diagnosys.Write_Event(LSX_RAM_KO);
        Failure_System_Reboot();
    }

    if(flag_initgsx==false)
    {
        Diagnosys.Write_Event(GSX_RAM_KO);
        Failure_System_Reboot();
    }

}


void Init_Peripherals(void)
{

    Uint32 aux, aux2, aux3;

    EALLOW;

    // Configuración PCLKR0 (HPWM, CLA, TIMER0-2, DMA). TIMER2 y DMA se habilitan sin opción
    if(LS_CONFIG==0)
        aux2=0;
    else
        aux2=1;

    aux=(1<<5)+(TIMER1_PERIPHERAL<<4)+(TIMER0_PERIPHERAL<<3)+(aux2<<2)+1;
    aux3=(EPWM_SAME_BASETIME<<2)+EPWM_PERIPHERAL;
    aux3<<=16;
    CpuSysRegs.PCLKCR0.all=aux+aux3;

    // Configuración PCLKR2 (ePWM1-8)
    aux=(EPWM8_PERIPHERAL<<7)+(EPWM7_PERIPHERAL<<6)+(EPWM6_PERIPHERAL<<5)+(EPWM5_PERIPHERAL<<4)+(EPWM4_PERIPHERAL<<3)+(EPWM3_PERIPHERAL<<2)+(EPWM2_PERIPHERAL<<1)+EPWM1_PERIPHERAL;
    CpuSysRegs.PCLKCR2.all=aux;

    // Configuración PCLKR3 (ECAP1-7)
    aux=(ECAP7_PERIPHERAL<<6)+(ECAP6_PERIPHERAL<<5)+(ECAP5_PERIPHERAL<<4)+(ECAP4_PERIPHERAL<<3)+(ECAP3_PERIPHERAL<<2)+(ECAP2_PERIPHERAL<<1)+ECAP1_PERIPHERAL;
    CpuSysRegs.PCLKCR3.all=aux;

    // Configuración PCKR4  (EQEP1-2)
    aux=(EQEP2_PERIPHERAL<<1)+EQEP1_PERIPHERAL;
    CpuSysRegs.PCLKCR4.all=aux;

    // Configuración PCLKR6 (SD1)
    CpuSysRegs.PCLKCR6.all=SD_PERIPHERAL;

    // Configuración PCLKR7 (SCIA-B)
    aux=(SCIB_PERIPHERAL<<1)+SCIA_PERIPHERAL;
    CpuSysRegs.PCLKCR7.all=aux;

    // Configuración PCLKR8 (SPIA-B)
    aux=(SPIB_PERIPHERAL<<1)+SPIA_PERIPHERAL;
    CpuSysRegs.PCLKCR8.all=aux;

    // Configuración PCLKR9 (I2C)
    CpuSysRegs.PCLKCR9.all=I2C_PERIPHERAL;

    // Configuración PCLKR10 (CANA-B)
    aux=(CANB_PERIPHERAL<<1)+CANA_PERIPHERAL;
    CpuSysRegs.PCLKCR10.all=aux;

    // Configuración PCLKR13 (ADCA-C)
    aux=(ADCC_PERIPHERAL<<2)+(ADCB_PERIPHERAL<<1)+ADCA_PERIPHERAL;
    CpuSysRegs.PCLKCR13.all=aux;

    // Configuración PCLKR14 (CMPSS1-7)
    aux=(CMPSS7_PERIPHERAL<<6)+(CMPSS6_PERIPHERAL<<5)+(CMPSS5_PERIPHERAL<<4)+(CMPSS4_PERIPHERAL<<3)+(CMPSS3_PERIPHERAL<<2)+(CMPSS2_PERIPHERAL<<1)+CMPSS1_PERIPHERAL;
    CpuSysRegs.PCLKCR14.all=aux;

    // Configuración PCLKR15 (PGA1-7)
    aux=(PGA7_PERIPHERAL<<6)+(PGA6_PERIPHERAL<<5)+(PGA5_PERIPHERAL<<4)+(PGA4_PERIPHERAL<<3)+(PGA3_PERIPHERAL<<2)+(PGA2_PERIPHERAL<<1)+PGA1_PERIPHERAL;
    CpuSysRegs.PCLKCR15.all=aux;

    // Configuración PCLKR16 (DACA-B)
    aux=(DACB_PERIPHERAL<<1)+DACA_PERIPHERAL;
    aux<<=16;
    CpuSysRegs.PCLKCR16.all=aux;

    // Configuración PCLKR17 (CLB1-4)
    aux=(CLB4_PERIPHERAL<<3)+(CLB3_PERIPHERAL<<2)+(CLB2_PERIPHERAL<<1)+CLB1_PERIPHERAL;
    CpuSysRegs.PCLKCR17.all=aux;

    // Configuración PCLKR18 (FSI TX-RX)
    aux=(FSIRX_PERIPHERAL<<1)+FSITX_PERIPHERAL;
    CpuSysRegs.PCLKCR18.all=aux;

    // Configuración PCLKR19 (LIN)
    CpuSysRegs.PCLKCR19.all=LIN_PERIPHERAL;


    // Configuración PCLKR20 (PMBUS)
    CpuSysRegs.PCLKCR20.all=PMBUS_PERIPHERAL;


    // Configuración PCLKR21 (DCC)
    CpuSysRegs.PCLKCR21.all=DCC_PERIPHERAL;


    EDIS;

}



void Create_Vector_Table(void)
{
    DINT;
    PieCtrlRegs.PIECTRL.bit.ENPIE=1;
    EALLOW;

    // Configuración de la tabla de vectores de interrupción del PIE
    //PieVectTable.x=&isr_name;


    // Habilitación de los PIEIER.x

    //Habilitación de bits en IER

    // Habilitación de interrupciones en los periféricos


    EINT;

}

void Copy_FastApp_to_RAM(void)
{
    Copy_Flash_to_RAM(_CpuinramLoadStart, _CpuinramRunStart, _FlashinitLoadSize);
}
void Copy_Flash_to_RAM(Uint32 * pcode_read, Uint32 * pcode_write, Uint16 size)
{
    uint16  veces;

    for(veces=0;veces<size;veces++)
        *(pcode_write++)=*(pcode_read++);
}



void Init_Kernel_Object(int16 estado)
{

}


void Failure_System_Reboot(void)
{
    Diagnosys.Write_Event(BOOTING_CRITICAL_ERROR);
    Nmi.Force_System_Reset();
}



