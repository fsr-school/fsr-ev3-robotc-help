# Motors
#### bFloatDuringInactiveMotorPWM 电机停止是否制动
```c
	// 断电时马达会滑行
	bFloatDuringInactiveMotorPWM = true; 
	// 断电时马达会制动
	 bFloatDuringInactiveMotorPWM = false;  

getMotorBrakeMode 获取电机制动模式
// 如果获取A电机不是滑行模式，设置A电机为滑行模式 motorCoast电机滑行
if(getMotorBrakeMode(motorA) != motorCoast)
    {
        setMotorBrakeMode(motorA, motorCoast);
    }
// 如果获取A电机不是制动模式，设置A电机为制动模式  motorBrake电机制动
else if(getMotorBrakeMode(motorA) != motorBrake)
    {
        setMotorBrakeMode(motorA, motorBrake);
    }

getMotorEncoder   获取电机当前度数
// 重置A电机为0
resetMotorEncoder(motorA);
// 功率为50时，将A电机的目标度数设置为1000
setMotorTarget(motorA, 1000, 50);
// 循环直到当前编码器计数等于目标计数
repeatUntil(getMotorEncoder(motorA) == getMotorTarget(motorA))
    {
    
    }

getMotorRPM 获取发动机转速既功率 （每分种的转速值，每秒采样10次）
// 设置初始速度为0
    int speed = 0;
//无限循环
while (true)
{
    //获取A电机的转速，如果A边电机转速低于目标值100
    if (getMotorRPM(MotorA) < 100)
    {
        // 速度值就加1
        speed = speed + 1;
        //等待2毫秒
        sleep(2);
    }
    //将速度值用到A电机和B电机，速度会加速
    setMotorSpeed(MotorA, speed);
    setMotorSpeed(MotorB, speed);
}

getMotorRunning 获取电机状态，是否旋转（返回bool值）
	//将A端口的马达设置50功率，旋转度数为1000
	moveMotorTarget(motorA, 1000, 50);
	// 循环直到马达停止移动
	repeatUntil(getMotorMoving(motorA) == 0);
		{
	//Do nothing (idle loop)
		}

getMotorSpeed  获取电机速度/功率
	//创建当前速度变量
	int currentSpeed;
	//将A马达设置的功率设置为50
	setMotorSpeed(motorA, 50);
	//将马达A的速度存储为当前速度
	currentSpeed = getMotorSpeed(motorA);
	// 等待3000毫秒
	sleep(3000);
	//将A马达的功率设置为100
	setMotorSpeed(motorA, 100);
	//将马达A的速度存储为当前速度
	currentSpeed = getMotorSpeed(motorA);
	//等待3000毫秒
	sleep(3000);

getMotorTarget 设置电机运动目标值
  // 重置马达A的编码器计数为0
 resetMotorEncoder(motorA);
 // 设置马达A功率为50时，移动至1000度
 moveMotorTarget(motorA, 1000, 50); 
 //循环直到当前编码器计数等于目标计数
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

  moveMotorTarget   马达移动至目标 （测试目标度数为负数，功率为正数，电机还是顺时针转，如果功率设置为负数，电机转）     
// 将A马达以100功率移动至1000度
moveMotorTarget(motorA, 1000, 100); 
// 等待A电机执行完以上的命令
waitUntilMotorStop(motorA);
//将A马达以负功率50逆时针旋转600度
moveMotorTarget(motorA, -600, -50);
//将A马达以功率50顺时针旋转720度
moveMotorTarget(motorA, 720, 50);
//等待A电机执行完以上的命令
waitUntilMotorStop(motorA);   

nMotorDriveSide 设置哪边的马达为驱动侧
	//将左马达设置为传动的左侧
	nMotorDriveSide[leftMotor] = driveLeft;
	//机器人应按50功率向前移动一圈
	forward(1, rotation, 50);
	//将左马达设置到传动系的右侧
	nMotorDriveSide[leftMotor] = driveRight;
	//机器人应按50功率向前移动一圈
	forward(1, rotation, 50);

resetMotorEncoder 重置电机数值为0
//重置A马达为0
resetMotorEncoder(motorA);
//在EV3显示器第二行显示A马达的当前值
displayTextLine(2, "%d", getMotorEncoder(motorA));
//等待2000毫秒
sleep(2000); 

setMotorBrakeMode 设置电机制动模式
	//设置发动机为滑行
	setMotorBrakeMode(motorA, motorCoast);
	//设置电机A在为0功率时旋转目标至360度
	setMotorTarget(motorA, 360, 0); 
	//等待马达达到目标并停止
	waitUntilMotorStop(motorA);
	//等待1000毫秒
	sleep(1000);
	//将马达重置为0
	resetMotorEncoder(motorA);
	//设置电机为制动
	setMotorBrakeMode(motorA, motorBrake);
	//设置电机A在为0功率时旋转目标至360度
	setMotorTarget(motorA, 360, 0); 
	//等待马达达到目标并停止
	waitUntilMotorStop(motorA);
	//等待1000毫秒
	sleep(1000);

setMotorReversed  设置电机反转
	//设置A电机反转
	setMotorReversed(motorA, true);
	//设置A电机以50功率逆时针旋转
	setMotorSpeed(motorA, 50);
	//设置A电机不反转
	setMotorReversed(motorA, false);
	//设置A电机以50功率顺时针旋转
	setMotorSpeed(motorA, 50);   

setMotorSpeed 设定车速 
	// 设置A马达的功率为100
 	setMotorSpeed(motorA, 100);
 	//等待1000毫秒
 	sleep(1000);
 	//设置A马达的功率为-50
 	setMotorSpeed(motorA, -50);
 	//等待1000毫秒
	 sleep(1000); 
 	// 设置A马达的功率为0
 	setMotorSpeed(motorA, 0);
 	//等待1000毫秒
	 sleep(1000);

setMotorSync 设置（两个）电机同步运行
	// 左右电机同步以60功率旋转
	setMotorSync(leftMotor, rightMotor, 0, 60);
	// 等待1000毫秒
	sleep(1000);
	//左电机以60功率旋转，右电机为0功率
	setMotorSync(leftMotor, rightMotor, 50, 60);
	sleep(1000);
	//左电机以60功率顺时针旋转，右电机以60功率逆时针旋转
	setMotorSync(leftMotor, rightMotor, 100, 60);
	sleep(1000);

setMotorSyncEncoder 设置（两个）电机同步编码器
	// 左右电机以50功率直线行走1000度
	setMotorSyncEncoder(left, right, 0, 1000, 50);
	sleep(1500);

	// 左电机以50功率顺时针旋转1000度，右电机以50功率逆时针旋转1000度
	setMotorSyncEncoder(left, right, 100, 1000, 50);
	sleep(1500);

	// 左电机以50功率逆时针旋转1000度，右电机以50功率顺时针旋转1000度
	setMotorSyncEncoder(left, right, -100, 1000, 50);
	sleep(1500);

	// 左电机以50功率顺时针旋转500度，右电机为0功率
	setMotorSyncEncoder(left, right, 50, 1200, 50);
	sleep(1500);

	// 右电机以50功率顺时针旋转500度，左电机为0功率
	setMotorSyncEncoder(left, right, -50, 500, 50);
	sleep(1500); 
 
setMotorSyncTime 设置双电机同步运行时间
	//  设置左右电机同步以50功率运行1000毫秒
	setMotorSyncTime(leftMotor, rightMotor, 0, 1000, 50);
	sleep(1500);

	// 设置左电机以50功率顺时针旋转1000毫秒，右电机以50功率逆时针旋转1000毫秒
	setMotorSyncTime(leftMotor, rightMotor, 100, 1000, 50);
	sleep(1500);
	// 设置左电机以50功率逆时针旋转1000毫秒，右电机以50功率顺时针旋转1000毫秒	setMotorSyncTime(leftMotor, rightMotor, -100, 1000, 50);
	sleep(1500);
	// 左电机以50功率顺时针旋转1000毫秒，右电机为0功率
	setMotorSyncTime(leftMotor, rightMotor, 50, 1000, 50);
	sleep(1500);
	// 右电机以50功率顺时针旋转1000毫秒，左电机为0功率
	setMotorSyncTime(leftMotor, rightMotor, -50, 1000, 50);
	sleep(1500);

setMotorTarget 设置电机旋转到目标度数（度数为绝对值），如下列 第一次设置的度数到达后，再设置第二次度数，那电机第二次旋转的度数就是第二数设置的减去第一次设置的度数
	//设置A电机以50功率旋转目标至绝对值1000度
 	setMotorTarget(motorA, 1000, 50);
 	//等待A电机动作停止
 	waitUntilMotorStop(motorA); 
 	//设置A电机以50功率旋转目标至绝对值1200度，电机旋转200度
 	setMotorTarget(motorA, 1200, 50); 
 	//等待A电机动作停止
 	waitUntilMotorStop(motorA);
 	//设置A电机以50功率旋转目标至绝对值800度，电机逆时针旋转400度 		   
	setMotorTarget(motorA, 800, 50);
 	//等待A电机动作停止
 	waitUntilMotorStop(motorA);

waitUntilMotorStop 等待电机停止
	//设置A电机以50功率旋转目标至绝对值1000度
	 setMotorTarget(motorA, 1000, 50);
 	//等待A电机动作停止
 	waitUntilMotorStop(motorA);
// =======================================================
# Sensors 传感器
## Color Sensors 颜色传感器
getColorAmbient 获取颜色环境光
//将颜色传感器设置为端口3
int threshold = 50;      /* 取暗和明的值相加除以2   */ 
while(true)
{
	// 如果颜色传感器感测到路线值低于阀值
	if(getColorAmbient(S3) < threshold)
	{
		// 将C电机设置功率为50
		setMotorSpeed(motorC, 50);
		 
		//将B电机设置功率为0
		setMotorSpeed(motorB, 0);
	}
	 
	//否则如果颜色传感器感测到路线值高于阀值50
	else
	{
		// 将C电机设置功率为0
		setMotorSpeed(motorC, 0);
		 
		//将B电机设置功率为50
		setMotorSpeed(motorB, 50);
	}
}
// ------------------------------------------------------------
getColorHue  获取颜色色调
//循环直到颜色传感器检测到蓝色（240）
repeatUntil(getColorHue(S2) == 240)
{
	//设置B电机和C电机B的功率为50
	setMotorSpeed(motorB, 50);
	setMotorSpeed(motorC, 50);
}
// 循环结束就停止电机
setMotorSpeed(motorB, 0);
setMotorSpeed(motorC, 0);
// ------------------------------------------------------------
getColorName 获取颜色名称（共8种，如果未检测到颜色，则返回colorNone）
colorNone:0    	colorBlack:1 	 colorBlue: 2	   colorGreen：3 
colorYellow：4 	colorRed：5	  colorWhite: 6   colorBrown：7
// 此程序将一直检测颜色传感器，并将它检测到颜色的名称存储在彩色
// 对象字符串
string colorOfObject;
//一直循环
repeat(forever)
{
	// 将插入端口3的颜色传感器返回彩色名称
	if(getColorName(S3) == colorRed)
	{
		//将红色存储到颜色字符串中
		colorOfObject = "RED";
	}
	// 如果检测颜色感应器检测到的是蓝色
	else if(getColorName(S3) == colorBlue)
	{
		// 将蓝色存储到颜色字符串中
		colorOfObject = "BLUE";
	}
}
// ------------------------------------------------------------
getColorReflected 红色灯获取反射光（深0-100浅），通常用于巡线
// 利用颜色感应器感应反射线光的明暗值
 
int threshold = 50;      /* 设置阀值为50 */
while(true)
{
	// 如果传感器感应到线条，值低于50
	if(getColorReflected(S3) < threshold)
	{
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
	}
}
// ------------------------------------------------------------
getColorRGB 获取RGB的值，每个值的范围从0到255
//创建变量存储红色、绿色和蓝色值
long redValue;
long greenValue;
long blueValue;
		while (true)
	{
	// 获取颜色传感器三个通道的值，并储存在变量中
	getColorRGB(colorSensor, redValue, greenValue, blueValue);

	//将值写入调试流
	  writeDebugStreamLine("Colour detected: %d, %d, %d", redValue, greenValue, blueValue);
		sleep(100);
	}
// ------------------------------------------------------------
getColorSaturation  获取颜色饱和度（低0-100高）
// 注：以下为robotc帮助文件中的实例，测试结果是值小于50时AB电机旋转
// 以下程序是将机器人向前行驶直到找到正确的颜色饱和度
// 循环直到颜色传感器找到饱和值大于50
repeatUntil(getColorSaturation(S3) > 50)
{
    displayBigTextLine(3, "%d", getColorSaturation(S3));
    //设置A电机的功率为10
    setMotorSpeed(motorA, 10);
    setMotorSpeed(motorB, 10);
}
// 停止电机
setMotorSpeed(motorA, 0);
setMotorSpeed(motorB, 0);

    // 注：经测试显示的饱合值与测试行为不一致，单电机测试报错，必须双电机
    // repeat(forever)
    // {
    //     // 如果颜色饱合度值大于50
    //     if (getColorSaturation(S3) > 50)
    //     {
    //         // 显示颜色饱合度值在第四行。
    //         displayBigTextLine(3, "%d", getColorSaturation(S3));
    //         //设置A电机的功率为10
    //         setMotorSpeed(motorA, 10);
    //         setMotorSpeed(motorB, 10);
    //     }
    //     else
    //     {
    //         setMotorSpeed(motorA, 0);
    //         setMotorSpeed(motorB, 0);
    //     }
    // }
// ====================================================
## Distance sensor 超声波距离传感器
getUSDistance 获得距离（可以检测到250cm以内的物体）
//这个程序检测机器人离物体距离10厘米以内
//循环检测直到传感器距离物体的小于10厘米
while(getUSDistance(distanceCM) > 10)
{
	//设置电机功率为50
	setMotorSpeed(leftMotor, 50);
	setMotorSpeed(rightMotor, 50);
}
 
//循环结束停止电机
setMotorSpeed(leftMotor, 0);
setMotorSpeed(rightMotor, 0);

Gyro Sensor 陀螺仪传感器
// ------------------------------------------------------------
getGyroDegrees 获得陀螺度数 （返回度数，顺时针旋转返回的值增加，逆时针旋转返回的值减少）
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
// ------------------------------------------------------------
getGyroHeading 获取陀螺航向（每次移动重置显示上一次移动的值，顺时针旋转返回的值增加，逆时针旋转返回的值减少）
//此程序将旋转机器人，直到陀螺仪读取与上次重置位置的距离为// 90度
 //保持循环直到陀螺仪传感器的读数更大超过90度（从最新的重置位置开始）
 repeatUntil(getGyroHeading(port4) > 90)
 {
  //向左拐
  setMotorSpeed(motorA, -50);
  setMotorSpeed(motorB, 50);
 }
 //在转弯结束时停止电动机
 setMotorSpeed(motorA, 0);
 setMotorSpeed(motorB, 0);
// ------------------------------------------------------------
getGyroRate  获取陀螺速率(单位为每秒度数，值的范围-440--440)
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

resetGyro   复位陀螺仪
resetGyro（） 复位为0
// ============================================================
## IR Sensor  红外传感器
getIRBeaconDirection(nDeviceIndex) 获取红外方向（使用信标通道1，值范围-25至25，顺为正，逆为负）
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
// ------------------------------------------------------------
getIRBeaconStrength(nDeviceIndex) 获取红外信标强度（信标通道1，值范围 近0至100远）
// 当获取红外信标的距离小于20时
    while (getIRBeaconStrength(S4) < 20)
    {
        // 显示信标距离值
        displayBigTextLine(3, "%d", getIRBeaconStrength(S4));
        //设置电机A功率为50，B电机的功率为-50，机器人向右转
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, -50);
    }
// ------------------------------------------------------------
getIRDistance(nDeviceIndex)  获取红外距离（值为0至100，返回100说明没有检测到任何东西）
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
// ------------------------------------------------------------
getIRRemoteButtons(nDeviceIndex) 获取红外遥控按钮
// 未能验证 当按下红外遥控器的蓝色向上按钮时
    while (getIRRemoteButtons(S4) == 3)
    {
        //电机A和B旋转，机器人前进
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, 50);
// ------------------------------------------------------------
getIRRemoteChannelButtons(nDeviceIndex, nChannel) 获取红外遥控频道按钮
// 信标为通道1，当按下红外遥控器的蓝色向上按钮时
    while (getIRRemoteChannelButtons(S4, 1) == 3)
    {
        //电机A和B旋转，机器人前进
        setMotorSpeed(MotorA, 50);
        setMotorSpeed(MotorB, 50);
    }
// ------------------------------------------------------------

getIRBeaconAllChannels(nDeviceIndex, pDirections, pStrengths)
获取所有频道的红外信标---无帮助

getIRBeaconChannelDirection(nDeviceIndex, nChannel)
获取红外信标通道方向---无帮助

getIRBeaconChannelStrength(nDeviceIndex, nChannel)
获取红外信标信道强度---无帮助
// ==========================================================
Tounch Sensor 触碰感应器
getBumpedValue 获得碰撞次数值
// 重置触碰感应器的值
    resetBumpedValue(S1);
    // 检测按10次
    repeatUntil(getBumpedValue(S1) == 10)
    {
        // 按10次后会发出 soundBeepBeep 声音
        playSound(soundBeepBeep);
    }
// ------------------------------------------------------------
getTouchValue  获取触摸值，按下返回1，松开返回0
// 以下程序是机器人以50功率的速度前进，直到按下“触摸传感器”机器人停止前进
    // 重复循环，直到按下触摸传感器为止（返回值1）
    repeatUntil(getTouchValue(S1) == 1)
    {
        displayBigTextLine(3, "%d", getTouchValue(S1));

        // 设置A电机和B电机以50功率前进
        setMotorSpeed(motorA, 50);
        setMotorSpeed(motorB, 50);
    }
    // 停止AB电机
    setMotorSpeed(motorA, 0);
    setMotorSpeed(motorB, 0);

resetBumpedValue(sensorPort) 重置触碰值

sensorRaw  返回传感器原始值（返回的值取决于使用的传感器）
 //  无限循环
     while(true)
{  
	// 显示 Sensor Value: 值在EV3上
	displayCenteredTextLine(3, "Sensor Value: %d", sensorRaw[S1]);
	// 等待100毫秒
	wait1Msec(100);
       //删除显示
 	eraseDisplay();
}
// ------------------------------------------------------------
sensorReset 重置传感器
// 循环直到触控传感器被碰撞5次
    while (getBumpedValue(S1) < 5)
    {
    }
    // 显示触碰传感器按的5次
    displayCenteredTextLine(2, "Original: %d", getBumpedValue(S1));
    sleep(2000);
    //  重置传感器
    sensorReset(S1);
    // 显示重置后的数字0
    displayCenteredTextLine(3, "Reset: %d", getBumpedValue(S1));
    sleep(2000);   
/*
陀螺仪传感器：将航向值重置为0
触摸传感器：将累积的撞击计数重置为0
超声波（美国）传感器：将传感器重置为距离CM模式
红外（IR）传感器：将传感器重置为接近模式
颜色传感器：将传感器重置为反射模式
*/
// ------------------------------------------------------------
SensorType[nDeviceIndex]= sensor  传感器类型
 // 将传感器端口1设置为触摸传感器更改此分配以更改传感器的类型
    SensorType[s1] = sensorEV3_Touch;
//无限循环
    while (true)
    {
        // 显示  "Sensor Value: ##"的值
        displayCenteredTextLine(3, "Sensor Value: %d", sensorValue[S1]);
        // 等待100毫秒以帮助正确显示
        wait1Msec(100);
        //删除显示
        eraseDisplay();
    }
/*
sensorEV3_Touch：EV3触摸传感器
sensorEV3_Color：EV3颜色传感器
sensorEV3_Ultrasonic：EV3超声波传感器
sensorEV3_Gyro：EV3陀螺仪传感器
sensorEV3_IRSensor：EV3红外传感器
sensorEV3_EnergyMeter：EV3电能表
sensorEV3_GenericI2C：通用I2C设备
*/ 
// ------------------------------------------------------------
SensorValue[nDeviceIndex]=  传感器的值
// 无限循环
while (true) 
    {
        //显示 "Sensor Value: ##"值
        displayCenteredTextLine(3, "Sensor Value: %d", SensorValue[S1]);

        //等待100毫秒以帮助正确显示
        wait1Msec(100);

        //删除显示
        eraseDisplay();
    }
// =======================================================
## Sounds  声音
clearSounds 清晰的声音
	//清除声音缓存
	clearSounds();
// ------------------------------------------------------------
getSoundVolume 获取音量（值的范围是0--100百分比）
// 定义扬声器音量；
char speakerVolume;
//获取音量给EV3
speakerEV3Volume = getVolume();
// ------------------------------------------------------------
playImmediateTone 立即播放音调
// 根据光线传感器读数播放音调（音频，时间）                                                                           
PlayImmediateTone(440, 50);
// 在再次检查之前等待200毫秒                              
wait1Msec(200);
// ------------------------------------------------------------
playSound  播放声音	
// 预定义声音有soundBlip，soundBeepBeep，soundDownwardTones，soundUpwardTones，soundLowBuzz，soundFastUpwardTones，soundShortBlip，soundException，soundLowBuzzShort
// 播放预定义声音 'soundBeepBeep'，
playSound(soundBeepBeep);
// ------------------------------------------------------------
playSoundFile 播放声音文件
//设置音量为75
setSoundVolume(75);
// 开始在EV3上播放声音文件“Bravo.rsf”
playSoundFile("Bravo");
// 给文件2秒播放时间
sleep(2000);
// ------------------------------------------------------------
playTone 播放音调
	// 以784赫兹的频率播放音调150毫秒
	playTone(784, 15);
// ------------------------------------------------------------
setSoundVolume  设置音量（0最低，100最高）
	//设置EV3的音量为25
	setSystemVolume(25);
	//以784的频率播放音调150毫秒
	playTone(784, 15); 
	//设置EV3的音量为75
	setSystemVolume(75);
	//以784的频率播放音调150毫秒
	playTone(784, 15);
// ============================================================
## LCD Display 显示

clearPixel 清除EV3 LCD屏幕上的单个像素
displayBigStringAt  按坐标显示，在x和y坐标上显示16像素的大字体
//在x坐标为0，y坐标为16的地方显示 16像素的字符A
displayBigStringAt(0, 16, "A");
sleep(1000);
// ------------------------------------------------------------
displayBigTextLine 按行显示，在EV3上最左侧显示16像素的大字体(为	索引值）
//在第三行最左边显示 ROBOTC（测试结果行的索引值为0--14，16像素的字需占两行）
displayBigTextLine(3, "ROBOTC");
// ------------------------------------------------------------
displayCenteredBigTextLine 按行显示，在EV3上最居中显示16像素的大字体
//在第三行中间显示 ROBOTC（测试结果行的索引值为0--14，16像素的字需占两行）  
displayCenteredBigTextLine(3, "ROBOTC");
注：displayBigTextLine 和displayCenteredBigTextLine同时用时，行的索引值不能相同
// ------------------------------------------------------------
displayCenteredTextLine 按行显示，在EV3上最中间显示8像素的字	体
// 在第三行中间显示ROBOTC，字体为普通字体（8像素，行的索引值为0-14）
displayCenteredTextLine(3, "ROBOTC");
// ------------------------------------------------------------
displayInverseBigStringAt 按坐标显示，以EV3左下角为圆点，在	x,y值坐标显示16像素的字符，字的背景有填充 
//x坐标50，y坐标80的地方显示背景填充的ROBOTC
displayInverseBigStringAt(50, 80, "ROBOTC");
//显示时间为3000毫秒
sleep(3000);
//填充EV3显示屏背景色，第1，2个参数为布尔值，0是不填充，1是填充，
// 177为EV3显示屏最宽像素值，127为EV3显示屏最高像素值，可以在这个范围任意取值
fillRect(0, 0, 177, 127);
//x坐标10，y坐标20的地方显示背景填充的ROBOTC
displayInverseBigStringAt(10, 20, "ROBOTC");
//显示时间为3000毫秒
sleep(3000);
// ------------------------------------------------------------
displayString 按行显示，显示在EV3显示屏的左边，显示8像素普通字体
//显示屏上第4行显示ROBOTC（行数为索引值）
displayString(3, "ROBOTC");
//显示时间为3000毫秒
sleep(3000);
// ------------------------------------------------------------
displayStringAt 按坐标显示，以EV3显示屏的左下角为圆点，显示字符	大小是8像素
//清除显示屏
eraseDisplay();
//在xy坐标是（0，16）的位置显示8像素的A
displayStringAt(0, 16, "A");
//显示时间为3000毫秒
sleep(1000);
// ------------------------------------------------------------
displayTextLine  按行显示 ，字符大小为8像素
（与displayString不知道有什么区别）
	//行数为索引值，在第四行显示普通号字符ROBOTC
	displayTextLine(3, "ROBOTC"); 
	//显示时间为3000毫秒
	sleep(1000);
// ------------------------------------------------------------
displayInverseString 按行显示，在EV3上最左侧显示8像素的字体，字体背景有黑色，字为白色(为索引值）
	// 反转在第四行（行索引值为3）上的字符ROBOTC，此时为黑色字体
displayInverseString(3, "ROBOTC");
// 等待3000毫秒
sleep(3000);
//屏幕背景为白色
fillRect(0, 0, 177, 127);
//反转在第四行（行索引值为3）上的字符ROBOTC，此时为白色字体，黑色背景
displayInverseString(3, "ROBOTC");
// ------------------------------------------------------------
displayInverseStringAt  按坐标显示，以EV3左下角为圆点，在x,y值坐标显示8像素的字符，字的背景有填充
//在x坐标是10，y坐标是20的位置显示背景为黑，字为白的8像素的ROBOTC
displayInverseStringAt(10, 20, "ROBOTC");
//显示等待时间为3000毫秒
sleep(3000);
//Fill the entire screen
fillRect(0, 0, 177, 127);
//Inverts the string ROBOTC at 10, 20
displayInverseStringAt(10, 20, "ROBOTC”)；
//显示等待时间为3000毫秒
sleep(3000);
// ------------------------------------------------------------
drawEllipse 绘制椭圆
	//drawEllipse(Left, Top, Right, Bottom);
	drawEllipse(10, 40, 100, 15);
// ------------------------------------------------------------
drawLine 绘制线段
	//drawLine(xPos, yPos, xPosTo, yPosTo);
	drawLine(10, 100, 100, 10);
// ------------------------------------------------------------
drawRect 绘制矩形
	//drawRect(Left, Top, Right, Bottom);
	drawRect(10, 40, 100, 15);
// ------------------------------------------------------------
eraseDisplay  完全清除EV3 LCD显示屏
	eraseDisplay();
// ------------------------------------------------------------
eraseEllipse 删除椭圆
	//填充背景色，0为白色
	fillRect(0, 0, 177, 127);
	//删除EV3上的椭圆
	eraseEllipse(10, 40, 100, 15);
// ------------------------------------------------------------
eraseLine 删除线段
	//删除EV3 LCD屏幕上的两条对角线
	//形成“X”形
	eraseLine(10, 10, 100, 100);
	eraseLine(10, 100, 100, 10);
// ------------------------------------------------------------
eraseRect 删除矩形
	//删除EV3 LCD屏幕上的矩形
	eraseRect(10, 40, 100, 15);
// ------------------------------------------------------------
fillEllipse 绘制填充椭圆
	//EV3上显示为填充黑色的椭圆，以下参数为左，上，右，下
	fillEllipse(10, 40, 100, 15);
// ------------------------------------------------------------
fillRect 绘制填充矩形
	//EV3上显示为填充黑色的矩形，以下参数为左，上，右，下
	fillRect(10, 40, 100, 15);
// ------------------------------------------------------------
getPixel 获取像素
	//在当前x，y坐标处设置像素
	setPixel(10, 20);
	//检查10，20坐标处是否有像素
	getPixel(10, 20);
// ------------------------------------------------------------
invertLine 反转线（空白像素和填充像素互转）
	//反转EV3 LCD屏幕上的两条对角线
	//形成“X”形
	invertLine(10, 10, 100, 100);
	invertLine(10, 100, 100, 10);
	//等待3000毫秒
	sleep(3000);
	//反转EV3 LCD屏幕上的两条对角线
	//清除了“X”形
	invertLine(10, 10, 100, 100);
	invertLine(10, 100, 100, 10);
	//等待3000毫秒
	sleep(3000);
// ------------------------------------------------------------
invertPixel 反转像素（空白像素和填充像素互转）
	//在5，10的坐标上设置像素
	setPixel(5, 10);
	//等待3000毫秒
	sleep(3000);
	//在5，10的坐标上反转像素
	invertPixel(5,10);
// ------------------------------------------------------------
//scrollText
setPixel 设置像素（单个像素）
	//定义x,y坐标为
	int x = 0;
	int y = 0;
	//While y is less than 10
	while(y < 10)
	{
		//While x is less than 100
		while(x < 100)
		{
			//Set a pixel at the current x,y coordinate
			setPixel(x, y);		
			//Increase x by 5 and y by 1
			x = x + 5;
			y = y + 1;
			sleep(1000)；
		}
	}
// ------------------------------------------------------------
getColorReflected 获取颜色反射
                                      
getBatteryCurrent  获得电池电流
getBatteryVoltage  获得电池电压
getPowerDownTimer  获取断电计时器
getButtonPress 获取按钮按下
setBlockBackButton 设置阻止后退按钮 
setPowerDownTimer     设置断电定时器
// ==========================================================
## Task Control 任务控制
abortTimeslice() 结束当前任务时间片
// ------------------------------------------------------------
// 暂停其他所有任务，并将100％的CPU集中在当前任务上
hogCPU();
// ------------------------------------------------------------
kDefaultTaskPriority 默认任务优先级，（一般优先级值为7）
// 创建一个变量以保存默认任务优先级值
int myPriority = 100;
// 将'mypriority'设置为7（默认） 
myPriority = kDefaultTaskPriority;
// ------------------------------------------------------------
kHighPriority 高优先级（最高优先级值为255）
//创建一个变量，以保留最高的优先级值
int myPriority = 100;
//设置'mypriority' 为255 (最高优先)
myPriority = kHighPriority;
// ------------------------------------------------------------
kLowPriority 最低优先级（最低优先级值为0）
//创建一个变量，以保留最低的优先级值
int myPriority = 100;
//设置 'mypriority' 为 0 (最低优先)
myPriority = kLowPriority;
// ------------------------------------------------------------
nSchedulePriority = Values 时间优先级（0--255）
// 为当前任务分配优先级为100
nSchedulePriority = 100;
// ------------------------------------------------------------
releaseCPU 释放CPU ,取消了先前的HogCPU（）函数调用的效果
// 恢复其他任务并将控制权返回给任务计划程序
releaseCPU();
// ------------------------------------------------------------
startTask(TaskID,nTaskPriority) 开始任务 nTaskPriority的值从0--255，如不指定就为默认值7
// 以10的优先级启动名为“ MoveArm”的任务
startTask(MoveArm, 10);
// ------------------------------------------------------------
stopAllTasks 停止所有任务，包括主程序任务和函数调用
// 停止当前正在运行的所有任务并退出当前程序
stopAllTasks();
// ------------------------------------------------------------
stopTask 停止任务（停止指定的任务）
// 停止名为“ MoveArm”的任务
stopTask(MoveArm);

// =============================================================
clearTimer 清除计时器

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
// ------------------------------------------------------------
delay 延迟（以毫秒为单位）
// 注：与wait1MSec()和sleep()命令完全相同
// 电机A的功率为50，旋转度数为50度
    moveMotorTarget(motorA, 1000, 50);
    waitUntilMotorStop(motorA);
    // 程序将等待1秒，然后继续下一行代码,此处也可以用wait1MSec(2000);和 sleep(2000);
    delay(2000);
    // wait1MSec(2000);
    // sleep(2000);
    moveMotorTarget(motorA, 1000, 50);
    waitUntilMotorStop(motorA);

// ------------------------------------------------------------
nClockMinutes 读/写变量以分钟单位
// 创建一个变量以保存内部1毫秒计时器的值（以分钟为单位）
int varClock;
// 将nClockMinutes的值存储到'varClock'变量中
varClock = nClockMinutes;

// ------------------------------------------------------------
nPgmTime 当前程序运行的值（单步调式很有用）
// 创建一个变量用于存储当前程序运行时间
unsigned long varPgmTime;
// 等待1000个1毫秒的滴答声（1秒）
wait1MSec(1000);
 // 将nPgmTime的当前值存储到变量
varPgmTime = nPgmTime;

// ------------------------------------------------------------
nSysTime 系统时间（机器人通电时间的值，首次通电会重置此变量）
// 创建一个变量用于存储当前的系统通电时间值
int varSysTime;                                            
// 将nSysTime的当前值存储到变量
varSysTime = nSysTime;

// ------------------------------------------------------------
sleep 等待指定的毫秒数  与 wait1MSec（）和delay（）命令完全相同
// 等待1000毫秒
sleep(1000)

// ==========================================================
## Buttons 按钮
getButtonPress 按下按钮（按下返回1，没按下返回0）
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
// ------------------------------------------------------------
setBlockBackButton 设置阻止后退按钮

//阻止后退按钮退出程序，如不阻止，将1改为0
setBlockBackButton(1);
//无限循环 
while(true){}
// ------------------------------------------------------------
waitForButtonPress  等待按钮按下
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

//------------------------------------------------------------
## battery and power control 电池和电源控制

getBatteryCurrent 获取电池流量（只能读取，不能分配值）
// 创建并设置浮点变量'batteryDrain'
// 得出EV3的平均电流
float batteryDrain = getBatteryCurrent();

//------------------------------------------------------------
getBatteryVoltage 获取电池电压（以10分之1伏的精度返回电池电量，只能读取，不能分配值）
// 创建并设置浮动变量'batteryLife'，获取到设备的平均电池电量
float batteryLife = getBatteryVoltage();

//------------------------------------------------------------
getPowerDownTimer 获取电源关闭时间（返回剩余多少时间，直到EV3自动关闭，返回值以分钟为单位）
// 创建变量 'timeUntilDown'
char timeUntilDown;
//获取EV3的剩余电量时间给 'timeUntilDown' 变量
timeUntilDown = getPowerDownTimer();

//------------------------------------------------------------
setPowerDownTimer 设置关机时间（设置EV3在自动关闭之前保持空闲状态的时间，以分钟为单位）
// 在闲置5分钟后关闭EV3
setPowerDownTimer(5);

//------------------------------------------------------------
## Datalogging 数据记录

datalogAddValue(int nDataSeries, int nDataValue) 数据记录添加到数据日志中。nDataSeries是添加值的数据日志系列，从0--7；nDataValue为要添加的数据
// 将值27添加到数据记录系列1
datalogAddValue(1, 27);

//------------------------------------------------------------
datalogAddValueWithTimeStamp(int nDataSeries, int nDataValue)
数据记录添加到带有时间的数据日志中。nDataSeries是添加值的数据日志系列，从0--7；nDataValue为要添加的数据，此值带有时间，并在记录中占一行
//将值27添加到带有时间的数据记录系列1中
datalogAddValueWithTimeStamp(1、27);

//------------------------------------------------------------
datalogBackgroundPollingPause() 数据日志背景轮询暂停  暂停“电动机和传感器设置”对话框中定义的数据记录系列的后台轮询。
datalogBackgroundPollingResume() 数据日志后台轮询恢复 恢复“电动机和传感器设置”对话框中定义的数据记录系列的后台轮询。

// 暂停数据记录系列的后台轮询
datalogBackgroundPollingPause();
// 保持程序流5秒钟 
sleep(5000);
// 恢复数据记录系列的后台轮询
datalogBackgroundPollingResume();

//------------------------------------------------------------
datalogClear() 数据记录清除  清除所有ROBOTC调试器未读取的数据记录值。
//清除没有的数据记录值,由ROBOTC调试器读取
datalogClear();

//------------------------------------------------------------
datalogDataGroupEnd() 数据日志数据组结束 
datalogDataGroupStart() 数据日志数据组开始 此命令将启动数据日志集，并且必须使用datalogDataGroupEnd命令关闭数据日志集，此集中添加的任何数据将占据数据日志中的同一行
//开始一组数据记录值
datalogDataGroupStart();
//将值27添加到数据记录系列1
datalogAddValue(1，27);
//将值27添加到数据记录系列1
datalogAddValue(2，29);
//结束一组数据记录值
datalogDataGroupEnd();

//------------------------------------------------------------
setLEDColor(TEV3LEDpatterns) 设置EV3 LED的颜色和闪烁组合
TEV3LED模式有10个选项：
LED_BLACK：关闭LED。
LED_GREEN：将LED点亮为稳定的绿色。
LED_RED：将LED点亮为稳定的红色。
LED_ORANGE：将LED点亮为稳定的橙色。
LED_GREEN_FLASH：将LED点亮为绿色闪烁。
LED_RED_FLASH：将LED点亮为闪烁的红色。
LED_ORANGE_FLASH：将LED点亮为闪烁的橙色。
LED_GREEN_PULSE：将LED点亮为绿色。
LED_RED_PULSE：将LED点亮为红色。
LED_ORANGE_PULSE：将LED点亮为橙色。

//无限循环
while(true)
{
	// 将LED绿色灯闪烁两秒钟
	setLEDColor(edGreenFlash);
	sleep(2000);
	//将LED红色脉动两秒钟
	setLEDColor(ledRedPulse);
	sleep(2000);
	//将LED持续点亮橙色两秒钟
	setLEDColor(ledOrange);
	sleep(2000);
}

//=====================================================
## joystick control 操纵杆控制
getJoystickSettings(joystick) 获取操纵杆设置

//------------------------------------------------------------



//============================================================


//------------------------------------------------------------



//------------------------------------------------------------

