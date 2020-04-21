
#pragma once


#include "Mutex.h"


class SocketWindow
{
public:

	SocketWindow( SOCKET socket, bool deferredSocketInit = false );
	virtual ~SocketWindow( void );

	virtual int					start( void ) noexcept = 0;
	virtual int					onSocketWriteReady( const int byteCount, OVERLAPPED* overapped ) noexcept = 0;
	virtual int					onSocketReadReady( const int byteCount, OVERLAPPED* overapped ) noexcept = 0;

	virtual void				onSocketError( int systemError, OVERLAPPED* overapped ) noexcept = 0;
	virtual void				onSocketClose( void ) noexcept = 0;


protected:
	Lock						_lock;


private:
	SOCKET						_socket;
	//Error						_error;
	int							_systemError;
	char						_localAddressString[22];
	char						_remoteAddressString[22];
	struct sockaddr_in			_localAddress;
	struct sockaddr_in			_remoteAddress;
	volatile long				_refCount;
	bool						_isRegistred;
	bool						_hasCalledClose;
	
};