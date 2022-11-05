#pragma once
// //////////////////////////////////////////////////////////
// timing.c
// Copyright (c) 2014 Stephan Brumme. All rights reserved.
// see http://create.stephan-brumme.com/disclaimer.html
//
//	EDITED BY HKZ


// include OS specific timing library
#ifdef _MSC_VER
// Windows
#include <Windows.h>
#else
// Linux
#include <time.h>
#define __int64  long long
#endif



class TimerClass
{
public:

	static __int64 GetTime_in_MiliSec()
	{
#ifdef _MSC_VER
		static LARGE_INTEGER frequency;
		if (frequency.QuadPart == 0)
			::QueryPerformanceFrequency(&frequency);

		LARGE_INTEGER now;
		::QueryPerformanceCounter(&now);


		return now.QuadPart / (frequency.QuadPart / 1000);
#else
		struct timespec now;
		clock_gettime(CLOCK_MONOTONIC, &now);
		return now.tv_sec * 1000 + now.tv_nsec / 1000000.0;
#endif
	}
private:


};

