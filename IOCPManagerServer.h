#pragma once


#include "Thread/Thread.h"
#include "Thread/Mutex.h"

class PerConnectionData;
class IocpWorkerThread;

enum class SocketOperation
{  
	AcceptState, 
	ReadState, 
	WriteState,
	InvalidState
};


class SocketContext
{
public:
	SocketContext( SOCKET socket, SocketOperation socketOperation );
	~SocketContext( void );

private:

	PerConnectionData * _userData;

	Lock				_mutex;
	Lock				_writerMutex;
};

/*
class IOCPManagerServer : public Thread
{
public:
	static const unsigned int MAX_BUFFER_LEN = 8192 / 2;
	static const unsigned int RECOMMENDED_MESSAGE_SIZE = 1400;
	static const unsigned int NUM_MUTEXES = 2048;
	static const unsigned int MAX_NUM_THREADS = 16;

	IOCPManagerServer( unsigned short portNumber );
	virtual ~IOCPManagerServer( void );

	virtual void run( void ) noexcept;

};
*/