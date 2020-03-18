
task main()
{
    // 移动转向模块
    // TODO setMotorSync和setMotorSyncEncoder无法区分各自的功能

    // -------------------------------------

    // A和B端口的电机同时以60功率旋转
    setMotorSync(MotorA, MotorB, 0, 60);
    // 等待2000毫秒（2秒）
    sleep(2000);
    // A电机以60功率旋转，B电机不转
    setMotorSync(MotorA, MotorB, 50, 60);
    // 等待2000毫秒（2秒）
    sleep(2000);
    // A电机以60功率顺时针旋转，B电机以-60功率逆时针旋转
    setMotorSync(MotorA, MotorB, 100, 60);
    // 等待2000毫秒（2秒）
    sleep(2000);

    // -------------------------------------

    // A电机和B电机同时顺时针旋转1200度（ 直线行走 ）
    setMotorSyncEncoder(MotorA, MotorB, 0, 1200, 50);
    sleep(1500);
    // A电机以50功率顺时针旋转1000度，B电机以50功率逆时针旋转1000度（向右原地旋转）
    setMotorSyncEncoder(MotorA, MotorB, 100, 1000, 50);
    sleep(1500);
    // A电机以50功率逆时针旋转1000度，B电机以50功率顺时针旋转1000度（向左原地旋转）
    setMotorSyncEncoder(MotorA, MotorB, -100, 1000, 50);
    sleep(1500);
    // A电机以50功率顺时针旋转1200度，B电机为0功率（向右转弯）
    setMotorSyncEncoder(MotorA, MotorB, 50, 1200, 50);
    sleep(1500);
    // B电机以50功率顺时针旋转500度，A电机为0功率（向左转弯）
    setMotorSyncEncoder(MotorA, MotorB, -50, 500, 50);
    sleep(1500);

    // -------------------------------------

    // A电机以50功率顺时针旋转1000毫秒，B电机以50功率逆时针旋转1000毫秒
    setMotorSyncTime(MotorA, MotorB, 100, 1000, 50);
    sleep(1500);
}

/**
 * setMotorSync(nMotorOne, nMotorTwo, nTurnRatio, nSignedPower);
 * 功能：移动转向
 * 参数1：nMotorOne 第一电机的名称或端口
 * 参数2：nMotorTwo 第二电机的名称或端口
 * 参数3：nTurnRatio 转向值，如：
 *       100：1电机为正功率，2电机为负功率；
 *      -100：1电机为负功率，2电机为正功率；
 *         0：1和2电机直线行驶；
 *        50：1电机旋转，2电机不动；
 *       -50：1电机不动，2电机旋转。
 * 参数4：nSignedPower 电机功率
 */

/**
 * setMotorSyncEncoder(nMotorOne, nMotorTwo, nTurnRatio, nEncoderCount,nSignedPower);
 * 功能：根据度数移动转向
 * 参数1：nMotorOne 第一电机的名称或端口
 * 参数2：nMotorTwo 第二电机的名称或端口
 * 参数3：nTurnRatio 转向值，如：
 *       100：1电机为正功率，2电机为负功率；
 *      -100：1电机为负功率，2电机为正功率；
 *         0：1和2电机直线行驶；
 *        50：1电机旋转，2电机不动；
 *       -50：1电机不动，2电机旋转。
 * 参数4：nEncoderCount 电机旋转度数
 * 参数5：nSignedPower 电机功率
 */

/**
 * setMotorSyncTime(nMotorOne, nMotorTwo, nTurnRatio, nTimeMsec,nSignedPower);
 * 功能：根据时间移动转向
 * 参数1：nMotorOne 第一电机的名称或端口
 * 参数2：nMotorTwo 第二电机的名称或端口
 * 参数3：nTurnRatio 转向值，如：
 *       100：1电机为正功率，2电机为负功率；
 *      -100：1电机为负功率，2电机为正功率；
 *         0：1和2电机直线行驶；
 *        50：1电机旋转，2电机不动；
 *       -50：1电机不动，2电机旋转。
 * 参数4：nTimeMsec 电机旋转时间，单位为毫秒
 * 参数5：nSignedPower 电机功率
 */
