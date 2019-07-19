#ifndef _INC_QUERYCARDCONTROLLER_
#define _INC_QUERYCARDCONTROLLER_


#include<iostream>
#include<string>
#include"Factory.h"
class QueryCardController
{
protected:
	map<string, string> mm;
	DAOFactory factory;
public:
	map<string,string> *actionRequests(long long cardNumber);								// 处理前端请求，返回数据库查询结果
};

map<string,string> *QueryCardController::actionRequests(long long cardNumber)
{
	QueryDAO* query = factory.createQueryDAO();					// 创建一个查询DAO
	if(cardNumber % 2 == 1 )            //奇数信用卡
	{
		CreditCard* card = query->queryCredit(cardNumber);
		mm["idCard"] = to_string(card->getUserIDCard());
		mm["cardNumber"] = to_string(card->getCardnum());
		mm["password"] = to_string(card->getPassword());
		mm["phone"] = to_string(card->getPhone());
		mm["credit_line"] = to_string(card->getCreditline());
		mm["balance"] = to_string(card->getBalance());
		mm["state"] = card->getState();
		return &mm;
		
	}
	else           //偶数储蓄卡
	{
		DepositCard* card = query->queryDeposit(cardNumber);
		mm["idCard"] = to_string(card->getUserIDCard());
		mm["cardNumber"] = to_string(card->getCardnum());
		mm["password"] = to_string(card->getPassword());
		mm["phone"] = to_string(card->getPhone());
		mm["balance"] = to_string(card->getBalance());
		mm["state"] = card->getState();
		return &mm;
	}


}

#endif // !_INC_QUERYCONTROLLER_