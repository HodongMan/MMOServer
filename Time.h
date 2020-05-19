#pragma once

#include "pch.h"

inline uint32_t getTime( void )
{
	return GetTickCount();
}

inline uint64_t getTime64( void )
{
#if _WIN32_WINNT >= 0x0600
	return GetTickCount64();
#else
	static uint32 previous = 0;
	static uint64 total = 0;
	uint32 now = GetTickCount();
	total += (previous > now) ? (0xFFFFFFFF - previous) + now : (now - previous);
	previous = now;
	return total;
#endif
}