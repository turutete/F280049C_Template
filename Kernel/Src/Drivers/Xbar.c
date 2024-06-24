/** \page   page_xbar   XBAR Driver
 *
 *
 *
 * Controlador del periférico XBAR.
 *
 * Este controlador permite configurar:
 *
 * - Input XBAR
 * - Output XBAR
 * - ePWM XBAR
 * - CLB XBAR
 *
 * Para ello, el controlador proporciona la clase **xbar** que permite acceder al conjunto de métodos:
 *
 * Set_InputXbar: void xbar.Set_InputXbar(Uint16 xbar_input, Uint16 gpio)
 * ------------
 *
 * \param[out]  void
 * \param[in]   xbar_input  parámetro de entrada Uint16 en el rango 1:16 que indica la entrada del bloque Input-Xbar
 *              que se va asociar a la GPIO dada como parámetro de entrada
 * \param[in]   gpio    Número de GPIO que se conecta a **xbar_input**. Si el valor de GPIO es superior al número de
 *              GPIOs del dispositivo, **xbar_input** tomará el valor '1'. Si el valor de GPIO=0xFFFF, **xbar_input**
 *              valdrá 0
 *
 * Set_PwmMux**K**Xbar  void xbar.Set_PwmMuxkXbar(Uint16 epwmxbar_output,enum MUXk_PWM_XBAR)
 * ---------------
 *
 * \param[out]  void
 * \param[in]   epwmxbar_output Este parámetro es Uint16. Puede tomar los siguientes valores (4, 5, 7,8,9,10,11 y 12),
 *              que son las 8 posibles salidas ePWM-Xbar del dispositivo. Si el valor de entrada no es ninguno de los
 *              mencionados, el cambio no surte efecto
 * \param[in]   selector    este parámetro es un enumerado del tipo MUX**K**_PWM_XBAR, siendo **K** el identificador
 *              del enumerado correspondiente al multiplexor correspondiente al método Set_PwmMux**K**Xbar.
 *
 * El bloque ePMW XBAR está compuesto por 8 salidas que pueden ser conectadas como TRIPS a las ePWM. Estas 8 salidas están
 * numeradas como 4, 5, 7, 8, 9, 10, 11 y 12.
 *
 * Cada una de estas salidas se pueden configurar para que conectarlas a 28 multiplexores (0:23, 25, 27, 29 y 31).
 *
 * Cada uno de estos multiplexores puede seleccionar un máximo de 4 entradas digitales que indican diferentes eventos en
 * diversos periféricos del dispositivo. Cada multiplexor tiene un conjunto específico de digitales de entrada que es capaz
 * de multiplexar __(ver tabla 9.2 del manual de referencia)__.
 *
 * El valor **K** indicado en el nomre del método Set_PwmMux**K**Xbar define el multiplexor que se desea configurar.
 * Una vez especificado este valor de K, el enumerado selector está restringido por código al correspondiente a ese
 * multiplexor.
 *
 * Set_PwmOutInvert void xbar.Set_PwmOutInvert(Uint16 epwxbar_output, bool invert_option)
 * ----------------
 *
 * \param[out]  void
 * \param[in]   epwmxbar_output Parámetro Uint16 que selecciona una de las 8 salidas de trip a las ePWM (4,5,7,8,9,10,11,12)
 * \param[in]   invert_option   Parámetro tipo bool. Si vale true, la salida digital se invierte. Si vale false, no
 *                              se invierte. Si toma un valor diferente, no tiene efecto el cambio.
 *
 *
 * Set_PwmMuxEnabler void xbar.Set_PwmMuxEnabler(Uint16 epwmxbar_output, Uint32 trip_enaber)
 * -----------------
 *
 * \param[out]  void
 * \param[in]   epwmxbar_output Selecciona la salida ePWM XBAR (4,5,7,8,9,10,11,12) que se desea configurar
 * \param[in]   trip_enabler    Es un Uint32 que permite configurar cuáles de los 28 multiplexores de módulo se habilitan
 *              como salida. '1' habilita su uso como salida. '0' deshabilita su uso como salida.
 *
 * Pueden habilitarse tantos multiplexores como se desee. La activacion de cualquiera de los multiplexores habilitados
 * se verá en la salida.
 *
 * La habilitación de los bits, 24, 26, 28 y 30 no surten efecto.
 *
 *
 *  Historial de Cambios
 *  --------------------
 *  | Fecha | Autores | Versión | Descripción |
 *  |:--: |:--:|:--:|:--:|
 *  | 26/05/2024| Dr. Carlos Romero |1.0.0.0|Primera edición|
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

#include "xbar.h"

// Definición de métodos de la clase
void Set_InputXbar(Uint16,Uint16);

void Set_PwmMux0Xbar(Uint16,enum MUX0_PWM_XBAR);
void Set_PwmMux1Xbar(Uint16,enum MUX1_PWM_XBAR);
void Set_PwmMux2Xbar(Uint16,enum MUX2_PWM_XBAR);
void Set_PwmMux3Xbar(Uint16,enum MUX3_PWM_XBAR);
void Set_PwmMux4Xbar(Uint16,enum MUX4_PWM_XBAR);
void Set_PwmMux5Xbar(Uint16,enum MUX5_PWM_XBAR);
void Set_PwmMux6Xbar(Uint16,enum MUX6_PWM_XBAR);
void Set_PwmMux7Xbar(Uint16,enum MUX7_PWM_XBAR);
void Set_PwmMux8Xbar(Uint16,enum MUX8_PWM_XBAR);
void Set_PwmMux9Xbar(Uint16,enum MUX9_PWM_XBAR);
void Set_PwmMux10Xbar(Uint16,enum MUX10_PWM_XBAR);
void Set_PwmMux11Xbar(Uint16,enum MUX11_PWM_XBAR);
void Set_PwmMux12Xbar(Uint16,enum MUX12_PWM_XBAR);
void Set_PwmMux13Xbar(Uint16,enum MUX13_PWM_XBAR);
void Set_PwmMux14Xbar(Uint16,enum MUX14_PWM_XBAR);
void Set_PwmMux15Xbar(Uint16,enum MUX15_PWM_XBAR);
void Set_PwmMux16Xbar(Uint16,enum MUX16_PWM_XBAR);
void Set_PwmMux17Xbar(Uint16,enum MUX17_PWM_XBAR);
void Set_PwmMux18Xbar(Uint16,enum MUX18_PWM_XBAR);
void Set_PwmMux19Xbar(Uint16,enum MUX19_PWM_XBAR);
void Set_PwmMux20Xbar(Uint16,enum MUX20_PWM_XBAR);
void Set_PwmMux21Xbar(Uint16,enum MUX21_PWM_XBAR);
void Set_PwmMux22Xbar(Uint16,enum MUX22_PWM_XBAR);
void Set_PwmMux23Xbar(Uint16,enum MUX23_PWM_XBAR);
void Set_PwmMux25Xbar(Uint16,enum MUX25_PWM_XBAR);
void Set_PwmMux27Xbar(Uint16,enum MUX27_PWM_XBAR);
void Set_PwmMux29Xbar(Uint16,enum MUX29_PWM_XBAR);
void Set_PwmMux31Xbar(Uint16,enum MUX31_PWM_XBAR);
void Set_PwmMuxEnabler(Uint16,Uint32);
void Set_PwmOutInvert(Uint16,bool);

void Set_OutputMux0Xbar(Uint16,enum MUX0_OUTPUT_XBAR);
void Set_OutputMux1Xbar(Uint16,enum MUX1_OUTPUT_XBAR);
void Set_OutputMux2Xbar(Uint16,enum MUX2_OUTPUT_XBAR);
void Set_OutputMux3Xbar(Uint16,enum MUX3_OUTPUT_XBAR);
void Set_OutputMux4Xbar(Uint16,enum MUX4_OUTPUT_XBAR);
void Set_OutputMux5Xbar(Uint16,enum MUX5_OUTPUT_XBAR);
void Set_OutputMux6Xbar(Uint16,enum MUX6_OUTPUT_XBAR);
void Set_OutputMux7Xbar(Uint16,enum MUX7_OUTPUT_XBAR);
void Set_OutputMux8Xbar(Uint16,enum MUX8_OUTPUT_XBAR);
void Set_OutputMux9Xbar(Uint16,enum MUX9_OUTPUT_XBAR);
void Set_OutputMux10Xbar(Uint16,enum MUX10_OUTPUT_XBAR);
void Set_OutputMux11Xbar(Uint16,enum MUX11_OUTPUT_XBAR);
void Set_OutputMux12Xbar(Uint16,enum MUX12_OUTPUT_XBAR);
void Set_OutputMux13Xbar(Uint16,enum MUX13_OUTPUT_XBAR);
void Set_OutputMux14Xbar(Uint16,enum MUX14_OUTPUT_XBAR);
void Set_OutputMux15Xbar(Uint16,enum MUX15_OUTPUT_XBAR);
void Set_OutputMux16Xbar(Uint16,enum MUX16_OUTPUT_XBAR);
void Set_OutputMux17Xbar(Uint16,enum MUX17_OUTPUT_XBAR);
void Set_OutputMux18Xbar(Uint16,enum MUX18_OUTPUT_XBAR);
void Set_OutputMux19Xbar(Uint16,enum MUX19_OUTPUT_XBAR);
void Set_OutputMux20Xbar(Uint16,enum MUX20_OUTPUT_XBAR);
void Set_OutputMux21Xbar(Uint16,enum MUX21_OUTPUT_XBAR);
void Set_OutputMux22Xbar(Uint16,enum MUX22_OUTPUT_XBAR);
void Set_OutputMux23Xbar(Uint16,enum MUX23_OUTPUT_XBAR);
void Set_OutputMuxEnabler(Uint16,Uint32);
void Set_OutputOutInvert(Uint16,bool);


void Set_CLBMux0Xbar(Uint16,enum MUX0_CLB_XBAR);
void Set_CLBMux1Xbar(Uint16,enum MUX1_CLB_XBAR);
void Set_CLBMux2Xbar(Uint16,enum MUX2_CLB_XBAR);
void Set_CLBMux3Xbar(Uint16,enum MUX3_CLB_XBAR);
void Set_CLBMux4Xbar(Uint16,enum MUX4_CLB_XBAR);
void Set_CLBMux5Xbar(Uint16,enum MUX5_CLB_XBAR);
void Set_CLBMux6Xbar(Uint16,enum MUX6_CLB_XBAR);
void Set_CLBMux7Xbar(Uint16,enum MUX7_CLB_XBAR);
void Set_CLBMux8Xbar(Uint16,enum MUX8_CLB_XBAR);
void Set_CLBMux9Xbar(Uint16,enum MUX9_CLB_XBAR);
void Set_CLBMux10Xbar(Uint16,enum MUX10_CLB_XBAR);
void Set_CLBMux11Xbar(Uint16,enum MUX11_CLB_XBAR);
void Set_CLBMux12Xbar(Uint16,enum MUX12_CLB_XBAR);
void Set_CLBMux13Xbar(Uint16,enum MUX13_CLB_XBAR);
void Set_CLBMux14Xbar(Uint16,enum MUX14_CLB_XBAR);
void Set_CLBMux15Xbar(Uint16,enum MUX15_CLB_XBAR);
void Set_CLBMux16Xbar(Uint16,enum MUX16_CLB_XBAR);
void Set_CLBMux17Xbar(Uint16,enum MUX17_CLB_XBAR);
void Set_CLBMux18Xbar(Uint16,enum MUX18_CLB_XBAR);
void Set_CLBMux19Xbar(Uint16,enum MUX19_CLB_XBAR);
void Set_CLBMux20Xbar(Uint16,enum MUX20_CLB_XBAR);
void Set_CLBMux21Xbar(Uint16,enum MUX21_CLB_XBAR);
void Set_CLBMux22Xbar(Uint16,enum MUX22_CLB_XBAR);
void Set_CLBMux23Xbar(Uint16,enum MUX23_CLB_XBAR);
void Set_CLBMuxEnabler(Uint16,Uint32);
void Set_CLBOutInvert(Uint16,bool);



// Construcción de clases
clase_inputxbar inputxbar={&Set_InputXbar};
clase_outputxbar outputxbar={&Set_OutputMux0Xbar,&Set_OutputMux1Xbar,&Set_OutputMux2Xbar,&Set_OutputMux3Xbar,
                             &Set_OutputMux4Xbar,&Set_OutputMux5Xbar,&Set_OutputMux6Xbar,&Set_OutputMux7Xbar,
                             &Set_OutputMux8Xbar,&Set_OutputMux9Xbar,&Set_OutputMux10Xbar,&Set_OutputMux11Xbar,
                             &Set_OutputMux12Xbar,&Set_OutputMux13Xbar,&Set_OutputMux14Xbar,&Set_OutputMux15Xbar,
                             &Set_OutputMux16Xbar,&Set_OutputMux17Xbar,&Set_OutputMux18Xbar,&Set_OutputMux19Xbar,
                             &Set_OutputMux20Xbar,&Set_OutputMux21Xbar,&Set_OutputMux22Xbar,&Set_OutputMux23Xbar,
                             &Set_OutputMuxEnabler, &Set_OutputOutInvert};

clase_pwmxbar pwmxbar={&Set_PwmMux0Xbar,&Set_PwmMux1Xbar,&Set_PwmMux2Xbar,&Set_PwmMux3Xbar,
                       &Set_PwmMux4Xbar,&Set_PwmMux5Xbar,&Set_PwmMux6Xbar,&Set_PwmMux7Xbar,
                       &Set_PwmMux8Xbar,&Set_PwmMux9Xbar,&Set_PwmMux10Xbar,&Set_PwmMux11Xbar,
                       &Set_PwmMux12Xbar,&Set_PwmMux13Xbar,&Set_PwmMux14Xbar,&Set_PwmMux15Xbar,
                       &Set_PwmMux16Xbar,&Set_PwmMux17Xbar,&Set_PwmMux18Xbar,&Set_PwmMux19Xbar,
                       &Set_PwmMux20Xbar,&Set_PwmMux21Xbar,&Set_PwmMux22Xbar,&Set_PwmMux23Xbar,
                       &Set_PwmMux25Xbar,&Set_PwmMux27Xbar,&Set_PwmMux29Xbar,&Set_PwmMux31Xbar,
                       &Set_PwmMuxEnabler,&Set_PwmOutInvert};

clase_clbxbar clbxbar={&Set_CLBMux0Xbar,&Set_CLBMux1Xbar,&Set_CLBMux2Xbar,&Set_CLBMux3Xbar,
                       &Set_CLBMux4Xbar,&Set_CLBMux5Xbar,&Set_CLBMux6Xbar,&Set_CLBMux7Xbar,
                       &Set_CLBMux8Xbar,&Set_CLBMux9Xbar,&Set_CLBMux10Xbar,&Set_CLBMux11Xbar,
                       &Set_CLBMux12Xbar,&Set_CLBMux13Xbar,&Set_CLBMux14Xbar,&Set_CLBMux15Xbar,
                       &Set_CLBMux16Xbar,&Set_CLBMux17Xbar,&Set_CLBMux18Xbar,&Set_CLBMux19Xbar,
                       &Set_CLBMux20Xbar,&Set_CLBMux21Xbar,&Set_CLBMux22Xbar,&Set_CLBMux23Xbar,
                       &Set_CLBMuxEnabler,&Set_CLBOutInvert};

clase_xbar xbar={&inputxbar, &outputxbar, &pwmxbar, &clbxbar};


// Métodos
void Set_InputXbar(Uint16 xbar_input, Uint16 gpio)
{

    if(xbar_input>0 || xbar_input<=16)
    {
        switch(xbar_input)
        {
        case 1:
            InputXbarRegs.INPUT1SELECT=gpio;
            break;
        case 2:
            InputXbarRegs.INPUT2SELECT=gpio;
            break;
        case 3:
            InputXbarRegs.INPUT3SELECT=gpio;
            break;
        case 4:
            InputXbarRegs.INPUT4SELECT=gpio;
            break;
        case 5:
            InputXbarRegs.INPUT5SELECT=gpio;
            break;
        case 6:
            InputXbarRegs.INPUT6SELECT=gpio;
            break;
        case 7:
            InputXbarRegs.INPUT7SELECT=gpio;
            break;
        case 8:
            InputXbarRegs.INPUT8SELECT=gpio;
            break;
        case 9:
            InputXbarRegs.INPUT9SELECT=gpio;
            break;
        case 10:
            InputXbarRegs.INPUT10SELECT=gpio;
            break;
        case 11:
            InputXbarRegs.INPUT11SELECT=gpio;
            break;
        case 12:
            InputXbarRegs.INPUT12SELECT=gpio;
            break;
        case 13:
            InputXbarRegs.INPUT13SELECT=gpio;
            break;
        case 14:
            InputXbarRegs.INPUT14SELECT=gpio;
            break;
        case 15:
            InputXbarRegs.INPUT15SELECT=gpio;
            break;
        case 16:
            InputXbarRegs.INPUT16SELECT=gpio;
            break;
        }


    }
}


void Set_PwmMux0Xbar(Uint16 epwmxbar_output,enum MUX0_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX0=selector;
        break;
    }

}

void Set_PwmMux1Xbar(Uint16 epwmxbar_output,enum MUX1_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX1=selector;
        break;
    }

}

void Set_PwmMux2Xbar(Uint16 epwmxbar_output,enum MUX2_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX2=selector;
        break;
    }

}

void Set_PwmMux3Xbar(Uint16 epwmxbar_output,enum MUX3_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX3=selector;
        break;
    }

}

void Set_PwmMux4Xbar(Uint16 epwmxbar_output,enum MUX4_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX4=selector;
        break;
    }

}

void Set_PwmMux5Xbar(Uint16 epwmxbar_output,enum MUX5_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX5=selector;
        break;
    }

}

void Set_PwmMux6Xbar(Uint16 epwmxbar_output,enum MUX6_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX6=selector;
        break;
    }

}

void Set_PwmMux7Xbar(Uint16 epwmxbar_output,enum MUX7_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX7=selector;
        break;
    }

}

void Set_PwmMux8Xbar(Uint16 epwmxbar_output,enum MUX8_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX8=selector;
        break;
    }

}

void Set_PwmMux9Xbar(Uint16 epwmxbar_output,enum MUX9_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX9=selector;
        break;
    }

}

void Set_PwmMux10Xbar(Uint16 epwmxbar_output,enum MUX10_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX10=selector;
        break;
    }

}

void Set_PwmMux11Xbar(Uint16 epwmxbar_output,enum MUX11_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX11=selector;
        break;
    }

}

void Set_PwmMux12Xbar(Uint16 epwmxbar_output,enum MUX12_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX12=selector;
        break;
    }

}

void Set_PwmMux13Xbar(Uint16 epwmxbar_output,enum MUX13_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX13=selector;
        break;
    }

}

void Set_PwmMux14Xbar(Uint16 epwmxbar_output,enum MUX14_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX14=selector;
        break;
    }

}

void Set_PwmMux15Xbar(Uint16 epwmxbar_output,enum MUX15_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX0TO15CFG.bit.MUX15=selector;
        break;
    }

}

void Set_PwmMux16Xbar(Uint16 epwmxbar_output,enum MUX16_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX16=selector;
        break;
    }

}

void Set_PwmMux17Xbar(Uint16 epwmxbar_output,enum MUX17_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX17=selector;
        break;
    }

}

void Set_PwmMux18Xbar(Uint16 epwmxbar_output,enum MUX18_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX18=selector;
        break;
    }

}

void Set_PwmMux19Xbar(Uint16 epwmxbar_output,enum MUX19_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX19=selector;
        break;
    }

}

void Set_PwmMux20Xbar(Uint16 epwmxbar_output,enum MUX20_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX20=selector;
        break;
    }

}

void Set_PwmMux21Xbar(Uint16 epwmxbar_output,enum MUX21_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX21=selector;
        break;
    }

}

void Set_PwmMux22Xbar(Uint16 epwmxbar_output,enum MUX22_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX22=selector;
        break;
    }

}

void Set_PwmMux23Xbar(Uint16 epwmxbar_output,enum MUX23_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX23=selector;
        break;
    }

}

void Set_PwmMux25Xbar(Uint16 epwmxbar_output,enum MUX25_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX25=selector;
        break;
    }

}


void Set_PwmMux27Xbar(Uint16 epwmxbar_output,enum MUX27_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX27=selector;
        break;
    }

}

void Set_PwmMux29Xbar(Uint16 epwmxbar_output,enum MUX29_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX29=selector;
        break;
    }

}


void Set_PwmMux31Xbar(Uint16 epwmxbar_output,enum MUX31_PWM_XBAR selector)
{

    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUX16TO31CFG.bit.MUX31=selector;
        break;
    }

}




void Set_PwmMuxEnabler(Uint16 epwmxbar_output,Uint32 trip_enabler)
{
    switch(epwmxbar_output)
    {
    case 4:
        EPwmXbarRegs.TRIP4MUXENABLE.all=trip_enabler;
        break;
    case 5:
        EPwmXbarRegs.TRIP5MUXENABLE.all=trip_enabler;
        break;
    case 7:
        EPwmXbarRegs.TRIP7MUXENABLE.all=trip_enabler;
        break;
    case 8:
        EPwmXbarRegs.TRIP8MUXENABLE.all=trip_enabler;
        break;
    case 9:
        EPwmXbarRegs.TRIP9MUXENABLE.all=trip_enabler;
        break;
    case 10:
        EPwmXbarRegs.TRIP10MUXENABLE.all=trip_enabler;
        break;
    case 11:
        EPwmXbarRegs.TRIP11MUXENABLE.all=trip_enabler;
        break;
    case 12:
        EPwmXbarRegs.TRIP12MUXENABLE.all=trip_enabler;
        break;

    }
}

void Set_PwmOutInvert(Uint16 epwmxbar_output,bool invert_option)
{
    if((invert_option==true)||(invert_option==false))
    {
        switch(epwmxbar_output)
        {
        case 4:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP4=invert_option;
            break;
        case 5:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP5=invert_option;
            break;
        case 7:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP7=invert_option;
            break;
        case 8:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP8=invert_option;
            break;
        case 9:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP9=invert_option;
            break;
        case 10:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP10=invert_option;
            break;
        case 11:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP11=invert_option;
            break;
        case 12:
            EPwmXbarRegs.TRIPOUTINV.bit.TRIP12=invert_option;
            break;
        }
    }
}



void Set_CLBMux0Xbar(Uint16 clbxbar_output,enum MUX0_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX0=selector;
        break;
    }

}

void Set_CLBMux1Xbar(Uint16 clbxbar_output,enum MUX1_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX1=selector;
        break;
    }

}

void Set_CLBMux2Xbar(Uint16 clbxbar_output,enum MUX2_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX2=selector;
        break;
    }

}

void Set_CLBMux3Xbar(Uint16 clbxbar_output,enum MUX3_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX3=selector;
        break;
    }

}

void Set_CLBMux4Xbar(Uint16 clbxbar_output,enum MUX4_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX4=selector;
        break;
    }

}

void Set_CLBMux5Xbar(Uint16 clbxbar_output,enum MUX5_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX5=selector;
        break;
    }

}

void Set_CLBMux6Xbar(Uint16 clbxbar_output,enum MUX6_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX6=selector;
        break;
    }

}

void Set_CLBMux7Xbar(Uint16 clbxbar_output,enum MUX7_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX7=selector;
        break;
    }

}

void Set_CLBMux8Xbar(Uint16 clbxbar_output,enum MUX8_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX8=selector;
        break;
    }

}

void Set_CLBMux9Xbar(Uint16 clbxbar_output,enum MUX9_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX9=selector;
        break;
    }

}

void Set_CLBMux10Xbar(Uint16 clbxbar_output,enum MUX10_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX10=selector;
        break;
    }

}

void Set_CLBMux11Xbar(Uint16 clbxbar_output,enum MUX11_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX11=selector;
        break;
    }

}

void Set_CLBMux12Xbar(Uint16 clbxbar_output,enum MUX12_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX12=selector;
        break;
    }

}

void Set_CLBMux13Xbar(Uint16 clbxbar_output,enum MUX13_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX13=selector;
        break;
    }

}

void Set_CLBMux14Xbar(Uint16 clbxbar_output,enum MUX14_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX14=selector;
        break;
    }

}

void Set_CLBMux15Xbar(Uint16 clbxbar_output,enum MUX15_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX0TO15CFG.bit.MUX15=selector;
        break;
    }

}

void Set_CLBMux16Xbar(Uint16 clbxbar_output,enum MUX16_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX16=selector;
        break;
    }

}

void Set_CLBMux17Xbar(Uint16 clbxbar_output,enum MUX17_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX17=selector;
        break;
    }

}

void Set_CLBMux18Xbar(Uint16 clbxbar_output,enum MUX18_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX18=selector;
        break;
    }

}

void Set_CLBMux19Xbar(Uint16 clbxbar_output,enum MUX19_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX19=selector;
        break;
    }

}
void Set_CLBMux20Xbar(Uint16 clbxbar_output,enum MUX20_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX20=selector;
        break;
    }

}
void Set_CLBMux21Xbar(Uint16 clbxbar_output,enum MUX21_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX21=selector;
        break;
    }

}

void Set_CLBMux22Xbar(Uint16 clbxbar_output,enum MUX22_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX22=selector;
        break;
    }

}

void Set_CLBMux23Xbar(Uint16 clbxbar_output,enum MUX23_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX23=selector;
        break;
    }

}

void Set_CLBMux25Xbar(Uint16 clbxbar_output,enum MUX25_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX25=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX25=selector;
        break;
    }

}

void Set_CLBMux27Xbar(Uint16 clbxbar_output,enum MUX27_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX27=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX27=selector;
        break;
    }

}

void Set_CLBMux29Xbar(Uint16 clbxbar_output,enum MUX29_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX29=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX29=selector;
        break;
    }

}

void Set_CLBMux31Xbar(Uint16 clbxbar_output,enum MUX31_CLB_XBAR selector)
{

    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUX16TO31CFG.bit.MUX31=selector;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUX16TO31CFG.bit.MUX31=selector;
        break;
    }

}

void Set_CLBOutInvert(Uint16 clbxbar_output,bool invert_option)
{
    if((invert_option==true)||(invert_option==false))
    {
        switch(clbxbar_output)
        {
        case 0:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT0=invert_option;
            break;
        case 1:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT1=invert_option;
            break;
        case 2:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT2=invert_option;
            break;
        case 3:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT3=invert_option;
            break;
        case 4:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT4=invert_option;
            break;
        case 5:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT5=invert_option;
            break;
        case 6:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT6=invert_option;
            break;
        case 7:
            CLBXbarRegs.AUXSIGOUTINV.bit.OUT7=invert_option;
            break;

        }
    }
}

void Set_CLBMuxEnabler(Uint16 clbxbar_output,Uint32 trip_enabler)
{
    switch(clbxbar_output)
    {
    case 0:
        CLBXbarRegs.AUXSIG0MUXENABLE.all=trip_enabler;
        break;
    case 1:
        CLBXbarRegs.AUXSIG1MUXENABLE.all=trip_enabler;
        break;
    case 2:
        CLBXbarRegs.AUXSIG2MUXENABLE.all=trip_enabler;
        break;
    case 3:
        CLBXbarRegs.AUXSIG3MUXENABLE.all=trip_enabler;
        break;
    case 4:
        CLBXbarRegs.AUXSIG4MUXENABLE.all=trip_enabler;
        break;
    case 5:
        CLBXbarRegs.AUXSIG5MUXENABLE.all=trip_enabler;
        break;
    case 6:
        CLBXbarRegs.AUXSIG6MUXENABLE.all=trip_enabler;
        break;
    case 7:
        CLBXbarRegs.AUXSIG7MUXENABLE.all=trip_enabler;
        break;

    }
}

void Set_OutputMux0Xbar(Uint16 outputxbar_output,enum MUX0_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX0=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX0=selector;
        break;
    }

}

void Set_OutputMux1Xbar(Uint16 outputxbar_output,enum MUX1_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX1=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX1=selector;
        break;
    }

}

void Set_OutputMux2Xbar(Uint16 outputxbar_output,enum MUX2_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX2=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX2=selector;
        break;
    }

}

void Set_OutputMux3Xbar(Uint16 outputxbar_output,enum MUX3_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX3=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX3=selector;
        break;
    }

}

void Set_OutputMux4Xbar(Uint16 outputxbar_output,enum MUX4_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX4=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX4=selector;
        break;
    }

}

void Set_OutputMux5Xbar(Uint16 outputxbar_output,enum MUX5_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX5=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX5=selector;
        break;
    }

}

void Set_OutputMux6Xbar(Uint16 outputxbar_output,enum MUX6_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX6=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX6=selector;
        break;
    }

}

void Set_OutputMux7Xbar(Uint16 outputxbar_output,enum MUX7_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX7=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX7=selector;
        break;
    }

}

void Set_OutputMux8Xbar(Uint16 outputxbar_output,enum MUX8_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX8=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX8=selector;
        break;
    }

}

void Set_OutputMux9Xbar(Uint16 outputxbar_output,enum MUX9_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX9=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX9=selector;
        break;
    }

}

void Set_OutputMux10Xbar(Uint16 outputxbar_output,enum MUX10_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX10=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX10=selector;
        break;
    }

}

void Set_OutputMux11Xbar(Uint16 outputxbar_output,enum MUX11_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX11=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX11=selector;
        break;
    }

}

void Set_OutputMux12Xbar(Uint16 outputxbar_output,enum MUX12_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX12=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX12=selector;
        break;
    }

}

void Set_OutputMux13Xbar(Uint16 outputxbar_output,enum MUX13_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX13=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX13=selector;
        break;
    }

}

void Set_OutputMux14Xbar(Uint16 outputxbar_output,enum MUX14_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX14=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX14=selector;
        break;
    }

}

void Set_OutputMux15Xbar(Uint16 outputxbar_output,enum MUX15_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX0TO15CFG.bit.MUX15=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX0TO15CFG.bit.MUX15=selector;
        break;
    }

}

void Set_OutputMux16Xbar(Uint16 outputxbar_output,enum MUX16_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX16=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX16=selector;
        break;
    }

}

void Set_OutputMux17Xbar(Uint16 outputxbar_output,enum MUX17_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX17=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX17=selector;
        break;
    }

}

void Set_OutputMux18Xbar(Uint16 outputxbar_output,enum MUX18_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX18=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX18=selector;
        break;
    }

}

void Set_OutputMux19Xbar(Uint16 outputxbar_output,enum MUX19_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX19=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX19=selector;
        break;
    }

}

void Set_OutputMux20Xbar(Uint16 outputxbar_output,enum MUX20_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX20=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX20=selector;
        break;
    }

}

void Set_OutputMux21Xbar(Uint16 outputxbar_output,enum MUX21_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX21=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX21=selector;
        break;
    }

}

void Set_OutputMux22Xbar(Uint16 outputxbar_output,enum MUX22_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX22=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX22=selector;
        break;
    }

}

void Set_OutputMux23Xbar(Uint16 outputxbar_output,enum MUX23_OUTPUT_XBAR selector)
{

    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUX16TO31CFG.bit.MUX23=selector;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUX16TO31CFG.bit.MUX23=selector;
        break;
    }

}


void Set_OutputMuxEnabler(Uint16 outputxbar_output,Uint32 trip_enabler)
{
    switch(outputxbar_output)
    {
    case 0:
        OutputXbarRegs.OUTPUT1MUXENABLE.all=trip_enabler;
        break;
    case 1:
        OutputXbarRegs.OUTPUT2MUXENABLE.all=trip_enabler;
        break;
    case 2:
        OutputXbarRegs.OUTPUT3MUXENABLE.all=trip_enabler;
        break;
    case 3:
        OutputXbarRegs.OUTPUT4MUXENABLE.all=trip_enabler;
        break;
    case 4:
        OutputXbarRegs.OUTPUT5MUXENABLE.all=trip_enabler;
        break;
    case 5:
        OutputXbarRegs.OUTPUT6MUXENABLE.all=trip_enabler;
        break;
    case 6:
        OutputXbarRegs.OUTPUT7MUXENABLE.all=trip_enabler;
        break;
    case 7:
        OutputXbarRegs.OUTPUT8MUXENABLE.all=trip_enabler;
        break;

    }
}

void Set_OutputOutInvert(Uint16 outputxbar_output,bool invert_option)
{
    if((invert_option==true)||(invert_option==false))
    {
        switch(outputxbar_output)
        {
        case 0:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT1=invert_option;
            break;
        case 1:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT2=invert_option;
            break;
        case 2:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT3=invert_option;
            break;
        case 3:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT4=invert_option;
            break;
        case 4:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT5=invert_option;
            break;
        case 5:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT6=invert_option;
            break;
        case 6:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT7=invert_option;
            break;
        case 7:
            OutputXbarRegs.OUTPUTINV.bit.OUTPUT8=invert_option;
            break;

        }
    }
}
