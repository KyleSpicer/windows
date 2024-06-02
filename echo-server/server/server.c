#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <wchar.h>

#include "ControlHandler.h"

#pragma comment(lib, "Ws2_32.lib")

#define LAST_ERROR WSAGetLastError()
#define DEFAULT_PORT "5001"
#define DEFAULT_BUFF_LEN 512

// references:
// winapi server: https://learn.microsoft.com/en-us/windows/win32/winsock/winsock-server-application


INT wmain(INT argc, WCHAR* argv[])
{
	// TODO: add getopt for argument parsing
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	INT iMainReturnValue = 0;

	// set control handler
	if (FALSE == SetControlHandler())
	{
		iMainReturnValue = 1;
		goto EXIT_MAIN;
	}

	// initialize Windows Socket
	WSADATA wsaData = { 0 };	// contains info about WinSock implementation.
	int iWsaDataResult = { 0 };

	// initiate use of WS2_32.dll, requests WinSock version 2.2
	iWsaDataResult = WSAStartup(MAKEWORD(2, 2), &wsaData); 
	if (0 != iWsaDataResult) {
		wprintf(L"WSA Startup failed: %d\n", iWsaDataResult);
		iMainReturnValue = 2;
		goto EXIT_MAIN;
	}

	struct addrinfo* result = { 0 };
	struct addrinfo* ptr = { 0 };
	struct addrinfo hints = { 0 };

	hints.ai_family = AF_INET; // ipv4 only
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	// resolve local addr + port used by server
	iWsaDataResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (0 != iWsaDataResult)
	{
		wprintf(L"getaddrinfo failed: %d\n", iWsaDataResult);
		goto SERVER_SOCK_CLEANUP;
	}

	// create server socket
	SOCKET ServerSocket = INVALID_SOCKET;
	ServerSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	// ABCs for valid socket
	if (INVALID_SOCKET == ServerSocket)
	{
		wprintf(L"Error at socket(): %ld\n", LAST_ERROR);
		iMainReturnValue = 3;
		freeaddrinfo(result);
		goto SERVER_SOCK_CLEANUP;
	}

	// Setup TCP listening socket (BIND)
	iWsaDataResult = bind(ServerSocket, result->ai_addr, (int)result->ai_addrlen);
	if (SOCKET_ERROR == iWsaDataResult)
	{
		wprintf(L"bind failed with error: %d\n", LAST_ERROR);
		freeaddrinfo(result);
		iMainReturnValue = 4;
		goto SERVER_SOCK_CLEANUP;
	}
	freeaddrinfo(result);

	// (LISTEN)
	if (SOCKET_ERROR == listen(ServerSocket, SOMAXCONN))
	{
		wprintf(L"Listen failed with error: %ld\n", LAST_ERROR);
		iMainReturnValue = 5;
		goto CLOSE_SERVER_SOCKET;
	}

	wprintf(L"Server listening on port: %S\n", DEFAULT_PORT);
	while (ServerActive())
	{
		// TODO: Add timeout for Client accept()
		// TODO: Use Poll to handle multiple connections
		SOCKET ClientSocket = INVALID_SOCKET;
		ClientSocket = accept(ServerSocket, NULL, NULL);
		if (INVALID_SOCKET == ClientSocket)
		{
			wprintf(L"accept failed: %d\n", LAST_ERROR);
			goto SERVER_SOCK_CLEANUP;
		}

		WCHAR recvBuff[DEFAULT_BUFF_LEN] = { 0 };
		int iRecvResult = 0;
		int iSendResult = 0;

		iRecvResult = recv(ClientSocket, recvBuff, DEFAULT_BUFF_LEN, 0);
		if (iRecvResult > 0)
		{
			wprintf(L"Bytes received: %d\n", iRecvResult);

			// echo back to client
			iSendResult = send(ClientSocket, recvBuff, iRecvResult, 0);
			if (SOCKET_ERROR == iSendResult)
			{
				wprintf(L"send failed: %d\n", LAST_ERROR);
				closesocket(ClientSocket);
			}

			wprintf(L"Bytes sent: %d\n", iSendResult);
			iRecvResult = shutdown(ClientSocket, SD_SEND);
			if (SOCKET_ERROR == iRecvResult)
			{
				wprintf(L"shutdown failed:%d\n", LAST_ERROR);
			}
			closesocket(ClientSocket);
			goto CLOSE_SERVER_SOCKET;
		}
	}


CLOSE_SERVER_SOCKET:
	closesocket(ServerSocket);

SERVER_SOCK_CLEANUP:
	WSACleanup();

EXIT_MAIN:
	return iMainReturnValue;
}