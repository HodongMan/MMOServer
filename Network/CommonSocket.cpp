#include "../pch.h"

#include "CommonSocket.h"


CommonSocket::CommonSocket( SOCKET socket )
	: m_socket{ socket }
	, m_referenceCount{ 0 }
{
	memset( &m_remoteAddress, 0, sizeof( m_remoteAddress ) );
	memset( &m_localAddress, 0, sizeof( m_localAddress ) );
}

CommonSocket::~CommonSocket( void )
{

}

void CommonSocket::retain( void ) noexcept
{
	int ref = _InterlockedIncrement( &m_referenceCount);
}

void CommonSocket::release( void ) noexcept
{

}

int CommonSocket::regist(void) noexcept
{
	return 0;
}

void CommonSocket::unregist(void) noexcept
{

}

SOCKET CommonSocket::getSocket(void) const noexcept
{
	return m_socket;
}

const char * CommonSocket::getLocalAddressString(void) const noexcept
{
	return nullptr;
}

const sockaddr_in & CommonSocket::getLocalAddress(void) const noexcept
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

void CommonSocket::setLocalAddress(const sockaddr_in & address) noexcept
{
	m_localAddress = address;
}

const char * CommonSocket::getRemoteAddressString(void) const noexcept
{
	return nullptr;
}

const sockaddr_in & CommonSocket::getRemoteAddress(void) const noexcept
{
	// TODO: 여기에 반환 구문을 삽입합니다.
}

void CommonSocket::setRemoteAddress(const sockaddr_in & address) noexcept
{
}
