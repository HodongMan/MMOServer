#include "pch.h"
#include "Mutex.h"

Lock::Lock( int spinLockCount )
	: _lockCount{ 0 }
{
	if ( 0 < spinLockCount )
	{
		InitializeCriticalSectionAndSpinCount( &_mutex, spinLockCount );
	}
	else
	{
		InitializeCriticalSection( &_mutex );
	}
}

Lock::~Lock( void )
{
	DeleteCriticalSection( &_mutex );
}

void Lock::lock( void ) noexcept
{
	if ( false == TryEnterCriticalSection( & _mutex ) )
	{
		EnterCriticalSection( &_mutex );
	}

	_lockCount += 1;
}

bool Lock::tryLock( void ) noexcept
{
	if ( false == TryEnterCriticalSection( & _mutex ) )
	{
		_lockCount += 1;

		return true;
	}

	return false;
}

void Lock::unlock( void ) noexcept
{
	LeaveCriticalSection( &_mutex );

	_lockCount -= 1;
}

const CRITICAL_SECTION& Lock::getCriticalSection( void ) const noexcept
{
	return _mutex;
}

unsigned int Lock::getLockCount( void ) noexcept
{
	return 0;
}

SpinLock::SpinLock( void )
	: _lock{ 0 }
	, _lockCount{ 0 }
{

}

SpinLock::~SpinLock( void )
{

}

void SpinLock::lock( void ) noexcept
{
	while ( _InterlockedExchange( &_lock, 1 ) );

	_lockCount += 1;
}

bool SpinLock::tryLock( void ) noexcept
{
	if( false == _InterlockedExchange( &_lock, 1 ) )
	{
		_lockCount += 1;
		return true; 
	}
	else 
	{
		return false; 
	}
}

void SpinLock::unlock( void ) noexcept
{
	_InterlockedExchange( &_lock, 0 );

	_lockCount -= 1;
}

unsigned int SpinLock::getLockCount( void ) const noexcept
{
	return _lockCount;
}
