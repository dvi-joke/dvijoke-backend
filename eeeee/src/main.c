#include <esp_log.h>
#include <driver/gpio.h>
#include <portmacro.h>

// Тег для логирования
static const char *TAG = "BlinkExample";

// Пин встроенного LED (обычно GPIO8)
#define LED_PIN 8

void app_main(void)
{
    // Настройка пина как выходного
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    ESP_LOGI(TAG, "ESP32-C3 Blink Test Started!");

    while (1)
    {
        // Включаем LED
        gpio_set_level(LED_PIN, 1); // HIGH
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Ждём 1 секунду

        // Выключаем LED
        gpio_set_level(LED_PIN, 0); // LOW
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Ждём 1 секунду
    }
}