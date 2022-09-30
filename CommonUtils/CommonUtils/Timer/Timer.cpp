#include "Timer.h"

Timer::Timer(string timer_name, TimerFunc func)
{
	timer_name_ = timer_name;
	func_ = func;
}

void Timer::Start(int interval, bool immediate_)
{
	unique_lock<mutex> guard(mutex_);

	exit_ = true;
	count_ = 0;
	immediate_ = immediate_;
	interval_ = interval;
	thread_ = thread(bind(&Timer::Exec, this));
}

void Timer::Stop()
{
	unique_lock<mutex> guard(mutex_);
	if (!exit_)
	{
		return;
	}

	exit_ = false;

	cv.notify_all();
	if (thread_.joinable())
	{
		thread_.join();
	}
}

void Timer::Exec()
{
	if (immediate_)
	{
		if (func_)
		{
			func_(interval_);
		}
	}

	while (!exit_)
	{
		unique_lock<mutex> guard(mutex_);
		cv.wait_for(guard, chrono::milliseconds(interval_));

		++count_;
		if (func_)
		{
			func_(count_);
		}
	}
}