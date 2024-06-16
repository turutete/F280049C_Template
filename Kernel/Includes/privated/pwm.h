/*
 * pwm.h
 *
 *  Created on: 10 may. 2024
 *      Author: Dr. Carlos Romero
 */

#ifndef KERNEL_INCLUDES_PRIVATED_PWM_H_
#define KERNEL_INCLUDES_PRIVATED_PWM_H_

typedef struct
{

}clase_pwm_config;


typedef struct
{
    // Atributos


    // Métodos
    void (* Init )(void);
    clase_pwm_config set;


} clase_pwm;

extern clase_pwm pwm;

#endif /* KERNEL_INCLUDES_PRIVATED_PWM_H_ */
