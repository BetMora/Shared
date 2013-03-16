#pragma once

#include <ctime>

class Timer
{
public:
	enum
	{
		Sec,
		MSec
	};

	static void Start();
	static void Stop();

	static double GetTime(int Mode = MSec);
private:
	static clock_t	mStart;
	static clock_t	mEnd;

	static double	mSeconds;
	static double	mMiliseconds;
};