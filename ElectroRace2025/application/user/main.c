#include "common_include.h"
//#include "log_config.h"
#include "log.h"

void init_task(void *pvParameters) {
	menu_init();
	vTaskDelete(NULL);
}

int main(void)
{
    SYSCFG_DL_init(); // ϵͳ��Ӳ����ʼ��
		xTaskCreate(init_task, "init_task", 64, NULL, tskIDLE_PRIORITY + 2, NULL);
		vTaskStartScheduler();
    while (1) {
    
		}
    return 0;
}
