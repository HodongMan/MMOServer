#pragma once

#include "pch.h"

const int MAX_WRITE_SIZE	= 32 * 1024;
const int MAX_READ_SIZE		= 8 * 1024;


struct WriteRequest
{
	char data[MAX_WRITE_SIZE];
	WSAOVERLAPPED overlapped;
	WSABUF winsockBuf;
	int bytesSent;
	int bytesToSend;
};

struct ReadRequest
{
	char data[MAX_READ_SIZE];
	WSAOVERLAPPED overlapped;
	WSABUF winsockBuf;
	int bytesExpected;
	int bytesRead;
};
