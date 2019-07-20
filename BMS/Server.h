#ifndef _INC_RESPONSE_
#define _INC_RESPONSE_

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <winsock2.h>
#include<string>
#include<map>
#include "Message.h"
#include "Controller.h"

#pragma comment(lib, "ws2_32.lib")




using namespace std;

class Server
{
private:
	int net();
	map<string, string>* handle(map<string, string>* m);
public:
	void run();
};



int Server::net()
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
	char sendData[255];
	string str;
	while (true)
	{
		printf("等待连接...\n");
		m_Client = accept(slisten, (SOCKADDR*)& remoteAddr, &nAddrlen);

		printf("接受到一个连接：%s \r\n", inet_ntoa(remoteAddr.sin_addr));
		// 收数据


		//接受消息
		recv(m_Client, revData, 200, 0);

		string recStr = revData;

		map<string, string> m = Message::parse(recStr);

		map<string,string> *mm = handle(&m);
			
		string sendStr = Message::serialize(m);

		const char* sendData = sendStr.data();
		
		//发送消息
		send(m_Client, sendData, 200, 0);

		closesocket(m_Client);
	}

	closesocket(slisten);
	WSACleanup();
	return 0;
}

map<string, string>* Server::handle(map<string, string>* m)
{
	map<string, string>* mm = new map<string, string>;
	string name = (*m)["name"];//判断调用哪个控制器


	if (name.compare("LoginController") == 0)  //登陆
	{
		string cardNumber = (*m)["cardNumber"];//卡号
		string password = (*m)["password"];//密码

		long long cardNum = stoll(cardNumber);
		int passwd = stoi(password);

		//--………………………………调用控制器，获取数据
		LoginController controller;
		(*mm)["check"] = to_string(controller.actionRequests(cardNum, passwd));

	}
	else if (name.compare("QueryController") == 0)   //查询余额
	{
		long long cardNum = stoll((*m)["cardNumber"]);//卡号

			//调用查询控制器，获取数据
		QueryCardController controller;
		map<string, string>* mk = new map<string, string>;
		mk = controller.actionRequests(cardNum);

		(*mm)["money"] = (*mk)["balance"];
		(*mm)["check"] = (*mk)["state"];

	}
	else if (name.compare("ChangePasswordController") == 0)  //修改密码
	{

	}
	else if (name.compare("SaveController") == 0)  //存钱
	{
		string cardNumber = (*m)["cardNumber"];//卡号
		string money = (*m)["money"];
		//--………………………………调用控制器，获取数据
		SaveController controller;
		(*mm)["check"] = to_string(controller.actionRequests(stoll(cardNumber), stoi(money)));
	}
	else if (name.compare("WithdrawController") == 0)  //取钱
	{

	}
	else if (name.compare("TransController") == 0) //转账
	{

	}
	else if (name.compare("OpenAccountController") == 0)             //开户
	{
		string cardNumber = (*m)["cardNumber"];//卡号
		string amount = (*m)["amount"];  //额度，信用卡为正数、储蓄卡为-1
		string phone = (*m)["phone"];//电话
		string password = (*m)["password"]; //密码
		string username = (*m)["username"]; //用户姓名

		//控制器
		OpenController controller;
		(*mm)["check"] = to_string(controller.actionRequests(stoll(cardNumber), stoll(phone), stoi(password), stoi(amount), username));

	}
	else if (name.compare("LossReportingController") == 0)              //挂失
	{
		string cardNumber = (*m)["cardNumber"];//卡号

		//控制器
		LossReportingController controller;
		(*mm)["check"] = to_string(controller.actionRequests(stoll(cardNumber)));

	}
	else
	{
		(*mm)["check"] = "0";
	}
	return mm;
}

void Server::run()
{
	net();
}
#endif // !_INC_RESPONSE_