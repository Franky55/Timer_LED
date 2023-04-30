#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "soc/timer_group_struct.h"
#include "driver/periph_ctrl.h"
#include "driver/timer.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "LED.h"
#include "Timer.h"

#define TIMER_DIVIDER (16)
#define TIMER_SCALE (TIMER)

bool s_led_state = true;


static const char* TAG = "example";

LED DEL(48);
Timer blink(50000);

// static void periodic_timer_callback(void* arg)
// {
//   static bool ON;
//   ON = !ON;

//   if(ON)
//   {
//     DEL.Set_RGB(250, 0, 0);
//   }
//   else
//   {
//     DEL.Set_RGB(0, 250, 50);
//   }

//     int64_t time_since_boot = esp_timer_get_time();
//     ESP_LOGI(TAG, "Periodic timer called, time since boot: %lld us", time_since_boot);
// }


extern "C" void app_main(void)
{

  // const esp_timer_create_args_t periodic_timer_args = {
  //           .callback = &periodic_timer_callback,
  //           /* name is optional, but may help identify the timer when debugging */
  //           .name = "periodic"
  //   };

  //   esp_timer_handle_t periodic_timer;
  //   esp_timer_create(&periodic_timer_args, &periodic_timer);
  //   esp_timer_start_periodic(periodic_timer, 50000);
 
  
  DEL.Configure();
  blink.AddNewFonct(&LED::Blink, DEL);
  blink.Configure_Start();
  
  DEL.Set_RGB(250, 0, 0);
    while (1) {
        
        vTaskDelay(50);
        esp_timer_dump(stdout);

    }
}