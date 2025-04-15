/*
 * encoder.h
 *
 *  Created on: [Current Date]
 *      Author: [Your Name]
 *
 *  Header file for encoder counting functionality on MSPM0G350X using GPIO interrupts.
 *  Designed for counting using pulse and direction signals (ENC_P, D1/D2) from the motor driver.
 *  Pin mapping (based on configuration):
 *    - Motor 1: P1 (Pulse) -> PB4 (Encoder_GPIO_Encoder_P1_PIN)
 *    - Motor 1: D1 (Direction) -> PB5 (Encoder_GPIO_Encoder_D1_PIN)
 *    - Motor 2: P2 (Pulse) -> PB6 (Encoder_GPIO_Encoder_P2_PIN)
 *    - Motor 2: D2 (Direction) -> PB7 (Encoder_GPIO_Encoder_D2_PIN)
 */

#ifndef ENCODER_H_
#define ENCODER_H_

#include <stdint.h>
#include "ti_msp_dl_config.h"

typedef struct {
    int left_motor_period_ms;      // �������ڣ����룩
    int right_motor_period_ms;     // �ҵ�����ڣ����룩
    float left_motor_speed_rpm;    // �����ٶȣ�RPM��
    float right_motor_speed_rpm;   // �ҵ���ٶȣ�RPM��
    float left_motor_speed_cmps;   // �����ٶȣ�cm/s��
    float right_motor_speed_cmps;  // �ҵ���ٶȣ�cm/s��
} encoder;

// ����������ȫ�ֱ���
extern int left_motor_period_cnt;     // �����������
extern int right_motor_period_cnt;    // �ҵ���������

void Encoder_init(void);
extern float get_left_motor_speed(void);
extern float get_right_motor_speed(void);

#endif /* ENCODER_H_ */