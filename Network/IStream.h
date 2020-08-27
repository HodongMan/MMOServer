#pragma once


class INetworkStream
{
public:
	INetworkStream( void ) {}
	virtual ~INetworkStream( void ) {}

	virtual int		getUsed( void ) const noexcept = 0;
	virtual int		read( void* buffer, const int size ) noexcept = 0;;
	virtual int		readSkip( const int size ) noexcept = 0;
	virtual int		peek(void* buffer, const int size) noexcept = 0;
	virtual int		write( const void* buffer, const int size ) noexcept = 0;
	virtual int		writeSkip( const int size ) noexcept = 0;
};