#pragma once


class Packet
{
public:

private:
	static Packet*			create(unsigned int theTransportSize = 512) noexcept;
	static Packet*			create(const Packet* packet) noexcept;

	static void				deallocate(Packet*& packet) noexcept;
	static void				cleanUp( void ) noexcept;

	inline unsigned short	getBinarySize( void ) const noexcept;
	const unsigned char*	getBinaryData( void ) const noexcept;

	const unsigned short	getWriteOffset( void ) const noexcept;
	void					setWriteOffset( unsigned short writeOffset ) noexcept;

	const unsigned char*	getData( void ) const noexcept;
	void					appendData( const void* data, unsigned int dataLen ) noexcept;
	void					clear( void ) noexcept;

	const unsigned short	getPacketDataCapacity( void ) const noexcept;

private:

	Packet( void );
	Packet( unsigned char* allocatedBuffPtr, unsigned int transportSize );
	explicit Packet( const Packet& packet );

	virtual ~Packet( void );

	static Packet* getNewPacket( unsigned int theTransportSize );

	unsigned char*			m_rawDataBuffer;
	unsigned int			m_rawDataBufferLen;

	unsigned short&			m_writeOffset;
	unsigned short			m_transportSize;
};