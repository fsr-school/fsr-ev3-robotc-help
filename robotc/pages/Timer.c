task main()
{
    //  计时器模块

    //------------------------------------------

    // 定义阀值为600
    int threshold = 20;
    // 重置计时器T1以从0开始计数
    clearTimer(T1);
    // 定时器T1计数少于10秒时循环代码
    while (time1[T1] < 10000)
    {
        // 如果获取的颜色值小于阀值
        if (SensorValue(S1) < threshold)
        {

            displayBigTextLine(3, "SensorValue:%d", SensorValue(S1));
            // 向右转弯
            // 设置A电机功率为50
            setMotorSpeed(MotorA, 50);
            //设置B电机功率为0
            setMotorSpeed(MotorB, 0);
        }
        else
        {
            displayBigTextLine(3, "SensorValue:%d", SensorValue(S1));
            // 向左转弯
            // 设置电机A的功率为0
            setMotorSpeed(MotorA, 0);
            //设置电机B的功率为50
            setMotorSpeed(MotorB, 50);
        }
    }

    //------------------------------------------

    // 电机A的功率为50，旋转度数为50度
    moveMotorTarget(motorA, 1000, 50);
    waitUntilMotorStop(motorA);
    // 程序将等待1秒，然后继续下一行代码,此处也可以用wait1MSec(2000);和 sleep(2000);
    delay(2000);
    // wait1MSec(2000);
    // sleep(2000);
    moveMotorTarget(motorA, 1000, 50);
    waitUntilMotorStop(motorA);
}

/**
 * clearTimer(theTimer);
 * 功能：清除计时器,将指定计时器重置为0
 * 参数1：theTimer 可指定四个定时器 T1 T2 T3 T4
 */

/**
 * delay(nMSec);
 * 功能：程序等待指定的时间
 * 参数1：nMSec 等待的毫秒数
 */

/**
 * wait1MSec(nMSec);
 * 功能：程序等待指定的时间
 * 参数1：nMSec 等待的毫秒数
 */

/**
 * sleep(nMSec);
 * 功能：程序等待指定的时间
 * 参数1：nMSec 等待的毫秒数
 */