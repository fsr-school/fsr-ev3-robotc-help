task main()
{
    // 程序块按钮模块

    // -----------------------------------------------------------
    while (true)
    {
        // 当左按钮（5）是按下时
        if (getButtonPress(buttonLeft) == 1)
        {
            // 在第2行显示 buttonLeft：5
            displayBigTextLine(1, "buttonLeft:%d", 5);
            //电机A的功率为-50，逆时针旋转，B电机为50功率，顺时针旋转，机器人向左转
            setMotorSpeed(MotorA, -50);
            setMotorSpeed(MotorB, 50);
        }
        // 当右按钮（4）是按下时
        else if (getButtonPress(buttonRight) == 1)
        {
            // 在第4行显示 buttonRight：4
            displayBigTextLine(3, "buttonRight:%d", 4);
            //电机A和电机B停止
            setMotorSpeed(MotorA, 0);
            setMotorSpeed(MotorB, 0);
        }
        // 当下按钮（3）是按下时
        else if (getButtonPress(buttonDown) == 1)
        {
            // 在第6行显示 buttonDown：3
            displayBigTextLine(5, "buttonDown:%d", 3);
        }
    }

    // -----------------------------------------------------------

    //阻止后退按钮退出程序，如不阻止，将1改为0
    setBlockBackButton(1);
    //无限循环
    while (true)
    {
    }

    // ------------------------------------------------------------

    //停止电机
    setMotorSpeed(MotorA, 0);
    setMotorSpeed(MotorB, 0);
    //等待在EV3上按下（任意）按钮
    waitForButtonPress();
    //电机以50功率旋转
    setMotorSpeed(MotorA, 50);
    setMotorSpeed(MotorB, 50);
    //等待3000毫秒
    sleep(3000);
}

/**
 * getButtonPress(button);
 * 功能：获取EV3上相应按钮是否按下
 * 参数1：button EV3上的按钮
 * EV3上的按钮如下：
 * buttonNone：无按钮（0）
 * buttonUp：向上按钮（1）
 * buttonEnter：中间按钮（2）
 * buttonDown：向下按钮（3）
 * buttonRight：右按钮（4）
 * buttonLeft：左按钮（5）
 * buttonBack：后退按钮（6）
 * buttonAny：任何按钮（7）
 */

/**
 * setBlockBackButton(bool);
 * 功能：设置阻止后退按钮
 * 参数1：bool 1为阻止， 0为不阻止
 */

/**
 * waitForButtonPress();
 * 功能：等待按下按钮（任意，除返回键）
 */

