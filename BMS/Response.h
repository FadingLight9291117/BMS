#ifndef _INC_SERVER_
#define _INC_SERVER_

#include<iostream>
#include<string>
#include<map>
#include"Controller.h"
#include<sstream>
#include "Message.h"
using namespace std;

class Response
{
public:
	map<string, string>* response(map<string, string>* m)
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
		else
		{
			(*mm)["check"] = "0";
		}
		return mm;
	}

};

#endif // 