
#ifndef _INC_SAVECONTROLLER_
#define _INC_SAVECONTROLLER_


#include<iostream>
#include"Factory.h"
using namespace std;


class SaveController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNumber,int amount);								
};

int SaveController::actionRequests(long long cardNumber,int amount)
{	
	UpdateDAO* update = factory.createUpdateDAO();       // 创建一个更新DAO
	if(cardNumber % 2 == 1 )
	{
		return update->update(cardNumber,amount,1);
		
	}
	if(cardNumber % 2 == 0 )
	{
		return update->update(cardNumber,amount,1);
		

	}

}

#endif // !_INC_SAVECONTROLLER_