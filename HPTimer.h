#pragma once
#include <Windows.h>
class HPTimer
{
private:
	long long startTime;
	long long lastCallToUpdate;
	long long currentCallToUpdate;
	long long frequrency;
public:
	HPTimer()
	{
		LARGE_INTEGER t;
		QueryPerformanceFrequency(&t);
		frequrency = t.QuadPart;
		Reset();
	}
	void Reset()
	{
		LARGE_INTEGER t;
		QueryPerformanceCounter(&t);
		startTime = t.QuadPart;
		currentCallToUpdate = t.QuadPart;
		lastCallToUpdate = t.QuadPart;
	}
	void Update()
	{
		lastCallToUpdate = currentCallToUpdate;
		LARGE_INTEGER t;
		QueryPerformanceCounter(&t);
		currentCallToUpdate = t.QuadPart;
	}

	long long GetTimeTotal()
	{
		return (currentCallToUpdate - startTime) / frequrency;
	}

	long long GetTimeDelta()
	{
		return (currentCallToUpdate - lastCallToUpdate) / frequrency;
	}
};

