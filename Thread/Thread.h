#pragma once

#include "TypeThread.h"
#include "../Base/Atomic.hpp"
#include "../Base/Noncopyable.h"

class Task;

class Thread : public Noncopyable
{
public:
	Thread( void );
	virtual ~Thread( void );

	bool isRunning( void ) const noexcept;
	bool start( void ) noexcept;
	virtual bool run( void ) noexcept;
	bool suspend( void ) noexcept;
	void resume( void ) noexcept;
	void stop( void ) noexcept;

	static unsigned __stdcall threadFunc( void *arg ) noexcept;

protected:
	virtual void helpStop( void ) noexcept;

private:
	HANDLE			m_hThread;
	unsigned int	m_threadId;

	AtomicInt64		m_run;
	AtomicInt64		m_suspend;

};

/*
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

*/