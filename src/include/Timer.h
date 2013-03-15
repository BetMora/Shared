#pragma once

struct TimerData;

class Timer
{
public:
	enum
	{
		Sec,
		MSec
	};

	Timer();
	~Timer();

	static void Start();
	static void Stop();

	static double GetTime(int Mode = MSec);
private:
	static TimerData* mData;
};