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
#define ePWM_PERIPHERAL         false
#define eCAP_PERIPHERAL         false
#define eQEP_PERIPHERAL         false
#define SD_PERIPHERAL           false
#define ADC_PERIPHERAL          false
#define GPIO_PERIPHERAL         false
#define IXBAR_PERIPHERAL        false
#define OXBAR_PERIPHERAL        false
#define CMPSS_PERIPHERAL        false
#define DAC_PERIPHERAL          false
#define SPIA_PERIPHERAL         false
#define SPIB_PERIPHERAL         false
#define CANA_PERIPHERAL         false
#define CANB_PERIPHERAL         false
#define SCIA_PERIPHERAL         false
#define SCIB_PERIPHERAL         false
#define I2C_PERIPHERAL          false
#define NMI_WD_PERIPHERAL       true
#define PGA_PERIPHERAL          false
#define PWMXBAR_PERIPHERAL      false
#define PMBUS_PERIPHERAL        false
#define FSI_PERIPHERAL          false
#define LIN_PERIPHERAL          false
#define WINDOWEDWD_PERIPHERAL   false
#define HRPWM_PERIPHERAL        false
#define USB_PERIPHERAL          false
#define MCBSP_PERIPHERAL        false
#define UPP_PERIPHERAL          false
#define EMIF_PERIPHERAL         false





#endif /* INCLUDES_SYSTEM_H_ */
