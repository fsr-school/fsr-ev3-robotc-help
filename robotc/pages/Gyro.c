task main()
{
    // TODO 陀螺仪传感器模块，需要更精确验证

    // -------------------------------------------------

    //此程序将重置陀螺仪的航向,然后将机器人从当前位置旋转90度
    //将端口2的陀螺仪重置为0度
    resetGyro(S2);
    //保持循环直到陀螺仪传感器的读数大于当前位置超过90度
    repeatUntil(getGyroDegrees(S2) > 90)
    {
        // 向左拐
        setMotorSpeed(motorA, -50);
        setMotorSpeed(motorB, 50);
    }
    //在转弯结束时停止电动机
    setMotorSpeed(motorB, 0);
    setMotorSpeed(motorA, 0);

    // -------------------------------------------------

    //此程序将旋转机器人，直到陀螺仪读取与上次重置位置的距离大于90度
    //保持循环直到陀螺仪传感器的读数超过90度（从最新的重置位置开始）
    repeatUntil(getGyroHeading(S2) > 90)
    {
        displayBigTextLine(3, "%d", getGyroHeading(S2));
        //向左拐
        setMotorSpeed(motorA, -50);
        setMotorSpeed(motorB, 50);
    }
    //在转弯结束时停止电动机
    setMotorSpeed(motorA, 0);
    setMotorSpeed(motorB, 0);

    // -------------------------------------------------

    // 永远保持循环
    repeat(forever)
    {
        //如果陀螺仪传感器向左转，将机器人对准右边
        if (getGyroRate(S2) > 3)
        {
            displayBigTextLine(3, "%d", getGyroRate(S2));
            // 设置A电机功率为45，B电机为0功率
            setMotorSpeed(motorA, 45);
            setMotorSpeed(motorB, 30);
        }
        //如果陀螺仪传感器向右转，将机器人左移
        else if (getGyroRate(S2) < -3)
        {
            displayBigTextLine(3, "%d", getGyroRate(S2));
            //设置B电机功率为45，A电机功率为0
            setMotorSpeed(motorB, 45);
            setMotorSpeed(motorA, 30);
        }
        // 否则直线行走
        else
        {
            // 设置AB电机功率为50
            setMotorSpeed(motorA, 50);
            setMotorSpeed(motorB, 50);
        }
    }
}

/**
 * getGyroDegrees(nDeviceIndex);
 * 功能：获取陀螺仪度数 （顺时针旋转返回的值增加为正数，逆时针旋转返回的值减少为负数）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getGyroHeading(nDeviceIndex);
 * 功能：获取陀螺仪航向 （可获取到上一次的度数）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getGyroRate(nDeviceIndex);
 * 功能：获取陀螺仪速率 （单位为每秒度数，值的范围-440至440）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * resetGyro();
 * 功能：重置陀螺仪的值，使当前值为0.
 */
