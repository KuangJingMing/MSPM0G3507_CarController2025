#include "common_include.h"
#include "log_config.h"
#include "log.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "encoder.h" // ����������ı�����ͷ�ļ�

void TestTask(void *arg) {
	for ( ; ; ) {
		
		delay_ms(100);
	}
}



int main(void)
{
    // ϵͳ��Ӳ����ʼ��
    SYSCFG_DL_init();
		embedfire_protocol_receive_init();
    gray_detection_init();
    OLED_Init();
    // OLED_Test(); // �������Ҫ���ԣ�����ע�͵�
    Encoder_init(); // ��������ʼ�������� FreeRTOS �����ʱ����
		motor_init();
		motor_set_pwm(MOTOR_FRONT_LEFT, -1500);
		motor_set_pwm(MOTOR_FRONT_RIGHT, -1500);
    // ������ʾ����
    xTaskCreate(TestTask, "TestTask", configMINIMAL_STACK_SIZE * 4, NULL, tskIDLE_PRIORITY + 1, NULL);
    // ���� FreeRTOS ������
    vTaskStartScheduler();

    while (1) {
    }

    return 0;
}