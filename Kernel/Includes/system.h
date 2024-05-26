/*
 * System.h
 *
 *  Created on: 03/04/224
 *  Author: Dr. Carlos Romero Pérez
 *
 *  Este fichero de encabezamiento define etiquetas que utiliza la función Pre_Kernel() para configurar el sistema.
 *
 *  El valor de estas etiquetas debe modificarse para cada aplicación, de acuerdo al HW del producto.
 *
 *  El desarrollador deberá seguir las indicaciones de los comentarios en el fichero. La no observancia
 *  de estos comentarios puede llevar a compilaciones incompatibles con el HW real, o fallos de compilación.
 */

#ifndef INCLUDES_SYSTEM_H_
#define INCLUDES_SYSTEM_H_


#define CLOCKIN_MHZ         10      // Frecuencia del reloj o cristal externo en MHz. Si el valor es 0, se utiliza
                                    // el reloj interno del microprocesador

#define CLOCKSYS_MHZ        100


// Definir si la fuente del reloj de Sistema es externa (true=se usa fuente externa. false=no se usa fuente externa)

#if CLOCKIN_MHZ>0
#define CLOCK_EXTERN        true
#define SOURCE_CLK          1
#else
#define CLOCK_EXTERN
#define SOURCE_CLK          0
#endif // End if CLOCKIN_MZ

// Si se usa fuente externa, definir si es singled ended o dual ended (cristal o resonador) (true= opción seleccionada. false= opción no seleccionada)
#if CLOCK_EXTERN==true
#define SINGLE_ENDED        true
#endif


// Configurar la fuente de 1.2V externa (Poner a SI si se usa DCDC externo para 1.2V y NO en caso contrario.
// IMPORTANTE: Ver datasheet para el dispositivo y nº de pines para poner configuración compatible)
#define DCDC_1200mV_EXTERNO     true

// Configurar si se asigna memoria LSx (x=7 :0) para CLA. La memoria para CLA es consecutiva. Se
// asigna de más alta a más baja (de 7 a 0). Si no se asigna ningún sector de LS a CLA, no se activa la CLA

#define LS7_FOR_CLA             true
#if LS7_FOR_CLA==true
#define  LS6_FOR_CLA            true
#if LS6_FOR_CLA==true
#define LS5_FOR_CLA             true
#if LS5_FOR_CLA==true
#define LS4_FOR_CLA             true
#if LS4_FOR_CLA==true
#define LS3_FOR_CLA             true
#if LS3_FOR_CLA==true
#define LS2_FOR_CLA             true
#if LS2_FOR_CLA==true
#define LS1_FOR_CLA             true
#if LS1_FOR_CLA==true
#define LS0_FOR_CLA             true
#else
// NO MODIFICAR LAS DEFINICIONES FALSE DE ASIGNACIÓN DE LSX SIGUIENTES
#define LS0_FOR_CLA             false
#endif //End if LS1_FOR_CLA
#else
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS2_FOR_CLA
#else
#define LS2_FOR_CLA             false
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS3_FOR_CLA
#else
#define LS3_FOR_CLA             false
#define LS2_FOR_CLA             false
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS4_FOR_CLA
#else
#define LS4_FOR_CLA             false
#define LS3_FOR_CLA             false
#define LS2_FOR_CLA             false
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS5_FOR_CLA
#else
#define LS5_FOR_CLA             false
#define LS4_FOR_CLA             false
#define LS3_FOR_CLA             false
#define LS2_FOR_CLA             false
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS6_FOR_CLA
#else
#define LS6_FOR_CLA             false
#define LS5_FOR_CLA             false
#define LS4_FOR_CLA             false
#define LS3_FOR_CLA             false
#define LS2_FOR_CLA             false
#define LS1_FOR_CLA             false
#define LS0_FOR_CLA             false
#endif // End if LS7_FOR_CLA

#define LS_CONFIG               (LS7_FOR_CLA<<14)|(LS6_FOR_CLA<<12)|(LS5_FOR_CLA<<10)|(LS4_FOR_CLA<<8)|(LS3_FOR_CLA<<6)|(LS2_FOR_CLA<<4)|(LS1_FOR_CLA<<2)|LS0_FOR_CLA


//___________________________________________________________

