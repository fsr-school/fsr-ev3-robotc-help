task main()
{
    // 红外传感器

    // ----------------------------------------------------

    //无限循环
    while (true)
    {
        //获得红外信标在右侧
        if (getIRBeaconDirection(S4) > 5)
        {
            // displayBigTextLine(3, "%d", getIRBeaconDirection(S4));
            //向右转
            setMotorSpeed(MotorA, 50);
            setMotorSpeed(MotorB, -50);
        }
        //如果获得信标在左侧（负数为左边）
        else if (getIRBeaconDirection(S4) < -5)
        {
            // displayBigTextLine(3, "%d", getIRBeaconDirection(S4));
            //向左转
            setMotorSpeed(MotorA, -50);
            setMotorSpeed(MotorB, 50);
        }
        //否则直线行驶
        else
        {
            // displayBigTextLine(3, "%d", getIRBeaconDirection(S4));
            //Move Forward
            setMotorSpeed(MotorA, 50);
            setMotorSpeed(MotorB, 50);
        }
    }

    // ----------------------------------------------------

    // 当获取红外信标的距离小于20时
    while (getIRBeaconStrength(S4) < 20)
    {
        // 显示信标距离值
        displayBigTextLine(3, "%d", getIRBeaconStrength(S4));
        //设置电机A功率为50，B电机的功率为-50，机器人向右转
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, -50);
    }

    // ----------------------------------------------------

    // 当红外传感器返回值大于20时
    while (getIRDistance(S4) > 20)
    {
        displayBigTextLine(3, "%d", getIRDistance(S4));
        // 机器人向前直线行驶
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, 50);
    }
    // 否则停止前进
    setMotorSpeed(MotorA, 0);
    setMotorSpeed(MotorB, 0);

    // ----------------------------------------------------

    // TODO getIRRemoteButtons 未能验证 当按下红外遥控器的蓝色向上按钮时
    while (getIRRemoteButtons(S4) == 3)
    {
        //电机A和B旋转，机器人前进
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, 50);
    }

    // ----------------------------------------------------

    // TODO getIRRemoteChannelButtons 信标为通道1，当按下红外遥控器的蓝色向上按钮时
    while (getIRRemoteChannelButtons(S4, 1) == 3)
    {
        //电机A和B旋转，机器人前进
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, 50);
    }
}

/**
 * getIRBeaconDirection(nDeviceIndex);
 * 功能：获取红外方向（使用信标1通道，值范围-25至25，顺为正，逆为负）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getIRBeaconStrength(nDeviceIndex);
 * 功能：获取红外信标强度（信标通道1，值范围 近0至100远）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getIRDistance(nDeviceIndex);
 * 功能：获取红外线传感器的距离（值范围 近0至100远，返回100，说明没有检测到任何东西）
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getIRRemoteButtons(nDeviceIndex);
 * 功能：获取红外遥控按钮
 * 按钮对应数字：
 *  0= No Button Pressed 没按按钮
 *  1=	Red Up 红上
 *  2=	Red Down 红下
 *  3=	Blue Up 蓝上
 *  4=	Blue Down 蓝下
 *  5=	Red Up and Blue Up 红上和蓝上
 *  6=	Red Up and Blue Down 红上和蓝下
 *  7=	Red Down and Blue Up 红下和蓝上
 *  8=	Red Down and Blue Down 红下和蓝下
 *  9=	Beacon Mode On 信标模式按钮
 *  10=	Red Up and Red Down 红上和红下
 *  11=	Blue Up and Blue Down 蓝上和蓝下
 * 参数1：nDeviceIndex 传感器的名称或端口
 */

/**
 * getIRRemoteChannelButtons(nDeviceIndex, nChannel);
 * 功能：获取红外遥控频道按钮
 * 按钮对应数字：
 *  0= No Button Pressed 没按按钮
 *  1=	Red Up 红上
 *  2=	Red Down 红下
 *  3=	Blue Up 蓝上
 *  4=	Blue Down 蓝下
 *  5=	Red Up and Blue Up 红上和蓝上
 *  6=	Red Up and Blue Down 红上和蓝下
 *  7=	Red Down and Blue Up 红下和蓝上
 *  8=	Red Down and Blue Down 红下和蓝下
 *  9=	Beacon Mode On 信标模式按钮
 *  10=	Red Up and Red Down 红上和红下
 *  11=	Blue Up and Blue Down 蓝上和蓝下
 * 参数1：nDeviceIndex 传感器的名称或端口
 * 参数2：nChannel 遥控频道（1-4）
 */
