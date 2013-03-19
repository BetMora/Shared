#include "Timer.h"

#include <ctime>

clock_t	Timer::mStart		= 0;
clock_t	Timer::mEnd			= 0;

double	Timer::mSeconds		= 0;
double	Timer::mMiliseconds = 0;

void Timer::Start()
{
	mStart = clock();
}

void Timer::Stop()
{
	mEnd = clock();

	mSeconds		= ((double)(mEnd - mStart) / CLOCKS_PER_SEC);
	mMiliseconds	= (double)(mEnd - mStart);
}

double Timer::GetTime(int Mode)
{
	switch(Mode)
	{
	case Sec:
		return mSeconds;
		break;
	case MSec:
		return mMiliseconds;
		break;
	default:
		break;
	}

	return 0;
}