#include "common_include.h"
#include "log_config.h"
#include "log.h"
#include "button_user.h"

void vOLEDTask(void *pvParameters)
{
	button_timer_init();
	button_timer_start();
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