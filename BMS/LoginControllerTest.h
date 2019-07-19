/*@author 车亮召						*/
/*********************************/
/*      LoginController测试类	*/
/*******************************/
#ifndef _INC_LOGINCONTROLLER_
#define _INC_LIGINCONTROLLER_
#include<iostream>
#include"LoginController.h"
#include<list>

class LoginControllerTest
{
public:
	int run(long long cardNum , int password)
	{
		LoginController controller;
		return controller.actionRequests(cardNum, password);
	}
};

#endif // !_INC_LOGINCONTROLLER_
