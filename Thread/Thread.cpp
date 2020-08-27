#include "../pch.h"

#include "Thread.h"
#include "mutex.h"

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
