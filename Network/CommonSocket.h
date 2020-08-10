#pragma once


class CommonSocket
{
public:
	CommonSocket( SOCKET socket );
	virtual ~CommonSocket( void );

	virtual int			start( void ) noexcept = 0;

private:

	SOCKET						m_socket;
	char						m_localAddressString[22];
	char						m_remoteAddressString[22];
	struct sockaddr_in			m_localAddress;
	struct sockaddr_in			m_remoteAddress;

	volatile long				my_referenceCount;
};