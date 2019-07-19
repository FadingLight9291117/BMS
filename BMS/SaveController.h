#ifndef _INC_SAVE_CONTROLLER
#define _INC_SAVE_CONTROLLER


#include<iostream>
using namespace std;

class DAOFactory;											// 工厂类，创建DAO，DAO是操作数据库的一个类
class VO;													// VO，Value Object，用来传递值的对象
class DAO;													// DAO,Data Access Object 是操作数据库的对象

class SaveController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNumber,int amount);								
};

int SaveController::actionRequests(long long cardNumber,int amount)
{	
	DAO *update = factory.createUpdateDAO();       // 创建一个更新DAO
	update.update(cardNumber,amount);
		return 1;

}

#endif // !_INC_SAVE_CONTROLLER