#ifndef _INC_LOSS_
#define _INC_LOSS_

#include<iostream>
#include<string>
#include "Factory.h"
using namespace std;

class LossReportingController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNumber);								
};

int LossReportingController::actionRequests(long long cardNumber)
{	
	cout << 1 << endl;
	UpdateDAO* update = factory.createUpdateDAO(); // 创建一个更新DAO
	QueryDAO* query = factory.createQueryDAO();					// 创建一个查询DAO
	if( cardNumber % 2 == 1 ) //奇数为信用卡
	{
		if(query->queryCredit(cardNumber)->getState() == "abnormal" )
			return 0;
		else
			cout << 3 << endl;
			return  update->update(cardNumber,"abnormal");
	}

	if( cardNumber % 2 == 0 )   //偶数为储蓄卡
	{
		if (query->queryDeposit(cardNumber)->getState() == "abnormal")
			return 0;
		else
			cout << 2 << endl;
			return  update->update(cardNumber,"abnormal");	
	}
}
#endif // !_INC_LOSS_