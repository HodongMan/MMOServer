#pragma once

#include "TypeSocket.h"


class IWriteableDataStream
{
public:
	virtual ConnectionErrorType send( const void* data, unsigned int dataLen ) noexcept = 0;
	virtual unsigned int getRecommendedBufferSize( void ) const noexcept = 0;
};

class FileStream : public IWriteableDataStream
{
public:
	FileStream( FILE* file ) 
		: m_file( file) 
	{

	}

	virtual ~FileStream( void ) 
	{ 
		fclose(m_file); 
	}

	virtual ConnectionErrorType send( const void* data, unsigned int datalen ) noexcept 
	{ 
		fwrite( data, datalen, 1, m_file); 

		return ConnectionErrorType::CONNECTION_OK; 
	}

	virtual unsigned int getRecommendedBufferSize( void ) const noexcept 
	{ 
		return 8192; 
	}
	
private:
	FILE*			m_file;
};
