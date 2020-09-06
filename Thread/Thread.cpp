#include "../pch.h"

#include "Thread.h"
#include "mutex.h"


Thread::Thread( void )
	: m_hThread{ 0 }
	, m_threadId{ 0 }
{

}

Thread::~Thread( void )
{

}

bool Thread::isRunning( void ) const noexcept
{
	return ( 1 == this->m_run.get() );
}

bool Thread::start( void ) noexcept
{
	//m_run.getAndAdd();

	m_hThread = (HANDLE)_beginthreadex( NULL, 0, &Thread::threadFunc, (void*)this, NULL, &m_threadId);
	if ( 0 == m_hThread )
	{
		//this->m_run = 0;
		return false;
	}

	return true;
}

bool Thread::run( void ) noexcept
{
	return false;
}

bool Thread::suspend( void ) noexcept
{
	if ( SuspendThread( m_hThread ) < 0 )
	{
		return false;
	}

	//m_suspend.getAndAdd( 1 );
	return true;
}

void Thread::resume( void ) noexcept
{
	WaitForSingleObject( m_hThread, -1 );

	CloseHandle( m_hThread );
}

void Thread::stop( void ) noexcept
{

}

void Thread::helpStop( void ) noexcept
{

}

unsigned __stdcall Thread::threadFunc( void * arg ) noexcept
{
	Thread* thread = (Thread*)arg;

	if ( nullptr != thread)
	{
		return thread->run();
	}

	return 0;
}


/*
Thread::Thread( int threadWaitSecond )
	: _threadWaitSecond{ threadWaitSecond }
	, _threadHandle{ 0 }
	, _threadState{ ThreadState::THREAD_STATE_END }
{

}

Thread::~Thread( void )
{
	_endthreadex( 0 );
}

THREAD_ID Thread::createThread( void ) noexcept
{
	_threadHandle = _beginthreadex( NULL, 0, &Thread::threadFunc, (void*)this, NULL, 0 );

	return (THREAD_ID)_threadHandle;
}

void Thread::join( void ) noexcept
{

}

void Thread::onStart( void ) noexcept
{

}

void Thread::onEnd( void ) noexcept
{

}

void Thread::onProcessTaskStart( Task* task ) noexcept
{

}

void Thread::processTask( Task* task ) noexcept
{

}

void Thread::onProcessTaskEnd( Task * task ) noexcept
{

}

unsigned __stdcall Thread::threadFunc(void * arg) noexcept
{
	return 0;
}
*/