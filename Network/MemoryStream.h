#pragma once

#include "IStream.h"


class MemoryStream : public IStream
{
public:
	MemoryStream( void* buffef, const int length, bool ownsStreamFlag = false );
	virtual ~MemoryStream( void );

private:
	int*				m_buffer;
	int					m_length;
	int					m_offset;
	bool				m_ownsStream;
};