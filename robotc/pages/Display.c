task main()
{
    //  显示模块
    // TODO 没找到图片显示
    // 按行显示的索引为0--14，每一行的高度为5号字的高度，16像素占两行
    // 按坐标显示是从EV3屏幕左下角为圆点，x值范围0--177,y值范围为0--127

    // 清除屏幕
    eraseDisplay();

    //在xy坐标是（0，16）的位置显示16像素2号字符Robot
    displayBigStringAt(0, 16, "1-Robot");

    //在xy坐标是（0，32）的位置显示5号字符Robot
    displayStringAt(0, 32, "2-Robot");

    //在第1行最左边显示16像素2号字符 Robot
    displayBigTextLine(0, "3-Robot");

    //在第3行最左边显示5号字符Robot
    displayTextLine(2, "4-Robot");

    // TODO displayString 与 displayTextLine 的区别是什么？
    //显示屏上第4行显示5号字符Robot
    displayString(3, "5-Robot");

    //在第5行中间显示16像素2号字符Robot
    displayCenteredBigTextLine(4, "6-Robot");

    // 在第7行中间显示5号字符Robot
    displayCenteredTextLine(6, "7-Robot");

    //在x，y坐标(90,16)显示背景为黑色，字为白色的16像素字符Robot
    displayInverseBigStringAt(90, 16, "8-Robot");

    //在x，y坐标(90,16)的位置显示背景为黑，字为白的5号字符Robot
    displayInverseStringAt(90, 32, "9-Robot");

    // 在第8行上显示背景为黑色，字为白色的5号字符Robot
    displayInverseString(7, "10-Robot");

    //以上程序执行等待时间为10000毫秒
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //绘制圆或椭圆(Left, Top, Right, Bottom);
    drawEllipse(10, 40, 100, 15);
    sleep(1000);
    //删除椭圆
    eraseEllipse(10, 40, 100, 15);
    //以上程序执行等待时间为1000毫秒
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //绘制线段(xPos, yPos, xPosTo, yPosTo);
    drawLine(10, 100, 100, 10);
    sleep(1000);
    //删除线段
    eraseLine(10, 100, 100, 10);
    //等待时间为1000毫秒
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //绘制矩形(Left, Top, Right, Bottom);
    drawRect(10, 40, 100, 15);
    sleep(1000);
    //删除EV3 LCD屏幕上的矩形
    eraseRect(10, 40, 100, 15);
    //等待时间为1000毫秒
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //填充黑色的椭圆(Left, Top, Right, Bottom);
    fillEllipse(10, 40, 100, 15);
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //填充黑色的矩形，以下参数为左，上，右，下
    fillRect(10, 40, 100, 15);
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //在当前x，y坐标处设置像素
    setPixel(10, 20);
    sleep(1000);
    //检查10，20坐标处是否有像素
    getPixel(10, 20);
    sleep(1000);
    //在5，10的坐标上反转像素，也就是说在下面这个坐标处如果设置的有像素，那么就显示没有，如果没有像素就设置有像素
    invertPixel(5, 10);
    sleep(1000);

    // 清除屏幕
    eraseDisplay();
    //反转EV3 LCD屏幕上的两条对角线
    //形成“X”形
    invertLine(10, 10, 100, 100);
    invertLine(10, 100, 100, 10);
    sleep(3000);
    //反转EV3 LCD屏幕上的两条对角线
    //清除了“X”形
    invertLine(10, 10, 100, 100);
    invertLine(10, 100, 100, 10);
    sleep(3000);

    // -----利用形状画一个机器人头像-------

    //矩形的脸，绘制矩形(Left, Top, Right, Bottom);
    drawRect(40, 120, 140, 20);
    //矩形的嘴，绘制填充的矩形
    fillRect(70, 45, 110, 30);

    //绘制左眼，绘制椭圆(Left, Top, Right, Bottom);
    drawEllipse(50, 110, 80, 80);
    // 绘制左眼眼球，绘制填充的椭圆
    fillEllipse(60, 100, 70, 90);
    //绘制右眼;
    drawEllipse(100, 110, 130, 80);
    // 绘制右眼眼球，绘制填充的椭圆
    fillEllipse(110, 100, 120, 90);

    // 绘制三角形的鼻子，底边，绘制线段（xPos, yPos, xPosTo, yPosTo）
    drawLine(80, 60, 100, 60);
    // 绘制三角形的鼻子，左边线
    drawLine(80, 60, 90, 70);
    // 绘制三角形的鼻子，左边线
    drawLine(100, 60, 90, 70);

    // 机器人左耳朵
    drawLine(25, 70, 25, 100);
    drawLine(25, 70, 40, 70);
    drawLine(25, 100, 40, 100);
    // 机器人右耳朵
    drawLine(155, 70, 155, 100);
    drawLine(140, 70, 155, 70);
    drawLine(140, 100, 155, 100);
    //以上程序执行等待时间为50000毫秒
    sleep(50000);

    // ------------------------------
}

