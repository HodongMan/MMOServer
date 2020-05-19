#pragma once

#include "TypeThread.h"
#include "Mutex.h"

class Task;


class Thread
{
public:
	Thread( int threadWaitSecond = 0 );
	virtual ~Thread( void );

	THREAD_ID			createThread( void ) noexcept;
	void				join( void ) noexcept;

	virtual void		onStart( void ) noexcept;
	virtual void		onEnd( void ) noexcept;

	virtual void		onProcessTaskStart( Task* task ) noexcept;
	virtual void		processTask( Task* task ) noexcept;
	virtual void		onProcessTaskEnd( Task* task ) noexcept;


	static unsigned __stdcall threadFunc( void *arg ) noexcept;
protected:

	Lock				_lock;
	uintptr_t volatile	_threadHandle;
	const int			_threadWaitSecond; // readonly
	ThreadState			_threadState;
};