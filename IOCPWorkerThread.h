#pragma once

#include "Thread/Thread.h"


class IOCPServer;


class IOCPWorkerThread : public Thread
{
public:
	IOCPWorkerThread( IOCPServer* server);
	virtual ~IOCPWorkerThread( void );
};