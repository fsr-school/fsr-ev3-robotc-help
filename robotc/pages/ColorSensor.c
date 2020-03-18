task main()
{
    //  颜色传感器模块

    // -------------------------------------------

    //将颜色传感器设置为端口3
    int threshold = 50; /* 取暗和明的值相加除以2   */
    while (true)
    {
        // 如果颜色传感器感测到环境光线强度低于阀值
        if (getColorAmbient(S3) < threshold)
        {
            // 将颜色传感器检测的值显示在EV3的第四行
            displayBigTextLine(3, "%d", getColorAmbient(S3));
            // 将A电机设置功率为50
            setMotorSpeed(motorA, 50);
            //将B电机设置功率为0
            setMotorSpeed(motorB, 0);
        }
        //否则如果颜色传感器感测到光线强度高于阀值50
        else
        {
            // 将C电机设置功率为0
            setMotorSpeed(motorA, 0);
            //将B电机设置功率为50
            setMotorSpeed(motorB, 50);
        }
    }

    // -------------------------------------------

    // TODO getColorHue自己写的测试例子，好像测时有问题
    // 将颜色传感器检测到的颜色值放在EV3显示器的第四行
    displayBigTextLine(3, "%d", getColorHue(S3));
    while (true)
    {
        // 如果获取的颜色色相值小于100
        if (getColorHue(S3) < 100)
        {
            // 播放 soundBeepBeep 声音
            playSound(soundBeepBeep);
            // A电机不动
            setMotorSpeed(motorA, 0);
        }
        else
        {
            // 否则清除声音
            clearSounds();
            // A电机以10功率的速度旋转
            setMotorSpeed(motorA, 10);
        }
    }

    // -------------------------------------------

    //一直循环
    repeat(forever)
    {
        // 将插入端口3的颜色传感器返回彩色名称
        if (getColorName(S3) == colorRed)
        {
            //将RED显示在EV3的第3行
            displayBigTextLine(3, "RED");
        }
        // 如果检测颜色感应器检测到的是蓝色
        else if (getColorName(S3) == colorBlue)
        {
            // 将BLUE显示在EV3的第3行
            displayBigTextLine(3, "BLUE");
        }
        else if (getColorName(S3) == colorGreen)
        {
            // 将Green显示在EV3的第3行
            displayBigTextLine(3, "Green");
        }
        else if (getColorName(S3) == colorYellow)
        {
            // 将Yellow显示在EV3的第3行
            displayBigTextLine(3, "Yellow");
        }
    }

    // -------------------------------------------

    //创建变量存储红色、绿色和蓝色值
    long redValue;
    long greenValue;
    long blueValue;
    while (true)
    {
        // 获取颜色传感器三个通道的值，并储存在变量中
        getColorRGB(S3, redValue, greenValue, blueValue);
        // 红色值显示在ev3的第四行
        displayBigTextLine(3, "%d", redValue);
        // 绿色值显示在ev3的第六行
        displayBigTextLine(5, "%d", greenValue);
        // 蓝色值显示在ev3的第8行
        displayBigTextLine(7, "%d", blueValue);
    }

    // -------------------------------------------

    // TODO getColorSaturation 注：经测试显示的饱合值与测试行为不一致，单电机测试报错，必须双电机
    repeat(forever)
    {
        // 如果颜色饱合度值大于50
        if (getColorSaturation(S3) > 50)
        {
            // 显示颜色饱合度值在第四行。
            displayBigTextLine(3, "%d", getColorSaturation(S3));
            //设置A、B电机的功率为10
            setMotorSpeed(motorA, 10);
            setMotorSpeed(motorB, 10);
        }
        else
        {
            //否则A、B电机的功率为0
            setMotorSpeed(motorA, 0);
            setMotorSpeed(motorB, 0);
        }
    }

    // -------------------------------------------

    // TODO getColorReflected 注：晚上灯光下测试时检测白色时值是四十多，但是实现的是B电机旋转，A电机不转，不清楚是不是显示值不准
    // 定义阀值为50
    int threshold = 50;
    //一直循环
    while (true)
    {
        // 如果传感器感应到线条，值低于50
        if (getColorReflected(S3) < threshold)
        {
            displayBigTextLine(5, "%d", getColorReflected(S3));
            // 设置A电机以20功率旋转
            setMotorSpeed(motorA, 20);
            // 设置B电机的功率为0
            setMotorSpeed(motorB, 0);
        }
        // 否则，检测到的值高于50的话
        else
        {
            // 设置A电机为0功率
            setMotorSpeed(motorA, 0);
            // 设置B电机的功率为20
            setMotorSpeed(motorB, 20);
            // 重置传感器，此时颜色传感器重置为反射模式
            sensorReset(S3)
        }
    }

    // -------------------------------------------

    // 将传感器端口1设置为触摸传感器更改此分配以更改传感器的类型
    SensorType[s1] = sensorEV3_Color;
    //无限循环
    while (true)
    {
        // TODO sensorRaw 显示传感器的原始值 没有理解
        displayCenteredTextLine(1, "Sensor Value: %d", sensorRaw[S1]);
        // 显示  "Sensor Value: ##"的值
        displayCenteredTextLine(3, "Sensor Value: %d", sensorValue[S1]);
        // 等待100毫秒以帮助正确显示
        wait1Msec(100);
        //删除显示
        eraseDisplay();
    }
}

