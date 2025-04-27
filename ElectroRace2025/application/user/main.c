#include "common_include.h"
#include "log_config.h"
#include "log.h"

void vOLEDTask(void *pvParameters)
{
	vOLEDOpeningAnimation();
	for ( ; ; ) {
		delay_ms(1);
	}
}

int main(void)
{
    // ϵͳ��Ӳ����ʼ��
    SYSCFG_DL_init();
    // ������ʾ����
		xTaskCreate(vOLEDTask, "OLED", 512, NULL, tskIDLE_PRIORITY+1, NULL);
    // ���� FreeRTOS ������
    vTaskStartScheduler();
    while (1) {
    }

    return 0;
}