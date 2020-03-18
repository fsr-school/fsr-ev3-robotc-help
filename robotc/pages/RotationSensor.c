task main()
{
    // 电机旋转模块

    // --------------------------------

    // 重置A电机为0
    resetMotorEncoder(motorA);
    // 功率为50时，将A电机的目标度数设置为1000
    setMotorTarget(motorA, 1000, 50);
    // 循环直到当前编码器计数等于目标计数
    repeatUntil(getMotorEncoder(motorA) == getMotorTarget(motorA))
    {
        //清除EV3的LCD显示屏
        eraseDisplay();
        //在第2行显示电机A的目标编码器值
        displayTextLine(2, "%d", getMotorTarget(motorA));
        //在第4行显示马达A的当前编码器值
        displayTextLine(4, "%d", getMotorEncoder(motorA));
        //等待50毫秒
        sleep(50);
    }

    // --------------------------------

    // 设置初始速度为0
    int speed = 0;
    //无限循环
    while (true)
    {
        //获取A电机每分钟的功率，如果A电机功率低于目标值100
        if (getMotorRPM(MotorA) < 100)
        {
            // 速度值就加1
            speed = speed + 1;
            //等待2毫秒
            sleep(2);
        }
        //将功率值用到A电机和B电机，速度会加速
        setMotorSpeed(MotorA, speed);
        setMotorSpeed(MotorB, speed);
    }

    // --------------------------------

    //创建当前速度变量
    int currentSpeed;
    //将A马达设置的功率设置为50
    setMotorSpeed(motorA, 50);
    //将马达A的速度存储为当前速度
    currentSpeed = getMotorSpeed(motorA);
    // 将当前功率设置给B电机
    setMotorSpeed(motorB, currentSpeed);
    // 等待3000毫秒
    sleep(3000);

    // --------------------------------

    //将A端口的马达设置50功率，旋转度数为1000
    moveMotorTarget(motorA, 1000, 50);
    // 循环直到获取到A马达的状态为停止
    repeatUntil(getMotorMoving(motorA) == 0);
    {
        //  B电机以50功率旋转1000度
        moveMotorTarget(motorB, 1000, 50);
        // 等待B电机停止
        waitUntilMotorStop(motorB);
    }

    // --------------------------------

    // 如果获取A电机不是滑行模式
    if (getMotorBrakeMode(motorA) != motorCoast)
    {
        // 设置A电机为滑行模式 motorCoast电机滑行
        setMotorBrakeMode(motorA, motorCoast);
        // 设置电机是10功率，顺时针旋转360度
        setMotorTarget(motorA, 360, 10);
        // 等待A电机完成动作，电机停止时应该是滑行状态
        waitUntilMotorStop(motorA);
        // 等待1000毫秒
        sleep(1000);
    }
    // 如果获取A电机不是制动模式，设置A电机为制动模式  motorBrake电机制动
    else if (getMotorBrakeMode(motorA) != motorBrake)
    {
        // 设置A电机为制动模式 motorCoast电机制动
        setMotorBrakeMode(motorA, motorBrake);
        // 设置电机是10功率，顺时针旋转360度
        setMotorTarget(motorA, 360, 10);
        // 等待A电机完成动作，电机停止时应该是制动状态
        waitUntilMotorStop(motorA);
        // 等待1000毫秒
        sleep(1000);
    }

    // --------------------------------

    //重置A马达为0
    resetMotorEncoder(motorA);
    //在EV3显示器第二行显示A马达的当前值
    displayTextLine(2, "%d", getMotorEncoder(motorA));
    //等待2000毫秒
    sleep(2000);

    // --------------------------------
}

/**
 * getMotorEncoder(nMotorIndex);
 * 功能：获取电机当前度数。值 = int
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * getMotorTarget(nMotorIndex);
 * 功能：获取电机目标度数。值 = int
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * getMotorRPM(nMotorIndex);
 * 功能：获取电机每分钟功率值，每秒获取10次值。值 = int
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * getMotorSpeed(nMotorIndex);
 * 功能：获取电机功率值。值 = -100至100
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * getMotorMoving(nMotorIndex);
 * 功能：获取电机是否转动。值 = bool ，0为停止，1为转动。
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * getMotorBrakeMode(nMotorIndex);
 * 功能：获取电机停止时是否制动。值=motorCoast(电机滑行) / motorBrake(电机制动)
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * resetMotorEncoder(nMotorIndex);
 * 功能：重置电机为0
 * 参数1：nMotorIndex 电机的名称或端口
 */