// CONFIGURAR USO DE MEMORIA LSx DE CLA PARA PROGRAMA O DATO. ASIGNACIÓN CONSECUTIVA PARA EL MISMO USO.
// MEMORIA BAJA PARA PROGRAMA Y ALTA PARA DATOS


#define LS0_IS_PROGRAM          true
#if LS0_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS1_IS_PROGRAM          false
#define LS2_IS_PROGRAM          false
#define LS3_IS_PROGRAM          false
#define LS4_IS_PROGRAM          false
#define LS5_IS_PROGRAM          false
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS1_IS_PROGRAM          true
#if LS1_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS2_IS_PROGRAM          false
#define LS3_IS_PROGRAM          false
#define LS4_IS_PROGRAM          false
#define LS5_IS_PROGRAM          false
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS2_IS_PROGRAM          true
#if LS2_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS3_IS_PROGRAM          false
#define LS4_IS_PROGRAM          false
#define LS5_IS_PROGRAM          false
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS3_IS_PROGRAM          true
#if LS3_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS4_IS_PROGRAM          false
#define LS5_IS_PROGRAM          false
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS4_IS_PROGRAM          true
#if LS4_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS5_IS_PROGRAM          false
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS5_IS_PROGRAM          true
#if LS5_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS6_IS_PROGRAM          false
#define LS7_IS_PROGRAM          false
#else
//____________________________________
#define LS6_IS_PROGRAM          true
#if LS6_IS_PROGRAM==false
// NO MODIFICAR LOS SIGUIENTES FALSE
#define LS7_IS_PROGRAM          false
#else
//_____________________________________
#define LS7_IS_PROGRAM          true
#endif // End if LS6_IS_PROGRAM
#endif // End if LS5_IS_PROGRAM
#endif // End if LS4_IS_PROGRAM
#endif // End if LS3_IS_PROGRAM
#endif // End if LS2_IS_PROGRAM
#endif // End if LS1_IS_PROGRAM
#endif // End if LS0_IS_PROGRAM

#define LS_IS_PROGRAM       (LS7_IS_PROGRAM<<7)|(LS6_IS_PROGRAM<<6)|(LS5_IS_PROGRAM<<5)|(LS4_IS_PROGRAM<<4)|(LS3_IS_PROGRAM<<3)|(LS2_IS_PROGRAM<<2)|(LS1_IS_PROGRAM<<1)|LS0_IS_PROGRAM
//_______________________________________________________________________________
// CONFIGURA EL BLOQUEO DE ESCRITURA EN LSx PARA CPU Y BLOQUEO DE USO COMO PROGRAMA PARA CPU
#if LS7_IS_PROGRAM==false
#define LS7_PROGCPU_BLOCKED true
#if LS7_PROGCPU_BLOCKED==true
#define LS7_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS7_WCPU_BLOCKED    true
#endif // End LS7_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS7_WCPU_BLOCKED    true
#define LS7_PROGCPU_BLOCKED true
#endif // End LS7_IS_PROGAM

#if LS6_IS_PROGRAM==false
#define LS6_PROGCPU_BLOCKED true
#if LS6_PROGCPU_BLOCKED==true
#define LS6_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS6_WCPU_BLOCKED    true
#endif // End LS6_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS6_WCPU_BLOCKED    true
#define LS6_PROGCPU_BLOCKED true
#endif // End LS6_IS_PROGAM

#if LS5_IS_PROGRAM==false
#define LS5_PROGCPU_BLOCKED true
#if LS5_PROGCPU_BLOCKED==true
#define LS5_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS5_WCPU_BLOCKED    true
#endif // End LS5_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS5_WCPU_BLOCKED    true
#define LS5_PROGCPU_BLOCKED true
#endif // End LS5_IS_PROGRAM

#if LS4_IS_PROGRAM==false
#define LS4_PROGCPU_BLOCKED true
#if LS4_PROGCPU_BLOCKED==true
#define LS4_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS4_WCPU_BLOCKED    true
#endif // End LS4_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS4_WCPU_BLOCKED    true
#define LS4_PROGCPU_BLOCKED true
#endif // End LS4_IS_PROGRAM

