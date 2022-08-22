#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include<WinSock2.h>
#include<string>


#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData WseData;

	WSAStartup(MAKEWORD(2, 2), &WseData);
	

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServerSOCKADDR.sin_port = htons(3000);

	int Result = connect(ServerSocket, (SOCKADDR*)&ServerSOCKADDR, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		cout << "fail connect : " << GetLastError() << endl;
		exit(-1);
	}



	char Buffer[1024] = { 0, };
	int RecvBytes = recv(ServerSocket, Buffer, 1024, 0);

	cout << Buffer << endl;
	

	int SendBytes = send(ServerSocket, Buffer, RecvBytes, 0);
	

	WSACleanup();

	return 0;
}