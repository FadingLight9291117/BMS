#ifndef _INC_OPEN_
#define _INC_OPEN


#include<iostream>
#include<string>
#include "Factory.h"

using namespace std;

class OpenController
{
protected:
	DAOFactory factory;
public:
	int actionRequests(long long IDCard,long long phone,int password,int amount,string username);								// 处理前端请求，返回数据库查询结果
};


int OpenController::actionRequests(long long IDCard,long long phone,int password,int amount,string username)
{
	    InsertDAO* insert = factory.createInsertDAO();        //创建一个插入DAO
		if(amount >= 0)                //信用卡
		{

			User user;
			user.setId_card(IDCard);
			user.setName(username);
			insert->insert(&user);
			CreditCard card;
			card.setUserIDCard(IDCard);
			card.setPhone(phone);
			card.setPassword(password);
			card.setCreditline(amount);
			insert->insert(&card);
			return 1;
		}
		if(amount == -1)               //储蓄卡
		{
			User user;
			user.setId_card(IDCard);
			user.setName(username);
			insert->insert(&user);
			DepositCard card;
			card.setUserIDCard(IDCard);
			card.setPhone(phone);
			card.setPassword(password);
			insert->insert(&card);
			return 1;
		}
}

#endif // !_INC_OPEN_