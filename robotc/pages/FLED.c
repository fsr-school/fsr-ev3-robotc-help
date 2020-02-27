task main()
{
    // 程序块状态灯模块

    //无限循环
    while (true)
    {
        // 将LED绿色灯闪烁两秒钟
        setLEDColor(ledGreenFlash);
        sleep(2000);
        //将LED红色脉动两秒钟
        setLEDColor(ledRedPulse);
        sleep(2000);
        //将LED持续点亮橙色两秒钟
        setLEDColor(ledOrange);
        sleep(2000);
    }
}

/**
 * setLEDColor(TEV3LEDpatterns);
 * 功能：设置EV3 LED的颜色和闪烁组合
 * 参数1：TEV3LEDpatterns TEV3LED模式有10个选项：
 * LED_BLACK：关闭LED。
 * LED_GREEN：将LED点亮为稳定的绿色。
 * LED_RED：将LED点亮为稳定的红色。
 * LED_ORANGE：将LED点亮为稳定的橙色。
 * LED_GREEN_FLASH：将LED点亮为绿色闪烁。
 * LED_RED_FLASH：将LED点亮为闪烁的红色。
 * LED_ORANGE_FLASH：将LED点亮为闪烁的橙色。
 * LED_GREEN_PULSE：将LED点亮为绿色。
 * LED_RED_PULSE：将LED点亮为红色。
 * LED_ORANGE_PULSE：将LED点亮为橙色。
 */