#if LS3_IS_PROGRAM==false
#define LS3_PROGCPU_BLOCKED true
#if LS3_PROGCPU_BLOCKED==true
#define LS3_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS3_WCPU_BLOCKED    true
#endif // End LS3_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS3_WCPU_BLOCKED    true
#define LS3_PROGCPU_BLOCKED true
#endif // End LS3_IS_PROGRAM

#if LS2_IS_PROGRAM==false
#define LS2_PROGCPU_BLOCKED true
#if LS2_PROGCPU_BLOCKED==true
#define LS2_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS2_WCPU_BLOCKED    true
#endif // End LS2_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS2_WCPU_BLOCKED    true
#define LS2_PROGCPU_BLOCKED true
#endif // End LS2_IS_PROGRAM

#if LS1_IS_PROGRAM==false
#define LS1_PROGCPU_BLOCKED true
#if LS1_PROGCPU_BLOCKED==true
#define LS1_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS1_WCPU_BLOCKED    true
#endif // End LS1_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS1_WCPU_BLOCKED    true
#define LS1_PROGCPU_BLOCKED true
#endif // End LS1_IS_PROGRAM

#if LS0_IS_PROGRAM==false
#define LS0_PROGCPU_BLOCKED true
#if LS0_PROGCPU_BLOCKED==true
#define LS0_WCPU_BLOCKED    false
#else
// NO MODIFICAR LA SIGUIENTE LINEA
#define LS0_WCPU_BLOCKED    true
#endif // End LS0_PROGCPU_BLOCKED
#else
// NO MODIFICAR LAS SIGUIENTES LINEAS
#define LS0_WCPU_BLOCKED    true
#define LS0_PROGCPU_BLOCKED true
#endif // End LS0_IS_PROGRAM

#define LSXACCPROT0_H    ((LS3_WCPU_BLOCKED<<1|LS3_PROGCPU_BLOCKED)<<8)|((LS2_WCPU_BLOCKED<<1|LS2_PROGCPU_BLOCKED))
#define LSXACCPROT0_L    ((LS1_WCPU_BLOCKED<<1|LS1_PROGCPU_BLOCKED)<<8)|((LS0_WCPU_BLOCKED<<1|LS0_PROGCPU_BLOCKED))
#define LSXACCPROT1_H    ((LS7_WCPU_BLOCKED<<1|LS7_PROGCPU_BLOCKED)<<8)|((LS6_WCPU_BLOCKED<<1|LS6_PROGCPU_BLOCKED))
#define LSXACCPROT1_L    ((LS5_WCPU_BLOCKED<<1|LS5_PROGCPU_BLOCKED)<<8)|((LS4_WCPU_BLOCKED<<1|LS4_PROGCPU_BLOCKED))

#define LS_RAM_ON           0x000F

//______________________________________________________________________________


// Seleccionar periféricos que se que usa la aplicación (true: Se usa false: no se usa)
#define EPWM1_PERIPHERAL        false
#define EPWM2_PERIPHERAL        false
#define EPWM3_PERIPHERAL        false
#define EPWM4_PERIPHERAL        false
#define EPWM5_PERIPHERAL        false
#define EPWM6_PERIPHERAL        false
#define EPWM7_PERIPHERAL        false
#define EPWM8_PERIPHERAL        false
#define ECAP1_PERIPHERAL        false
#define ECAP2_PERIPHERAL        false
#define ECAP3_PERIPHERAL        false
#define ECAP4_PERIPHERAL        false
#define ECAP5_PERIPHERAL        false
#define ECAP6_PERIPHERAL        false
#define ECAP7_PERIPHERAL        false
#define EQEP1_PERIPHERAL        false
#define EQEP2_PERIPHERAL        false
#define SD_PERIPHERAL           false
#define CMPSS1_PERIPHERAL       false
#define CMPSS2_PERIPHERAL       false
#define CMPSS3_PERIPHERAL       false
#define CMPSS4_PERIPHERAL       false
#define CMPSS5_PERIPHERAL       false
#define CMPSS6_PERIPHERAL       false
#define CMPSS7_PERIPHERAL       false
#define DACA_PERIPHERAL         false
#define DACB_PERIPHERAL         false
#define PGA1_PERIPHERAL         false
#define PGA2_PERIPHERAL         false
#define PGA3_PERIPHERAL         false
#define PGA4_PERIPHERAL         false
#define PGA5_PERIPHERAL         false
#define PGA6_PERIPHERAL         false
#define PGA7_PERIPHERAL         false
#define CLB1_PERIPHERAL         false
#define CLB2_PERIPHERAL         false
#define CLB3_PERIPHERAL         false
#define CLB4_PERIPHERAL         false
#define GPIO_PERIPHERAL         true
#define IXBAR_PERIPHERAL        false
#define OXBAR_PERIPHERAL        false
#define PWMXBAR_PERIPHERAL      false
#define PMBUS_PERIPHERAL        false
#define SPIA_PERIPHERAL         false
#define SPIB_PERIPHERAL         false
#define FSITX_PERIPHERAL        false
#define FSIRX_PERIPHERAL        false
#define CANA_PERIPHERAL         false
#define CANB_PERIPHERAL         false
#define ADCA_PERIPHERAL         true
#define ADCB_PERIPHERAL         true
#define ADCC_PERIPHERAL         true
#define LIN_PERIPHERAL          false
#define SCIA_PERIPHERAL         false
#define SCIB_PERIPHERAL         false
#define I2C_PERIPHERAL          false
#define NMI_WD_PERIPHERAL       true
#define WINDOWEDWD_PERIPHERAL   false
#define DCC_PERIPHERAL          false


