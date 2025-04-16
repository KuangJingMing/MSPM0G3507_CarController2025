#include "motor_controller.h"
#include "log.h"
//#include "log_config.h"

// �����������ڶ�ȡ�ٶȲ����� OLED ��ʾ
 void DisplayTask(void *pvParameters)
{
    float right_speed, left_speed;
    const TickType_t xDelay = pdMS_TO_TICKS(20); // ÿ 20ms ����һ����ʾ
    static int log_counter = 0; // ���ڽ�����־���Ƶ�ʵļ�����
    const int log_frequency = 50; // ÿ 50 ��ѭ�����һ����־���� 50 * 20ms = 1000ms����ÿ�����һ�Σ�

    for (;;) {
        // ��ȡ���ҵ���ٶ�
        right_speed = get_right_motor_speed();
        left_speed = get_left_motor_speed();

        // ���� OLED ��ʾ
        OLED_Showdecimal(0, 0, right_speed, 4, 2, 16, 1);
        OLED_Showdecimal(1, 3, left_speed, 4, 2, 16, 1);

        // ÿ��һ���������һ����־���������Ƶ��
        log_counter++;
        if (log_counter >= log_frequency) {
            LOG_I("DisplayTask - Left Motor Speed: %.3f m/s, Right Motor Speed: %.3f m/s", left_speed, right_speed);
            log_counter = 0; // ���ü�����
        }

        // �����ӳ� 20ms
        vTaskDelay(xDelay);
    }
}
