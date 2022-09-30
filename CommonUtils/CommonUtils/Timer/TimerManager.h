#pragma once
#ifndef  __TIMER_MANAGER_H__
#define  __TIMER_MANAGER_H__

#include "../CommonDataDefine.h"


class Timer;

using ptr_timer = std::shared_ptr<Timer>;

class TimerManager
{
public:
	TimerManager() {}

public:
	// 创建定时器
	bool CreateTimer(string timer_name, TimerFunc func);

	// 销毁定时器
	bool DestroyTimer(string timer_name);

private:
	unordered_map<string, ptr_timer> map_timer_;
	mutex mutex_;
};

#endif