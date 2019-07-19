#ifndef _INC_TRANSCONTROLER_
#define _INC_TRANSCONTROLER_

#include<iostream>
#include"Factory.h"

using namespace std;

class TransController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNum1, long long cardNum2,int change);
};

int TransController::actionRequests(long long cardNum1, long long cardNum2,int change)
{
	UpdateDAO* update = factory.createUpdateDAO();
	int m = update->update(cardNum1, change, 0);
	if (m == 0)
	{
		return 0;
	}
	else
	{
		update->update(cardNum2, change, 1);
		return 1;
	}
}


#endif // !_INC_TRANSCONTROLER_
