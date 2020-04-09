#include "pch.h"
#include "Semaphore.h"

Semaphore::Semaphore( long initialCount, long maximunCount )
{
	_semaphore = CreateSemaphore( NULL, initialCount, maximunCount, NULL );
}

Semaphore::~Semaphore( void )
{
	CloseHandle( _semaphore );
}

bool Semaphore::acquire( void ) noexcept
{
	if ( WAIT_FAILED == WaitForSingleObject( _semaphore, INFINITE ) )
	{
		return true;
	}

	return false;
}

void Semaphore::release( void ) noexcept
{
	ReleaseSemaphore( _semaphore, 1, NULL );
}