// Seleccionar uso de TIMER0 y TIMER1 (TIMER2 está habilitado de forma forzosa. No es opcional. false= No se usa. true=Sí
#define TIMER0_PERIPHERAL       false
#define TIMER1_PERIPHERAL       false

// Configurar si las PWMs usan la misma base de tiempo o no
#define EPWM_PERIPHERAL         (EPWM1_PERIPHERAL|EPWM2_PERIPHERAL|EPWM3_PERIPHERAL|EPWM4_PERIPHERAL|EPWM5_PERIPHERAL|EPWM6_PERIPHERAL|EPWM7_PERIPHERAL|EPWM8_PERIPHERAL)

#if (EPWM_PERIPHERAL==true)
#define EPWM_SAME_BASETIME      true
#else
//NO MODIFICAR SIGUIENTE LÍNEA
#define EPWM_SAME_BASETIME      false
#endif // EPWM_PERIPHERAL

// Definición de la funcionalidad del pinout. Indicar true a GPIO usada. false las que no
#if EPWM1_PERIPHERAL==true
#define GPIO0_IS_PWM1           true
#define GPIO1_IS_PWM1           true
#endif

#if EPWM2_PERIPHERAL==true
#define GPIO2_IS_PWM2           true
#define GPIO3_IS_PWM2           true
#endif

#if EPWM3_PERIPHERAL==true
#define GPIO4_IS_PWM3           true
#define GPIO5_IS_PWM3           true
#endif

#if EPWM4_PERIPHERAL==true
#define GPIO6_IS_PWM4           true
#define GPIO7_IS_PWM4           true
#endif

#if EPWM5_PERIPHERAL==true
#define GPIO8_IS_PWM5           true
#define GPIO9_IS_PWM5           true
#endif

#if EPWM6_PERIPHERAL==true
#define GPIO10_IS_PWM6           true
#define GPIO11_IS_PWM6           true
#if GPIO10_IS_PWM6==true
#define GPIO18_IS_PWM6          false
#else
#define GPIO18_IS_PWM6          true
#endif //GPIO10_IS_PWM6
#endif

#if EPWM7_PERIPHERAL==true
#define GPIO12_IS_PWM7           true
#define GPIO13_IS_PWM7           true
#if GPIO12_IS_PWM7==true
#define GPIO28_IS_PWM7          false
#else
#define GPIO28_IS_PWM7          true
#endif //GPIO12_IS_PWM7
#if GPIO13_IS_PWM7==true
#define GPIO29_IS_PWM7          false
#else
#define GPIO29_IS_PWM7          true
#endif //GPIO13_IS_PWM7
#endif

#if EPWM8_PERIPHERAL==true
#define GPIO14_IS_PWM8           true
#define GPIO15_IS_PWM8           true
#if GPIO14_IS_PWM8==true
#define GPIO24_IS_PWM8          false
#else
#define GPIO24_IS_PWM8          true
#endif //GPIO14_IS_PWM8
#if GPIO15_IS_PWM8==true
#define GPIO32_IS_PWM8          false
#else
#define GPIO32_IS_PWM8          true
#endif //GPIO15_IS_PWM8
#endif


