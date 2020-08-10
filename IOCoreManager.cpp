#include "pch.h"

#include "IOCoreManager.h"


int IOCoreManager::start( const uint32_t maxThreadCount, const uint32_t numThreadPerCPU ) noexcept
{
	return 0;
}

void IOCoreManager::stop(void) noexcept
{
}

void IOCoreManager::waitCompletion(const int timeOut) noexcept
{
}

IOCoreManager& IOCoreManager::getInstance( void ) noexcept
{
	static IOCoreManager manager;
	return manager;
}

IOCoreManager::IOCoreManager( void )
{

}

IOCoreManager::~IOCoreManager( void )
{

}
