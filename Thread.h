#pragma once


class Thread
{
public:
	Thread( void );

protected:

	virtual void run( void ) = 0;
	virtual ~Thread( void );

private:

	volatile bool		_stopRequest;
	uintptr_t volatile	_threadHandle;
	UINT				_threadID;

	friend void			threadStarter( void* thread );
			
	void				updateHardwareThread( void ) const noexcept;

	static Thread*					g_threads[256];
	static volatile unsigned int	g_numThreads;
};