/**
 * getColorAmbient(nDeviceIndex);
 * 功能：红色灯熄灭获取光线强度值，光线为蓝色光（深0-100浅）
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * getColorHue(nDeviceIndex);
 * 功能：获取颜色色相值，也就是色谱图上的值（0-360）
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * getColorName(nDeviceIndex);
 * 功能：获取颜色名称（共8种）
 * colorNone:0    	colorBlack:1 	 
 * colorBlue: 2	    colorGreen：3 
 * colorYellow：4  	colorRed：5	  
 * colorWhite: 6    colorBrown：7
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * getColorRGB(nDeviceIndex,&pRedChannel,&pGreenChannel,&pBlueChannel);
 * 功能：获取红绿蓝颜色值（每个颜色通道值为0-255）
 * 参数1：nDeviceIndex 传感器端口或名称
 * 参数2：&pRedChannel redValue红色值
 * 参数3：&pGreenChannel greenValue绿色值
 * 参数4：&pBlueChannel blueValue蓝色值
 */

/**
 * getColorSaturation(nDeviceIndex);
 * 功能：获取颜色饱合度（低0-100高）
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * getColorReflected(nDeviceIndex);
 * 功能： 亮红色灯获取反射光（深0-100浅）
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * SensorType[nDeviceIndex] = Range of Values(传感器类型);  TODO 没有写入代码片段
 * 功能： 返回传感器类型（不同的传感器设置不同的类型，设置类型如下）
 *       sensorEV3_Touch：EV3触摸传感器
 *       sensorEV3_Color：EV3颜色传感器
 *       sensorEV3_Ultrasonic：EV3超声波传感器
 *       sensorEV3_Gyro：EV3陀螺仪传感器
 *       sensorEV3_IRSensor：EV3红外传感器
 *       sensorEV3_EnergyMeter：EV3电能表
 *       sensorEV3_GenericI2C：通用I2C设备
 * 参数1：nDeviceIndex 传感器端口或名称
 * 
 */

/**
 * sensorReset(nDeviceIndex);
 * 功能： 重置传感器（不同的传感器重置结果如下）
 *       陀螺仪传感器（GyroSensor）：将航向值重置为0
 *       触摸传感器(touchSensor)：将累积的撞击计数重置为0
 *       超声波（美国）传感器(ultrasonicSensor)：将传感器重置为距离CM模式
 *       红外（IR）传感器(infraredSensor)：将传感器重置为接近模式
 *       颜色传感器(colorSensor)：将传感器重置为反射模式
 * 参数1：nDeviceIndex 传感器端口或名称
 */

/**
 * SensorValue[nDeviceIndex]=value (传感器的值);  TODO 没有写入代码片段
 * 功能：返回相应的传感器的值
 * 参数1：传感器的端口或名称
 */

/**
 * sensorRaw[nDeviceIndex] = value (传感器的原始值); TODO 没有写入代码片段
 * 功能：返回相应的传感器的原始值
 * 参数1：传感器的端口或名称
 */