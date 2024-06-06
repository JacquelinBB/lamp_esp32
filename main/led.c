#include <led.h>
#include <esp_log.h>

static const char *tag = "GPIO";

esp_err_t gpio_configure(void)
{
    ESP_LOGI(tag, "CONFIGURANDO LED");

    gpio_config_t io_conf = {};

    //desabilitar interrupção
    io_conf.intr_type = GPIO_INTR_DISABLE;

    //selecionar o modo dos pinos(output ou input)
    io_conf.mode = GPIO_MODE_OUTPUT;

    //selecionar quais pinos iremos configurar
    io_conf.pin_bit_mask = (1<<LUMINARIA);

    //configurar os resistores
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    gpio_config(&io_conf);

    return ESP_OK;
}

esp_err_t basic_gpio_set(void)
{
    ESP_LOGI(tag, "CONFIGURANDO LED");

    if(
        gpio_set_level(LUMINARIA, HIGH)
    )
    {
        ESP_LOGE(tag, "Erro ao setar os pinos");
        return ESP_FAIL;
    }
    return ESP_OK;
}