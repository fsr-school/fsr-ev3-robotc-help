
task main()
{
    //  反转电机

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

/**
 * setMotorReversed(nMotorIndex, bReversed);
 * 功能：设置指定的电机正反转。
 * 参数1：nMotorIndex 电机的名称或端口
 * 参数2：bReversed bool ture反转，fals正转
 */
