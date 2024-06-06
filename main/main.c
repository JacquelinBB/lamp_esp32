#include <stdio.h>
#include "esp_log.h"
#include "nvs_flash.h"
#include <stdio.h>
#include <string.h>
#include "esp_event.h"
#include "freertos/semphr.h"
#include "wifi.h"
#include "mqtt.h"

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG_W, "ESP_WIFI_MODE_STA");
    wifi_init_sta();
    ESP_LOGI(TAG_W, "ESP_WIFI_MQTT");
    mqtt_start();
    vTaskDelay(pdMS_TO_TICKS(100));
}