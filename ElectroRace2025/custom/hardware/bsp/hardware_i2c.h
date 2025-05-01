#ifndef HARDWARE_I2C_H
#define HARDWARE_I2C_H

#include <stdint.h> // ���� uint8_t �����Ͷ���
#include "ti_msp_dl_config.h" // ���� I2C_Regs ���Ͷ���� I2C_0_INST ��ʵ������

// ���� I2C_Regs �ṹ�壬��� ti_msp_dl_config.h û��ֱ�Ӷ���
// ͨ�� ti_msp_dl_config.h ��ͨ���������� DriverLib ͷ�ļ�������
// �������ʱ�����Ҳ��� I2C_Regs��������Ҫ������������� DriverLib ͷ�ļ����ҵ������������岢��������
// ����ȷ�� ti_msp_dl_config.h �Ѿ���������ȷ��ͷ�ļ���
// ���磬������Ҫ���������İ�����
// #include "ti/devices/msp/mspm0g/driverlib/dl_i2c.h"


#ifdef __cplusplus
extern "C" {
#endif

#if (i2c_miss_up_enable == 1)
/**
 * @brief ͨ��I2Cд��Ĵ������ݣ�����ʱ���ƣ�
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param DevAddr I2C�豸��ַ
 * @param reg_addr �Ĵ�����ַ
 * @param reg_data ��д�����ݵ�ָ��
 * @param count ��д�����ݵ��ֽ���
 */
void I2C_WriteReg(I2C_Regs *i2c, uint8_t DevAddr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);

/**
 * @brief ͨ��I2C��ȡ�Ĵ������ݣ�����ʱ���ƣ�
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param DevAddr I2C�豸��ַ
 * @param reg_addr �Ĵ�����ַ
 * @param reg_data �洢��ȡ���ݵĻ�����ָ��
 * @param count ����ȡ���ݵ��ֽ���
 */
void I2C_ReadReg(I2C_Regs *i2c, uint8_t DevAddr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);

#else

/**
 * @brief ͨ��I2Cд��Ĵ������ݣ�������ʱ���ƣ�
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param DevAddr I2C�豸��ַ
 * @param reg_addr �Ĵ�����ַ
 * @param reg_data ��д�����ݵ�ָ��
 * @param count ��д�����ݵ��ֽ���
 */
void I2C_WriteReg(I2C_Regs *i2c, uint8_t DevAddr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);

/**
 * @brief ͨ��I2C��ȡ�Ĵ������ݣ�������ʱ���ƣ�
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param DevAddr I2C�豸��ַ
 * @param reg_addr �Ĵ�����ַ
 * @param reg_data �洢��ȡ���ݵĻ�����ָ��
 * @param count ����ȡ���ݵ��ֽ���
 */
void I2C_ReadReg(I2C_Regs *i2c, uint8_t DevAddr, uint8_t reg_addr, uint8_t *reg_data, uint8_t count);

#endif // i2c_miss_up_enable


/**
 * @brief ͨ��I2C���豸���ֽ�д������
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param SlaveAddress I2C�豸��ַ
 * @param REG_Address �Ĵ�����ַ
 * @param REG_data ��д��ĵ��ֽ�����
 */
void single_writei2c(I2C_Regs *i2c, unsigned char SlaveAddress, unsigned char REG_Address, unsigned char REG_data);

/**
 * @brief ͨ��I2C���豸���ֽڶ�ȡ����
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param SlaveAddress I2C�豸��ַ
 * @param REG_Address �Ĵ�����ַ
 * @return unsigned char ��ȡ���ĵ��ֽ�����
 */
unsigned char single_readi2c(I2C_Regs *i2c, unsigned char SlaveAddress, unsigned char REG_Address);

/**
 * @brief ͨ��I2C���豸��ȡָ���ֽ���������
 *
 * @param i2c ָ��I2C����Ĵ����ṹ��ָ��
 * @param addr I2C�豸��ַ
 * @param regAddr �Ĵ�����ַ
 * @param data �洢��ȡ���ݵĻ�����ָ��
 * @param length ����ȡ���ݵ��ֽ���
 */
void i2creadnbyte(I2C_Regs *i2c, uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length);


#ifdef __cplusplus
}
#endif

#endif // HARDWARE_I2C_H
