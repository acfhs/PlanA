#include "Timer.h"
#include "TimerManager.h"

bool TimerManager::CreateTimer(string timer_name, TimerFunc func)
{
	lock_guard<mutex> guard(mutex_);

	auto iter_timer_find = map_timer_.find(timer_name);
	if (map_timer_.end() != iter_timer_find)
	{
		return false;
	}

	auto timer = make_shared<Timer>(timer_name, func);
	timer->Start();

	map_timer_[timer_name] = timer;

	return true;
}

bool TimerManager::DestroyTimer(string timer_name)
{
	lock_guard<mutex> guard(mutex_);

	auto iter_timer_find = map_timer_.find(timer_name);
	if (map_timer_.end() == iter_timer_find)
	{
		return false;
	}

	iter_timer_find->second->Stop();
	map_timer_.erase(iter_timer_find);

	return true;
}