task main()
{
    // 超声波传感器
    // TODO  getUSDistance 注：不清楚返回厘米和英寸如何区分
    // 超声波传感器获取障碍物距离大于10时
    while (getUSDistance(S3) > 10)
    {
        // 获取的距离值显示在EV3上第一行
        displayBigTextLine(0, "%d", getUSDistance(S3));
        //设置A和B电机功率为20
        setMotorSpeed(motorA, 20);
        setMotorSpeed(motorB, 20);
    }
    //循环结束停止电机
    setMotorSpeed(motorA, 0);
    setMotorSpeed(motorB, 0);
}

/**
 * getUSDistance(nDeviceIndex);
 * 功能：获取超声波传感器感应到前方障碍物的值（0--255cm / 0--100Inch）
 * 参数1：nDeviceIndex 传感器端口或名称
 */