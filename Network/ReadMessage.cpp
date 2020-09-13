#include "../pch.h"

#include "ReadMessage.h"

#include "IStream.h"


ReadMessage::ReadMessage( void )
	: m_stream{ nullptr }
	, m_packetSize{ 0 }
	, m_isTypeChecked{ false }
	, m_isSystemMessage{ false }
	, m_namesSpace{ 0 }
	, m_ownStream{ false }
	, m_delimiterType{ 0 }
{

}

ReadMessage::ReadMessage(INetworkStream * stream)
	: m_stream{ stream }
	, m_packetSize{ 0 }
	, m_isTypeChecked{ false }
	, m_isSystemMessage{ false }
	, m_namesSpace{ 0 }
	, m_ownStream{ false }
	, m_delimiterType{ 0 }
{

}

ReadMessage::ReadMessage(ReadMessage& readMessage, INetworkStream * stream)
	: m_stream{ stream }
	, m_packetSize{ stream->getUsed() }
	, m_isTypeChecked{ readMessage.m_isTypeChecked }
	, m_isSystemMessage{ readMessage.m_isSystemMessage }
	, m_namesSpace{ readMessage.m_namesSpace }
	, m_ownStream{ false }
	, m_delimiterType{ readMessage.m_delimiterType }
{

}

ReadMessage::~ReadMessage( void )
{
	if ( true == m_ownStream )
	{
		delete m_stream;
	}
}

bool ReadMessage::isMessageComplete(void) const noexcept
{
	return false;
}

bool ReadMessage::decodeHeader(void) noexcept
{
	return false;
}

bool ReadMessage::isSystemMessage(void) const noexcept
{
	return m_isSystemMessage;
}

int ReadMessage::getNamespace(void) const noexcept
{
	return 0;
}

bool ReadMessage::decodeDelimiter(void) const noexcept
{
	return false;
}

void ReadMessage::isTypeChecked(void) const noexcept
{
}

int ReadMessage::getPacketSize(void) const noexcept
{
	return 0;
}

INetworkStream * ReadMessage::getStream(void) const noexcept
{
	return nullptr;
}

void ReadMessage::setStream(INetworkStream * stream) noexcept
{
}

void ReadMessage::detachToStream(INetworkStream & stream) noexcept
{
}

bool ReadMessage::attachToStream(INetworkStream & stream, INetworkStream & tempStorage) noexcept
{
	return false;
}
