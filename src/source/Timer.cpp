#include "Timer.h"

#include <ctime>

struct TimerData
{
	clock_t Start;
	clock_t End;

	double	Seconds;
	double	Miliseconds;

	TimerData()
	{
		Seconds		= 0;
		Miliseconds	= 0;
		Start		= 0;
	}

	~TimerData()
	{
		Seconds		= 0;
		Miliseconds = 0;
		End			= 0;
	}
};

TimerData* Timer::mData = new TimerData();

Timer::Timer()
{
	mData = new TimerData();
}

Timer::~Timer()
{
	delete mData;
}

void Timer::Start()
{
	mData->Start = clock();
}

void Timer::Stop()
{
	mData->End = clock();

	mData->Seconds		= ((double)(mData->End - mData->Start) / CLOCKS_PER_SEC);
	mData->Miliseconds	= (double)(mData->End - mData->Start);
}

double Timer::GetTime(int Mode)
{
	switch(Mode)
	{
	case Sec:
		return mData->Seconds;
		break;
	case MSec:
		return mData->Miliseconds;
		break;
	default:
		return 0;
		break;
	}
}