/**
 * eraseDisplay();
 * 功能：清除屏幕
 */

/**
 * displayBigStringAt (xPos, yPos, sFormatString);
 * 功能：坐标显示16像素2号字符
 * 参数1：xPos,int x坐标
 * 参数2：yPos,int y坐标
 * 参数3：sFormatString,string  要显示的字符内容
 */

/**
 * displayStringAt (xPos, yPos, sFormatString);
 * 功能：坐标显示5号字符
 * 参数1：xPos,int x坐标
 * 参数2：yPos,int y坐标
 * 参数3：sFormatString,string  要显示的字符内容
 */

/**
 * displayBigTextLine (nLineNumber,sFormatString);
 * 功能：按行显示16像素2号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * displayTextLine (nLineNumber,sFormatString);
 * 功能：按行显示5号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * displayString (nLineNumber,sFormatString);
 * 功能：按行显示5号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * displayCenteredBigTextLine (nLineNumber,sFormatString);
 * 功能：按行居中显示16像素2号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * displayCenteredTextLine (nLineNumber,sFormatString);
 * 功能：按行居中显示5号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * displayInverseBigStringAt (xPos, yPos, sFormatString);
 * 功能：坐标显示背景色为黑色，字体为白色的16像素2号字符
 * 参数1：xPos,int x坐标
 * 参数2：yPos,int y坐标
 * 参数3：sFormatString,string  要显示的字符内容
 */

/**
 * displayInverseStringAt (xPos, yPos, sFormatString);
 * 功能：坐标显示背景色为黑色，字体为白色的5号字符
 * 参数1：xPos,int x坐标
 * 参数2：yPos,int y坐标
 * 参数3：sFormatString,string  要显示的字符内容
 */

/**
 * displayInverseString (nLineNumber,sFormatString);
 * 功能：按行显示背景色为黑色，字体为白色的5号字符
 * 参数1：nLineNumber,int 行数
 * 参数2：sFormatString,string  要显示的字符内容
 */

/**
 * drawEllipse (Left, Top, Right, Bottom);
 * 功能：绘制椭圆
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * eraseEllipse (Left, Top, Right, Bottom);
 * 功能：删除椭圆
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * drawLine (xPos, yPos, xPosTo, yPosTo);
 * 功能：绘制线段
 * 参数1：xPos,int 起点x坐标
 * 参数2：yPos,int 起点y坐标
 * 参数3：xPosTo,int 终点x坐标 
 * 参数4：yPosTo,int 终点y坐标
 */

/**
 * eraseLine (xPos, yPos, xPosTo, yPosTo);
 * 功能：绘制线段
 * 参数1：xPos,int 起点x坐标
 * 参数2：yPos,int 起点y坐标
 * 参数3：xPosTo,int 终点x坐标 
 * 参数4：yPosTo,int 终点y坐标
 */

/**
 * drawRect (Left, Top, Right, Bottom);
 * 功能：绘制矩形
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * eraseRect (Left, Top, Right, Bottom);
 * 功能：删除矩形
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * fillEllipse (Left, Top, Right, Bottom);
 * 功能：绘制填充的黑色椭圆
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * fillRect (Left, Top, Right, Bottom);
 * 功能：绘制填充的黑色矩形
 * 参数1：Left,int 左边x坐标
 * 参数2：Top,int 上边y坐标
 * 参数3：Right,int 右边x坐标 
 * 参数4：Right,int 下边y坐标
 */

/**
 * setPixel (x, y);
 * 功能：在坐标处设置像素
 * 参数1：x,int x坐标
 * 参数2：y,int y坐标
 */

/**
 * getPixel (x, y);
 * 功能：在坐标处获取像素
 * 参数1：x,int x坐标
 * 参数2：y,int y坐标
 */

/**
 * invertPixel (x, y);
 * 功能：反转坐标处的像素，黑白转换颜色，在同一坐标处第一次用时是黑色，第二次为白色
 * 参数1：x,int x坐标
 * 参数2：y,int y坐标
 */

/**
 * invertLine (xPos, yPos, xPosTo, yPosTo);
 * 功能：将线段黑白转换颜色，在同一坐标处第一次用时是黑色，第二次为白色
 * 参数1：xPos,int 起点x坐标
 * 参数2：yPos,int 起点y坐标
 * 参数3：xPosTo,int 终点x坐标 
 * 参数4：yPosTo,int 终点y坐标
 */