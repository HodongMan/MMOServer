#pragma once

#include <stdint.h>

#include "../pch.h"
#include "Noncopyable.h"


template <typename T>
class AtomicInt : public Noncopyable
{
public:
	AtomicInt( void )
		: _value{ 0 }
	{
	
	}

	T get( void ) const noexcept
	{
		return InterlockedCompareExchange( (long*)&_value, 0, 0 );
	}

	T getAndAdd( T& x ) noexcept
	{
		return InterlockedExchangeAdd( &value_, x );
	}

private:
	volatile T _value;
};

using AtomicInt32 = AtomicInt<int32_t>;
using AtomicInt64 = AtomicInt<int64_t>;

/*
#define CustomInterlockedCompareExchange(_v, _old, _new) (\
sizeof *(_v) == sizeof(char)    ? InterlockedCompareExchange8 ((char *)   (_v), (char)   (_new), (char)   (_old)) : \
sizeof *(_v) == sizeof(short)   ? InterlockedCompareExchange16((short *)  (_v), (short)  (_new), (short)  (_old)) : \
sizeof *(_v) == sizeof(long)    ? InterlockedCompareExchange  ((long *)   (_v), (long)   (_new), (long)   (_old)) : \
sizeof *(_v) == sizeof(__int64) ? InterlockedCompareExchange64 ((__int64 *)(_v), (__int64)(_new), (__int64)(_old))
*/