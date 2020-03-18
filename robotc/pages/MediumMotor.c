
task main()
{
    // 中型电机，电机端口和控制模式

    // --------------------------------

    // 设定电机A端口的速度为100
    setMotorSpeed(0, 100);
    // TODO 电机停止时是否制动，ture 为不制动，false 为制动 -------未验证
    bFloatDuringInactiveMotorPWM = false;
    // 暂停程序1000毫秒（1秒）
    sleep(1000);

    // --------------------------------

    // 设置电机功率为50，电机顺时针旋转至1000度
    setMotorTarget(motorA, 1000, 50);
    // 等待A电机停止
    waitUntilMotorStop(motorA);
    // 电机以50功率旋转至目标值1200度，这时旋转200度
    setMotorTarget(motorA, 1200, 50);
    // 等待A电机停止
    waitUntilMotorStop(motorA);

    // --------------------------------

    // A电机顺时针转动600度
    moveMotorTarget(motorA, -600, 50);
    waitUntilMotorStop(motorA);
    // A电机顺时针转动720度
    moveMotorTarget(motorA, 720, 50);
    waitUntilMotorStop(motorA);

    // --------------------------------

    //TODO 将左马达设置为传动的左侧 程序无法执行
    nMotorDriveSide[leftMotor] = driveLeft;
    //机器人应按50功率向前移动一圈
    forward(1, rotation, 50);
    //将左马达设置到传动系的右侧
    nMotorDriveSide[leftMotor] = driveRight;
    //机器人应按50功率向前移动一圈
    forward(1, rotation, 50);

    // --------------------------------

    //设置A电机反转
    setMotorReversed(motorA, true);
    //设置A电机以50功率逆时针旋转
    setMotorSpeed(motorA, 50);
    sleep(1000);
    waitUntilMotorStop(motorA);
    //设置A电机不反转
    setMotorReversed(motorA, false);
    //设置A电机以50功率顺时针旋转
    setMotorSpeed(motorA, 50);
    sleep(1000);
    waitUntilMotorStop(motorA);
}
}

/**
 * nMotorIndex 电机的名称或端口索引
 * A端口：motorA （0）
 * A端口：motorB （1）
 * A端口：motorC （2）
 * A端口：motorD （3）
 */

/**
 * setMotorSpeed(nMotorIndex, nSpeed);
 * 功能：开启电机。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：nSpeed 功率，速度
 */

/**
 * setMotorTarget(nMotorIndex, nPosition, nSpeed);
 * 功能：开启电机旋转至指定度数，当重置电机后，指定一个度数，电机旋转度数=第一次指定度数；第二次再设定度数，电机旋转的度数 = 是第二次 - 第一次的度数。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：nPosition 旋转度数（绝对值）
 * 参数2：nSpeed 功率，速度
 */

/**
 * waitUntilMotorStop(nMotorIndex);
 * 功能：等待电机停止。
 * 参数1：nMotorIndex 电机的名称或端口
 */

/**
 * moveMotorTarget(nMotorIndex, nPosition, nSpeed);
 * 功能：开启电机指定度数。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：nPosition 旋转度数（正负数都可以）
 * 参数2：nSpeed 功率，速度
 */

/**
 * bFloatDuringInactiveMotorPWM = ture / false;
 * 功能：电机停止时是否制动。
 * ture （1）不制动
 * false (0) 制动
 */

/**
 * setMotorBrakeMode(nMotorIndex, modeSetting);
 * 功能：设置指定的电机设置停止模式。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：modeSetting 电机停止的模式  motorCoast电机滑行  motorBrake电机制动
 */


/**
 * setMotorReversed(nMotorIndex, bReversed);
 * 功能：设置指定的电机正反转。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：bReversed bool ture反转，fals正转
 */
