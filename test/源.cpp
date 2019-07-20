#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")



using namespace std;




int main(int argc, char* argv[])
{
	SOCKET m_Client;
	//初始化WSA  
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	WSAStartup(sockVersion, &wsaData);


	//创建套接字  
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	slisten == INVALID_SOCKET;


	//绑定IP和端口  
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = inet_addr("0.0.0.0");
	bind(slisten, (LPSOCKADDR)& sin, sizeof(sin));
	

	//开始监听  
	listen(slisten, 5);

	//循环接收数据  
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];
	string str;
	while (true)
	{
		printf("等待连接...\n");
		m_Client = accept(slisten, (SOCKADDR*)& remoteAddr, &nAddrlen);

		printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
		// 收数据
		
		while (1)
		{
			recv(m_Client, revData, 200, 0);
			str = revData;
			cout << str << endl;

			str += "fuck";

			send(m_Client, str.data(), 200, 0);
		}


		closesocket(m_Client);
	}

	closesocket(slisten);
	WSACleanup();
	return 0;
}
