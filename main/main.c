#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "esp_log.h"
#include "lvgl.h"
#include "bsp/esp-bsp.h"
#include "bsp/display.h"
#include "lv_demos.h"


void app_main(void) {
    ESP_ERROR_CHECK(nvs_flash_init());
    
    bsp_display_cfg_t cfg = {
        .lvgl_port_cfg = ESP_LVGL_PORT_INIT_CONFIG(),
        .buffer_size = BSP_LCD_DRAW_BUFF_SIZE,
        .double_buffer = BSP_LCD_DRAW_BUFF_DOUBLE,
        .flags = {
            .buff_dma = true,
            .buff_spiram = false,
            .sw_rotate = false,
        }
    };

    bsp_display_start_with_config(&cfg);
    bsp_display_backlight_on();
    lv_init();
    bsp_display_lock(0);
        
    //lv_demo_music();
    //lv_demo_widgets();
    //lv_demo_benchmark();
    lv_demo_stress();
    bsp_display_unlock();
}
