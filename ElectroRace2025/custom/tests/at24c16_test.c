#include "common_include.h"
#include "tests.h"
#include "log_config.h"
#include "log.h"

// Ҫд��Ͷ�ȡ�����ݳ���
#define TEST_DATA_LEN 8 // �������������򻯲���
// Ҫд��Ͷ�ȡ�� EEPROM ��ַ
#define TEST_START_ADDR 0x0000 // ������ 0x0000-0x00FF ��Χ��

static uint8_t tx_buf[TEST_DATA_LEN];
static uint8_t rx_buf[TEST_DATA_LEN];
// ����һ��ȫ�ֵ� AT24CXX ���
static at24cxx_handle_t at24cxx_handle;

/**
 * @brief ���β��� AT24CXX �ĺ���
 */
void at24cxx_single_test(void)
{
    uint8_t res;
    uint32_t i;

    log_i("Starting AT24CXX single test...");

    // 1. ��� AT24CXX ����ṹ��
    DRIVER_AT24CXX_LINK_INIT(&at24cxx_handle, at24cxx_handle_t); // �������ṹ��
    at24cxx_handle.debug_print = at24cxx_interface_debug_print;
    at24cxx_handle.iic_init = at24cxx_interface_iic_init;
    at24cxx_handle.iic_deinit = at24cxx_interface_iic_deinit;
    at24cxx_handle.iic_read = at24cxx_interface_iic_read;
    at24cxx_handle.iic_write = at24cxx_interface_iic_write;
    at24cxx_handle.iic_read_address16 = at24cxx_interface_iic_read_address16;
    at24cxx_handle.iic_write_address16 = at24cxx_interface_iic_write_address16;
    at24cxx_handle.delay_ms = at24cxx_interface_delay_ms;

    // ȷ������ I2C ��ַ
    at24cxx_handle.iic_addr = 0xA0; // A0, A1, A2 �ӵ�ʱ��д��ַ
    log_i("I2C address set to 0xA0 (8-bit write address).");

    // 2. ����оƬ����
    res = at24cxx_set_type(&at24cxx_handle, AT24C16);
    if (res != 0) {
        log_e("AT24CXX set type failed.");
        return;
    }
    log_i("AT24CXX set type success (AT24C16).");

    // 3. ��ʼ�� AT24C16 ����
    res = at24cxx_init(&at24cxx_handle);
    if (res != 0) {
        log_e("AT24CXX driver init failed. Test aborted.");
        return;
    }
    log_i("AT24CXX driver init success.");

    // 4. ׼����������
    memset(tx_buf, 0x00, sizeof(tx_buf));
    for (i = 0; i < TEST_DATA_LEN; i++) {
        tx_buf[i] = (uint8_t)(i + 1); // ʾ�����ݣ�1, 2, 3, ...
    }
    log_i("Prepare data to write:");
    for (i = 0; i < TEST_DATA_LEN; i++) {
        log_i("tx_buf[%lu] = 0x%02X", i, tx_buf[i]);
    }

    // 5. д�����ݵ� EEPROM
    log_i("Writing data to EEPROM at address 0x%04X, length=%d...", TEST_START_ADDR, TEST_DATA_LEN);
    res = at24cxx_write(&at24cxx_handle, TEST_START_ADDR, tx_buf, TEST_DATA_LEN);
    if (res != 0) {
        log_e("AT24CXX driver write failed.");
    } else {
        log_i("AT24CXX driver write success.");
    }

    // 6. �ȴ�д�������
    at24cxx_interface_delay_ms(10); // ����д�����ӳٵ� 20ms
    log_i("Waiting 20ms for write cycle to complete.");

    // 7. ��ȡ���ݽ�����֤
    memset(rx_buf, 0x00, sizeof(rx_buf));
    log_i("Reading data from EEPROM at address 0x%04X, length=%d...", TEST_START_ADDR, TEST_DATA_LEN);
    res = at24cxx_read(&at24cxx_handle, TEST_START_ADDR, rx_buf, TEST_DATA_LEN);
    if (res != 0) {
        log_e("AT24CXX driver read failed.");
    } else {
        log_i("AT24CXX driver read success.");
        log_i("Data read from EEPROM:");
        for (i = 0; i < TEST_DATA_LEN; i++) {
            log_i("rx_buf[%lu] = 0x%02X", i, rx_buf[i]);
        }

        // ��֤�����Ƿ�һ��
        if (memcmp(tx_buf, rx_buf, TEST_DATA_LEN) == 0) {
            log_i("Write and read data match. Test passed!");
        } else {
            log_e("Write and read data mismatch. Test failed!");
        }
    }

    // 8. ȥ��ʼ��
    res = at24cxx_deinit(&at24cxx_handle);
    if (res != 0) {
        log_e("AT24CXX driver deinit failed.");
    } else {
        log_i("AT24CXX driver deinit success.");
    }

    log_i("AT24CXX single test completed.");
}