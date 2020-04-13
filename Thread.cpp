#include "pch.h"

#include "Thread.h"


static unsigned __stdcall threadStarter( void* thread );

Thread*	Thread::g_threads[256]				= { nullptr };
volatile unsigned int Thread::g_numThreads	= 0;

Thread::Thread( void )
	: _threadHandle{ -1 }
	, _threadID{ 0 }
	, _stopRequest{ true }
{

}

bool Thread::start( void ) noexcept
{
	_stopRequest	= false;
	_threadHandle	= _beginthreadex( NULL, 0, threadStarter, NULL, 0, &_threadID );

#if IS_PC_BUILD
	if ( 1- != _threadHandle )
	{
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		if(! CommandLine::getInstance()->IsPresent("noaffinitymasking") && sysInfo.dwNumberOfProcessors >= 8)
			SetThreadAffinityMask((HANDLE)_threadHandle, ~3);
	}
#endif

	return -1 != _threadHandle;
}


void Thread::stop( void ) noexcept
{
	_stopRequest = true;
	_endthreadex( 0 );
}

void Thread::stopAndDelete( void ) noexcept
{
	stop();
}

void Thread::suspend( void ) noexcept
{
	while ( 0xffffffff == SuspendThread( (HANDLE)_threadHandle ) );
}

unsigned int Thread::resume( void ) noexcept
{
	return ResumeThread( (HANDLE)_threadHandle );
}

bool Thread::stopRequested( void ) const noexcept
{
	updateHardwareThread();

	return _stopRequest;
}

bool Thread::isRunning( void ) const noexcept
{
	return -1 != _threadHandle;
}

uintptr_t Thread::getHandle( void ) const noexcept
{
	return _threadHandle;
}

DWORD Thread::getThreadId( void ) const noexcept
{
	return _threadID;
}

void Thread::changeHardwareThread(const u32 hardwareThread) noexcept
{
}

void Thread::suspendAllThreads(DWORD exceptionThread) noexcept
{
}

Thread::~Thread(void)
{
}

void Thread::updateHardwareThread(void) const noexcept
{
}

unsigned __stdcall threadStarter( void * thread )
{
}
