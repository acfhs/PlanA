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
	//�߳̿�ʼ
	void Start(int interval = 1000, bool immediate_ = false);

	//�߳̽���
	void Stop();

	//����ִ����
	void Exec();


private:
	bool exit_;				// �˳����
	bool immediate_;		//
	int interval_;			// ִ�м�������ڣ�
	int count_;				// ִ�д���
	thread thread_;			// �߳�
	mutex mutex_;			// ��
	TimerFunc func_;		// ִ�к���
	string timer_name_;		// ��ʱ��
	condition_variable cv;	// ��������
};

#endif
