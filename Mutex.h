#pragma once


class Lock
{
public:

	Lock( int spinLockCount = 0 );
	virtual ~Lock( void );

	void									lock( void ) noexcept;
	bool									tryLock( void ) noexcept;
	void									unlock( void ) noexcept;

	__forceinline const	CRITICAL_SECTION&	getCriticalSection( void ) const noexcept;

	unsigned int							getLockCount( void ) noexcept;

private:

	CRITICAL_SECTION						_mutex;
	unsigned int							_lockCount;
};


class SpinLock
{
public:

	SpinLock( void );
	virtual ~SpinLock( void );

	void				lock( void ) noexcept;
	bool				tryLock( void ) noexcept;
	void				unlock( void ) noexcept;

	unsigned int		getLockCount( void ) const noexcept;

private:

	volatile long		_lock;
	unsigned int		_lockCount;
};


template < typename MUTEX >
class LockGuard
{
public:

	LockGuard( MUTEX& mutex )
		: _mutex{ mutex }
	{
		_mutex->lock();
	}

	~LockGuard( void )
	{
		unlock();
	}

	__forceinline void		newLock( MUTEX& mutex ) noexcept
	{
		_mutex = mutex;
		_mutex->lock();
	}

	__forceinline void		unlock( void ) noexcept
	{
		mutex->unlock();
		_mutex = nullptr;
	}

	__forceinline bool		isLocked( void ) const noexcept
	{
		return nullptr != _mutex;
	}


private:
	MUTEX* _mutex;
};

using Locker		= LockGuard<Lock>;
using SpinLocker	= LockGuard<SpinLock>;

