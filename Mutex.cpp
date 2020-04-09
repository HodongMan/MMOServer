#include "pch.h"
#include "Mutex.h"

Mutex::Mutex( int spinLockCount )
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

Mutex::~Mutex( void )
{
	DeleteCriticalSection( &_mutex );
}

void Mutex::lock( void ) noexcept
{
	if ( false == TryEnterCriticalSection( & _mutex ) )
	{
		EnterCriticalSection( &_mutex );
	}

	_lockCount += 1;
}

bool Mutex::tryLock( void ) noexcept
{
	if ( false == TryEnterCriticalSection( & _mutex ) )
	{
		_lockCount += 1;

		return true;
	}

	return false;
}

void Mutex::unlock( void ) noexcept
{
	LeaveCriticalSection( &_mutex );

	_lockCount -= 1;
}

const CRITICAL_SECTION& Mutex::getCriticalSection( void ) const noexcept
{
	return _mutex;
}

unsigned int Mutex::getLockCount( void ) noexcept
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
