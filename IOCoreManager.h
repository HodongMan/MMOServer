#pragma once


class IOCoreManager
{
public:

	int							start( const uint32_t maxThreadCount, const uint32_t numThreadPerCPU ) noexcept;
	void						stop( void ) noexcept;
	
	void						waitCompletion( const int timeOut = INFINITE ) noexcept;

	static IOCoreManager&		getInstance( void ) noexcept; 
private:
	IOCoreManager( void );
	~IOCoreManager( void );

	HANDLE				m_serverHandle;
	uint32_t			m_workerCount;

	bool				m_isStopped;

};