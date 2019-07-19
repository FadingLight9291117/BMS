#ifndef _INC_LOGINCONTRLLER_
#define _INC_LOGINCONTRLLER_

#include<iostream>
#include"Factory.h"
using namespace std;

class LoginController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNumber,int password);								// 处理前端请求，返回数据库查询结果
};

int LoginController::actionRequests(long long cardNumber,int password)
{
	QueryDAO* query = factory.createQueryDAO();					// 创建一个查询DAO

	if(cardNumber % 2 == 1 )
	{
		CreditCard* card = query->queryCredit(cardNumber);
		if (card == NULL)
			return 0;
		if(card->getPassword() == password)
			return 1;
		return 0;
	}
	if(cardNumber % 2 == 0 )
	{
		DepositCard* card = query->queryDeposit(cardNumber);
		if (card == NULL)
			return 0;
		if(card->getPassword() == password)
			return 1;
		return 0;
	}

}

#endif // !_INC_LOGINCONTRLLER
