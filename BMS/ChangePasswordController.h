#ifndef _INC_CHANGEPASSWORDCONTROLLER_
#define _INC_CHANGEPASSWORDCONTROLLER_

#include<iostream>
#include"Factory.h"
using namespace std;

class ChangePasswordController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNum, int password);
};

int ChangePasswordController::actionRequests(long long cardNum, int password)
{
	UpdateDAO *update = factory.createUpdateDAO();
	return update->update(cardNum,password);
}


#endif // !_INC_CHANGEPASSWORDCONTROLLER_
