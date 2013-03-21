#pragma once

#include "Basic.h"
#include "Types.h"
#include "Defines.h"
#include "Config.h"

class Timer
{
public:
	enum
	{
		Sec,
		MSec
	};

	static void		Start();
	static void		Stop();

	static double	GetTime(int Mode = MSec);
private:
	static long		mStart;
	static long		mEnd;

	static double	mSeconds;
	static double	mMiliseconds;
};