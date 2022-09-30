#pragma once

#ifndef  __TIMER_H__
#define  __TIMER_H__

#include "../CommonDataDefine.h"

using TimerFunc = function<void(int)>;

class Timer
{
public:
	Timer(string timer_name, TimerFunc func);

public:
	//线程开始
	void Start(int interval = 1000, bool immediate_ = false);

	//线程结束
	void Stop();

	//函数执行体
	void Exec();


private:
	bool exit_;				// 退出标记
	bool immediate_;		//
	int interval_;			// 执行间隔（周期）
	int count_;				// 执行次数
	thread thread_;			// 线程
	mutex mutex_;			// 锁
	TimerFunc func_;		// 执行函数
	string timer_name_;		// 计时器
	condition_variable cv;	// 条件变量
};

#endif
