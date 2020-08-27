#pragma once


class Semaphore
{
public:

	Semaphore( long initialCount = 0, long maximunCount = 1 );
	~Semaphore( void );

	bool		acquire( void ) noexcept;
	void		release( void ) noexcept;

private:
	
	HANDLE		_semaphore;
};