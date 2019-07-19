#ifndef _INC_SAVECONTROLLERTEST_
#define _INC_SAVECONTROLLERTEST_

#include<iostream>
#include"SaveController.h"
class SaveControllerTest
{
public:
	int run(long long num, int amount)
	{
		SaveController controller;
		return controller.actionRequests(num, amount);
	}
};

#endif // !_INC_SAVECONTROLLERTEST_
