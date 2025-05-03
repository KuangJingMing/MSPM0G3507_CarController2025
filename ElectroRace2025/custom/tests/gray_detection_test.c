#include "tests.h"
#include "common_include.h"
#include "log_config.h"
#include "log.h"

static uint8_t gray_datas[12] = {0};

void gd_task(void *arg) {
		gray_detection_init();
    for ( ; ; )  {
				gray_read_data(gray_datas);
					    // 使用日志工具输出 gray_datas 数组内容
        log_i("Gray Data Array: %d %d %d %d %d %d %d %d %d %d %d %d",
						gray_datas[0], gray_datas[1], gray_datas[2], gray_datas[3],
						gray_datas[4], gray_datas[5], gray_datas[6], gray_datas[7],
						gray_datas[8], gray_datas[9], gray_datas[10], gray_datas[11]);
				delay_ms(200);
    }
}


void gd_task_create(void) {
    xTaskCreate(gd_task, "gd_task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
}
