
#ifndef _INC_QUERY_CONTROLLER
#define _INC_QUERY_CONTROLLER

#include"Factory.h"
#include"Model.h"

class QueryController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long cardNumber);								// 处理前端请求，返回数据库查询结果
};

int QueryController::actionRequests(long long num,string type1,string type2)
{
	QueryDAO* query = factory.createQueryDAO();					// 创建一个查询DAO
	if (type.compare("user") == 0)
	{
		
	}
	else if (type.compare("card") == 0)
	{

	}
	
	
	map<string,string> *result = query->operate(num);
	
	

}

#endif // !_INC_QUERY_CONTROLLER