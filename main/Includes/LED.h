#include "led_strip.h"


class LED
{
    private:
    led_strip_handle_t Led_strip;
    int GPIO;
    bool ON;
    int R = 255;
    int G = 255;
    int B = 255;

    public:
    LED(int GPIO);
    void Configure();
    void Set_RGB(int r, int g, int b);
    void Blink();

};
