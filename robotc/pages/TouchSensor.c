task main()
{
    //  触动传感器模块
    // -----------------------------------------------------------
    // 重置触碰感应器的值
    resetBumpedValue(S1);
    // 检测按10次
    repeatUntil(getBumpedValue(S1) == 10)
    {
        // 按10次后会发出 soundBeepBeep 声音
        playSound(soundBeepBeep);
    }

    // -----------------------------------------------------------

    // 以下程序是机器人以50功率的速度前进，直到按下“触摸传感器”机器人停止前进
    // 重复循环，直到按下触摸传感器为止（返回值1）
    repeatUntil(getTouchValue(S1) == 1)
    {
        // 显示传感器的值
        displayBigTextLine(3, "%d", SensorValue(S1));
        // 设置A电机和B电机以50功率前进
        setMotorSpeed(motorA, 50);
        setMotorSpeed(motorB, 50);
    }
    // 停止AB电机
    setMotorSpeed(motorA, 0);
    setMotorSpeed(motorB, 0);
}

/**
 * getBumpedValue(nDeviceIndex);
 * 功能：获得碰撞次数值 
 * 参数1：传感器的端口或名称
 */

/**
 * resetBumpedValue(nDeviceIndex);
 * 功能：重置触碰感应器的值 
 * 参数1：传感器的端口或名称
 */

/**
 * getTouchValue(nDeviceIndex);
 * 功能：获取触摸值，按下返回1，松开返回0 
 * 参数1：传感器的端口或名称
 */

/**
 * SensorValue(nDeviceIndex);
 * 功能：传感器的值，返回相应的传感器的值
 * 参数1：传感器的端口或名称
 */