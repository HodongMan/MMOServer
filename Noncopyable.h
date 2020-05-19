#pragma once


class Noncopyable
{
protected:
	Noncopyable( void ) = default;
	~Noncopyable( void ) = default;

private:
	Noncopyable( const Noncopyable& rhs ) noexcept = delete;
	void operator=( const Noncopyable& rhs ) noexcept = delete;
};