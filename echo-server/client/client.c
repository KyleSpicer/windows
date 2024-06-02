#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <wchar.h>

#pragma comment(lib, "Ws2_32.lib")

#define LAST_ERROR WSAGetLastError()
#define DEFAULT_PORT "5001"
#define SERVER_IP "localhost"
#define DEFAULT_BUFF_LEN 512

// Reference: https://learn.microsoft.com/en-us/windows/win32/winsock/winsock-client-application

INT wmain(INT argc, WCHAR* argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	int iMainReturnValue = 0;

	// create client socket
	WSADATA wsaData = { 0 };
	struct addrinfo* result = { 0 };
	struct addrinfo* ptr = { 0 };
	struct addrinfo hints = { 0 };

	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	hints.ai_family = AF_INET; // ipv4 only
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	// resolve the server address and port
	iResult = getaddrinfo(SERVER_IP, DEFAULT_PORT, &hints, &result);
	if (0 != iResult)
	{
		wprintf(L"getaddrinfo failed: %d\n", iResult);
		iMainReturnValue = 1;
		goto CLIENT_SOCK_CLEANUP;
	}

	SOCKET ClientSocket = INVALID_SOCKET;
	ptr = result;

	// create client socket
	ClientSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (INVALID_SOCKET == ClientSocket)
	{
		wprintf(L"Error at socket(): %ld\n", LAST_ERROR);
		freeaddrinfo(result);
		iMainReturnValue = 2;
		goto CLIENT_SOCK_CLEANUP;
	}

	// connect to server
	iResult = connect(ClientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (SOCKET_ERROR == iResult)
	{
		closesocket(ClientSocket);
		ClientSocket = INVALID_SOCKET;
	}
	freeaddrinfo(result);

	if (INVALID_SOCKET == ClientSocket)
	{
		wprintf(L"Unable to connect to server...\n");
		iMainReturnValue = 3;
		goto CLIENT_SOCK_CLEANUP;
	}

	// send and receive from server
	int recvBuffLen = DEFAULT_BUFF_LEN;
	const WCHAR* sendBuff = L"This is a test.";
	WCHAR recvBuff[DEFAULT_BUFF_LEN] = { 0 }; 
	int iBytesSent = send(ClientSocket, sendBuff, (int)(wcslen(sendBuff) * sizeof(WCHAR)), 0);
	if (SOCKET_ERROR == iBytesSent)
	{
		wprintf(L"send failed: %d\n", LAST_ERROR);
		iMainReturnValue = 4;
		goto CLOSE_CLIENT_SOCKET;
	}

	wprintf(L"Bytes Sent: %ld\n", iBytesSent);

	// shutdown connection for sending, because there is no more data 
	// client can still use ConnectSocket for receiving
	iResult = shutdown(ClientSocket, SD_SEND);
	if (SOCKET_ERROR == iResult)
	{
		wprintf(L"shutdown failed: %d\n", LAST_ERROR);
		iMainReturnValue = 5;
		goto CLOSE_CLIENT_SOCKET;
	}

	// receive data until server closes connection
	do {
		iResult = recv(ClientSocket, recvBuff, recvBuffLen, 0);
		if (iResult > 0)
		{
			wprintf(L"Bytes Received: %d\n", iResult);
		}
		else if (iResult == 0)
		{
			wprintf(L"Connection closed\n");
		}
		else
		{
			wprintf(L"recv failed: %d\n", LAST_ERROR);
		}
	} while (iResult > 0);

CLOSE_CLIENT_SOCKET:
	closesocket(ClientSocket);

CLIENT_SOCK_CLEANUP:
	WSACleanup();

EXIT_CLIENT_MAIN:
	return iMainReturnValue;
}