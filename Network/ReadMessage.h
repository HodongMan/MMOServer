#pragma once

#include "TypeSocket.h"

class WriteBuffer;
class INetworkStream;

class ReadMessage
{
public:
	ReadMessage( void );
	ReadMessage( INetworkStream* stream );
	ReadMessage( ReadMessage& readMessage, INetworkStream* stream );
	~ReadMessage( void );


	bool				isMessageComplete( void ) const noexcept;
	bool				decodeHeader( void ) noexcept;
	bool				isSystemMessage( void ) const noexcept;
	int					getNamespace( void ) const noexcept;
	bool				decodeDelimiter( void ) const noexcept;

	void				isTypeChecked( void ) const noexcept;
	int					getPacketSize( void ) const noexcept;
	INetworkStream*		getStream( void ) const noexcept;

	void				setStream( INetworkStream* stream) noexcept;

	void				detachToStream( INetworkStream& stream) noexcept;
	bool				attachToStream( INetworkStream& stream, INetworkStream& tempStorage ) noexcept;

private:
	class DetachedMessage
	{
	public:
		int				m_packetSize;
		DelimiterType	m_delimiter;
		bool			m_isTypeChecked;
		bool			m_isSystemMessage;
		int				m_namespace;
	};

	INetworkStream*		m_stream;
	int					m_packetSize;
	bool				m_isTypeChecked;
	bool				m_isSystemMessage;
	int					m_namesSpace;
	bool				m_ownStream;
	DelimiterType		m_delimiterType;
};