task main()
{
    // 声音模块

    //清除声音缓存
    clearSounds();

    // 定义扬声器音量；
    char speakerVolume;
    //TODO 获取音量给EV3 不清楚具体用法
    speakerEV3Volume = getVolume();

    // TODO 根据光线传感器读数播放音调（音频，时间）不清楚具体用法
    PlayImmediateTone(440, 50);
    // 在再次检查之前等待200毫秒
    wait1Msec(200);

    // 播放声音 预定义'soundBeepBeep'
    playSound(soundBeepBeep);

    // 设置音量为75
    setSoundVolume(75);
    // 开始在EV3上播放声音文件“Bravo.rsf”
    playSoundFile("Bravo");
    // 给文件2秒播放时间
    sleep(2000);

    // 播放784赫兹的音调，时长150毫秒
    playTone(784, 15);
    sleep(2000);
}

/**
 * clearSounds();
 * 功能：清除声音缓存
 */

/**
 * getVolume();
 * 功能：获取音量
 */

/**
 * PlayImmediateTone(frequency, durationIn10MsecTicks);
 * 功能：在程序排队请求之前立即在指定时间内播放音频
 * 参数1：frequency：int 音频
 * 参数2：durationIn10MsecTicks： int 播放时间，以10毫秒为单位
 */

/**
 * playSound(TSounds sound);
 * 功能：播放预定义声音
 * 参数1：TSounds sound：TSounds 预定义声音
 * 预定义声音有：
 * soundBlip
 * soundBeepBeep
 * soundDownwardTones
 * soundUpwardTones
 * soundLowBuzz
 * soundFastUpwardTones
 * soundShortBlip
 * soundException
 * soundLowBuzzShort
 */

/**
 * playSoundFile(pFileName);
 * 功能：播放声音文件
 * 参数1：pFileName：string 声音文件名称（共有127个文件）
 * 声音文件的路径：C:\Program Files (x86)\Robomatter Inc\ROBOTC Development Environment 4.X\EV3 System Files\Sounds 
 */

/**
 * setSoundVolume(nVolume);
 * 功能：设置音量
 * 参数1：nVolume：int 音量值0--100
*/

/**
 * playTone(frequency，durationIn10MsecTicks);
 * 功能：在指定时间内播放音频
 * 参数1：frequency：int 音频，赫兹
 * 参数2：durationIn10MsecTicks： int 播放时间，以10毫秒为单位
*/

