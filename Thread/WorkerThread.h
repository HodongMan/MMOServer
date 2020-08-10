#pragma once


class IOCoreManager;


class WorkerThread
{
public:

	WorkerThread( IOCoreManager* manager );
	~WorkerThread( void );

protected:

	virtual			void run( void ) noexcept;
private:

	IOCoreManager* m_IoManager;
};