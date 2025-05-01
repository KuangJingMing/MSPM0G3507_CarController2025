#ifndef __ICM20608_H
#define __ICM20608_H

// IMU ID ����
#define IMU_ICM20689_ID  0x98
// IMU I2C ��ַ (ͨ��Ϊ 0x68 �� 0x69)
#define ICM20689_ADRESS		0x68

#include "ti_msp_dl_config.h"
#include "data_type.h" // ȷ������ vector3f �Ķ���

// ����������ת��ϵ�� (��ԭʼ LSB ת��Ϊ deg/s)
// ��Ҫ���� GYRO_CONFIG �Ĵ������õ�������ȷ��
// ���磺���� +/-500 deg/s ���̣�������Ϊ 65.5 LSB/deg/s����ϵ��Ϊ 1 / 65.5 = 0.015267...
//#define GYRO_CALIBRATION_COFF 0.060976f  // ��Ӧ +/-2000 deg/s ����
//#define GYRO_CALIBRATION_COFF 0.030488f; // ��Ӧ +/-1000 deg/s ����
#define GYRO_CALIBRATION_COFF 0.0152672f  // ��Ӧ +/-500 deg/s ���� (��˶������ֲᾫȷֵ)

// �����������ٶȱ�׼ֵ (m/s/s)
#define GRAVITY_MSS 9.80665f
// ���ٶȼ����̶�Ӧ��ԭʼֵ (���� +/-4g ���̣������� 8192 LSB/g)
// ��Ҫ���� ACCEL_CONFIG �Ĵ������õ�������ȷ��
#define GRAVITY_RAW 8192.0f // ��Ӧ +/-4g ���� (��˶������ֲᾫȷֵ)

// ��ԭʼ���ٶȼ�ֵת��Ϊ��λ g (RAW / GRAVITY_RAW)
#define RAW_TO_G     (1.0f / GRAVITY_RAW) // �޸�Ϊֱ�ӵĳ�����������
// ����λ g ת��Ϊԭʼ���ٶȼ�ֵ (g * GRAVITY_RAW)
#define G_TO_RAW  	 GRAVITY_RAW

// IMU �Ĵ�����ַ����
#define	SMPLRT_DIV		0x19 // �����ʷ�Ƶ�Ĵ���
#define	MPU_CONFIG		0x1A // ���üĴ��� (DLPF ���õ�)
#define	GYRO_CONFIG		0x1B // ���������üĴ��� (���̺� DLPF)
#define	ACCEL_CONFIG  0x1C // ���ٶȼ����üĴ��� (����)
#define ACCEL_CONFIG2 0x1D // ���ٶȼ����üĴ��� 2 (DLPF)
#define	ACCEL_XOUT_H	0x3B // ���ٶȼ� X ��� 8 λ
#define	ACCEL_XOUT_L	0x3C // ���ٶȼ� X ��� 8 λ
#define	ACCEL_YOUT_H	0x3D // ���ٶȼ� Y ��� 8 λ
#define	ACCEL_YOUT_L	0x3E // ���ٶȼ� Y ��� 8 λ
#define	ACCEL_ZOUT_H	0x3F // ���ٶȼ� Z ��� 8 λ
#define	ACCEL_ZOUT_L	0x40 // ���ٶȼ� Z ��� 8 λ
#define	TEMP_OUT_H		0x41 // �¶ȸ� 8 λ
#define	TEMP_OUT_L		0x42 // �¶ȵ� 8 λ
#define	GYRO_XOUT_H		0x43 // ������ X ��� 8 λ
#define	GYRO_XOUT_L		0x44 // ������ X ��� 8 λ
#define	GYRO_YOUT_H		0x45 // ������ Y ��� 8 λ
#define	GYRO_YOUT_L		0x46 // ������ Y ��� 8 λ
#define	GYRO_ZOUT_H		0x47 // ������ Z ��� 8 λ
#define	GYRO_ZOUT_L		0x48 // ������ Z ��� 8 λ
#define	PWR_MGMT_1		0x6B // ��Դ����Ĵ��� 1
#define	WHO_AM_I		  0x75 // WHO_AM_I �Ĵ��� (оƬ ID)
#define USER_CTRL		  0x6A // �û����ƼĴ���
#define INT_PIN_CFG		0x37 // �ж��������üĴ���

// ��֪ IMU оƬ�� WHO_AM_I ֵ
typedef enum
{
	WHO_AM_I_MPU6050  =0x68,
	WHO_AM_I_ICM20689 =0x98,
	WHO_AM_I_ICM20608D=0xAE, // ����Ϊ 0xAE������������ֲ�ȷ��
	WHO_AM_I_ICM20608G=0xAF, // ����Ϊ 0xAF������������ֲ�ȷ��
	WHO_AM_I_ICM20602=0x12,  // ����Ϊ 0x12������������ֲ�ȷ��
    WHO_AM_I_UNKNOWN  =0xFF, // δ֪ ID
}IMU_ID_READ;

/**
 * @brief ��ʼ�� ICM206xx ϵ�� IMU ������
 * @return uint8_t 0: �ɹ�, 1: ʧ��
 */
uint8_t ICM206xx_Init(void);

/**
 * @brief �� ICM206xx ��������ȡ���ٶȼơ������Ǻ��¶�����
 * @param gyro ָ��洢���������ݵĽṹ�� (��λ deg/s)
 * @param accel ָ��洢���ٶȼ����ݵĽṹ�� (��λ g)
 * @param temperature ָ��洢�¶����ݵı��� (��λ ���϶�)
 */
void ICM206xx_Read_Data(vector3f *gyro,vector3f *accel,float *temperature);




#endif // __ICM20608_H