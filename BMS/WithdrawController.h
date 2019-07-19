#ifndef _INC_WITHDRAWCONTROLLER_
#define _INC_WITHDRAWCONTROLLER_



#include<iostream>
#include"Factory.h"
using namespace std;


class WithdrawController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardnumber, int change);						// 处理前端请求，返回数据库查询结果
};

int WithdrawController::actionRequests(long long cardnumber,int change)
{
	QueryDAO* query = factory.createQueryDAO();					// 创建一个查询DAO
	UpdateDAO* update = factory.createUpdateDAO();
	if(cardnumber % 2 == 1 )            //奇数信用卡
	{
		CreditCard* card = query->queryCredit(cardnumber);
		if(change > card->getBalance())
		{
			return 0;
		}
		else
		{
			return update->update(cardnumber, change, 0);
		}
	}
	else           //偶数储蓄卡
	{
		DepositCard* card = query->queryDeposit(cardnumber);
		if(change > card->getBalance())
		{
			return 0;
		}
		else
		{
			return update->update(cardnumber, change, 0);
		}
	}

}

#endif // !_INC_WITHDRAWCONTROLLER_