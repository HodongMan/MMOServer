#pragma once


class Netstat
{
public:

	Netstat*			getInstance( void ) const noexcept;

private:

	Netstat( void );
	~Netstat( void );

	bool				init( void ) noexcept;
	void				updateData( void ) noexcept;
};