#pragma once


class CommonSocket
{
public:
	CommonSocket( SOCKET socket );
	virtual ~CommonSocket( void );

	virtual int					start( void ) noexcept = 0;
	virtual void				close( void ) noexcept = 0;

	void						retain( void ) noexcept;
	void						release( void ) noexcept;

	int							regist( void ) noexcept;
	void						unregist( void ) noexcept;


	SOCKET						getSocket( void ) const noexcept;
	


	const char*					getLocalAddressString( void ) const noexcept;
	const struct sockaddr_in&	getLocalAddress( void ) const noexcept;
	void						setLocalAddress( const struct sockaddr_in& address ) noexcept;

	const char*					getRemoteAddressString( void ) const noexcept;
	const struct sockaddr_in&	getRemoteAddress( void ) const noexcept;
	void						setRemoteAddress( const struct sockaddr_in& address ) noexcept;

private:

	SOCKET						m_socket;
	char						m_localAddressString[22];
	char						m_remoteAddressString[22];
	struct sockaddr_in			m_localAddress;
	struct sockaddr_in			m_remoteAddress;

	volatile long				m_referenceCount;
};