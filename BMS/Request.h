#ifndef _INC_REQUEST_
#define _INC_REQUEST_
#include<iostream>
#include<string>
#include<map>
#include "Message.h"
#include <winsock2.h>
#pragma comment (lib,"WS2_32.lib")

class Request
{
public:
	map<string, string>* request(map<string, string>* m)
	{
		string str = Message::serialize(*m);

		const char* msg = str.data();
		char* result;
		net(msg, result);
		string strs = result;

		map<string, string> mm = Message::parse(strs);
		return &mm;
	}

private:
	int net(const char* msg, char*& result)
	{
		//加载套接字库
		WSADATA wsadata;
		int iRet = WSAStartup(MAKEWORD(2, 2), &wsadata);
		if (iRet != 0)
		{
			cout << "套接字库加载失败" << endl;
			return -1;
		}
		else
		{
			cout << "套接字库加载成功" << endl;
		}
		//创建套接字
		SOCKET clientsocket;
		clientsocket = socket(AF_INET, SOCK_STREAM, 0);
		if (clientsocket == INVALID_SOCKET)
		{
			cout << "套接字创建失败" << endl;
			return -1;
		}
		else
		{
			cout << "套接字创建成功" << endl;
		}

		//初始化客户端地址族变量
		SOCKADDR_IN addrSrv;
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		addrSrv.sin_port = htons(8000);

		//连接
		iRet = connect(clientsocket, (SOCKADDR*)& addrSrv, sizeof(SOCKADDR));
		if (iRet == SOCKET_ERROR)
		{
			cout << "连接失败" << endl;
			return -1;
		}
		else
		{
			cout << "连接成功" << endl;
		}
		result = new char[255];
		//发送数据
		send(clientsocket, msg, 255, 0);
		recv(clientsocket, result, 255, 0);
		closesocket(clientsocket);
		WSACleanup();
		return 1;
	}
};

#endif // !_INC_REQUEST_