#if EQEP1_PERIPHERAL==true
// SELECCIONAR (TRUE) LAS GPIOS USADAS PARA EQEP1
// EQEP1A
#define GPIO6_IS_EQEP           false
#define GPIO10_IS_EQEP          false
#define GPIO28_IS_EQEP          false
#define GPIO35_IS_EQEP          false
#define GPIO40_IS_EQEP          false
#define GPIO56_IS_EQEP          false
// EQEP1B
#define GPIO7_IS_EQEP           false
#define GPIO11_IS_EQEP          false
#define GPIO29_IS_EQEP          false
#define GPIO37_IS_EQEP          false
#define GPIO57_IS_EQEP          false
// EQEP1_STROBE
#define GPIO8_IS_EQEP           false
#define GPIO12_IS_EQEP          false
#define GPIO16_IS_EQEP          false
#define GPIO22_IS_EQEP          false
#define GPIO30_IS_EQEP          false
#define GPIO58_IS_EQEP          false
// EQEP1_INDEX
#define GPIO9_IS_EQEP           false
#define GPIO13_IS_EQEP          false
#define GPIO17_IS_EQEP          false
#define GPIO31_IS_EQEP          false
#define GPIO59_IS_EQEP          false
#endif

#if EQEP2_PERIPHERAL==true
// SELECCIONAR (TRUE) LAS GPIOS USADAS PARA EQEP2
// EQEP2A
#define GPIO14_IS_EQEP          false
#define GPIO18_IS_EQEP          false
#define GPIO24_IS_EQEP          false
// EQEP2B
#define GPIO15_IS_EQEP          false
#define GPIO25_IS_EQEP          false
// EQEP2_STROBE
#define GPIO27_IS_EQEP          false
#define GPIO28_IS_EQEP          false
#define GPIO56_IS_EQEP          false
// EQEP2_INDEX
#define GPIO26_IS_EQEP          false
#define GPIO29_IS_EQEP          false
#define GPIO57_IS_EQEP          false
#endif

#if SD_PERIPHERAL==true
//SELECCIONAR (TRUE) EL PIN USADO
//SD1_D1
#define GPIO16_IS_SD            false
#define GPIO24_IS_SD            false
//SD1_D2
#define GPIO18_IS_SD            false
#define GPIO26_IS_SD            false
//SD1_D3
#define GPIO28_IS_SD            false
#define GPIO32_IS_SD            false
//SD1_D4
#define GPIO22_IS_SD            false
#define GPIO30_IS_SD            false
#define GPIO58_IS_SD            false
//SD1_C1
#define GPIO17_IS_SD            false
#define GPIO25_IS_SD            false
//SD1_C2
#define GPIO27_IS_SD            false
//SD1_C3
#define GPIO29_IS_SD            false
#define GPIO33_IS_SD            false
#define GPIO57_IS_SD            false
//SD1_C4
#define GPIO31_IS_SD            false
#define GPIO59_IS_SD            false
#endif

#define CLB1_PERIPHERAL         false
#define CLB2_PERIPHERAL         false
#define CLB3_PERIPHERAL         false
#define CLB4_PERIPHERAL         false
#define GPIO_PERIPHERAL         true
#define IXBAR_PERIPHERAL        false
#define OXBAR_PERIPHERAL        false
#define PWMXBAR_PERIPHERAL      false
#define PMBUS_PERIPHERAL        false
#define SPIA_PERIPHERAL         false
#define SPIB_PERIPHERAL         false
#define FSITX_PERIPHERAL        false
#define FSIRX_PERIPHERAL        false
#define CANA_PERIPHERAL         false
#define CANB_PERIPHERAL         false
#define ADCA_PERIPHERAL         true
#define ADCB_PERIPHERAL         true
#define ADCC_PERIPHERAL         true
#define LIN_PERIPHERAL          false
#define SCIA_PERIPHERAL         false
#define SCIB_PERIPHERAL         false
#define I2C_PERIPHERAL          false
#define NMI_WD_PERIPHERAL       true
#define WINDOWEDWD_PERIPHERAL   false
#define DCC_PERIPHERAL          false

#endif /* INCLUDES_SYSTEM_H_ */
