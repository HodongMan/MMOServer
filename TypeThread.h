#pragma once

enum class ThreadState
{
	THREAD_STATE_STOP,
	THREAD_STATE_SLEEP,
	THREAD_STATE_BUSY,
	THREAD_STATE_END,
	THREAD_STATE_PENDING,
	THREAD_STATE_COUNT
};


#if _WIN32
#define THREAD_ID											HANDLE
#define THREAD_SINGNAL										HANDLE
#define THREAD_SINGNAL_INIT(x)								x = CreateEvent(NULL, TRUE, FALSE, NULL)
#define THREAD_SINGNAL_DELETE(x)							CloseHandle(x)
#define THREAD_SINGNAL_SET(x)								SetEvent(x)
#define THREAD_MUTEX										CRITICAL_SECTION
#define THREAD_MUTEX_INIT(x)								InitializeCriticalSection(&x)
#define THREAD_MUTEX_DELETE(x)								DeleteCriticalSection(&x)
#define THREAD_MUTEX_LOCK(x)								EnterCriticalSection(&x)
#define THREAD_MUTEX_UNLOCK(x)								LeaveCriticalSection(&x)	
#else
#define THREAD_ID											pthread_t
#define THREAD_SINGNAL										pthread_cond_t
#define THREAD_SINGNAL_INIT(x)								pthread_cond_init(&x, NULL)
#define THREAD_SINGNAL_DELETE(x)							pthread_cond_destroy(&x)
#define THREAD_SINGNAL_SET(x)								pthread_cond_signal(&x);
#define THREAD_MUTEX										pthread_mutex_t
#define THREAD_MUTEX_INIT(x)								pthread_mutex_init (&x, NULL)
#define THREAD_MUTEX_DELETE(x)								pthread_mutex_destroy(&x)
#define THREAD_MUTEX_LOCK(x)								pthread_mutex_lock(&x)
#define THREAD_MUTEX_UNLOCK(x)								pthread_mutex_unlock(&x)		
#endif