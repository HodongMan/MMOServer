#pragma once


class Thread
{
public:
	Thread( void );

	bool				start( void ) noexcept;
	void				stop( void ) noexcept;
	void				stopAndDelete( void ) noexcept;

	void				suspend( void ) noexcept;
	unsigned int		resume( void ) noexcept;

	bool				stopRequested( void ) const noexcept;
	bool				isRunning( void ) const noexcept;

	uintptr_t			getHandle( void ) const noexcept;
	DWORD				getThreadId( void )	const noexcept;

	void				changeHardwareThread( const u32 hardwareThread ) noexcept;

	static void			suspendAllThreads( DWORD exceptionThread ) noexcept;

protected:

	virtual void run( void ) = 0;
	virtual ~Thread( void );

private:

	volatile bool					_stopRequest;
	uintptr_t volatile				_threadHandle;
	UINT							_threadID;

	friend unsigned __stdcall		threadStarter( void* thread );
			
	void							updateHardwareThread( void ) const noexcept;

	static Thread*					g_threads[256];
	static volatile unsigned int	g_numThreads;
};