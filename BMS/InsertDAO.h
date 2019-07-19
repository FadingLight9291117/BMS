
//@author 方舟	
/************************************************/
/*			InsertDAO类，插入对象					*/
/*												*/	
/************************************************/

#ifndef _INC_INSERTDAO_
#define _INC_INSERTDAO_


#include<string>
#include<iostream>
#include"MysqlConnector.h"

#include"Model.h"
using namespace std;

class InsertDAO 
{
private:
	MYSQL* mysql;
public:
	int insert(User* user);									// 插入到user表，参数自定,返回值0或1
	int insert(CreditCard* card);							// 插入到credit_card
	int insert(DepositCard* card);							//  deposit_card表
};

int InsertDAO::insert(User *user)
{
	mysql = MysqlConnector::getConnector();					// 连接数据库
	string name = user->getName();
	long long id_card = user->getId_card();    

	char insertsql[1024];
	const char* pname = name.data();

	int len = sprintf_s(insertsql, 256, "INSERT INTO user (user_name,id_card) values ('%s',%lld);",pname, id_card);

	if (len < 0)
	{
		return 0;
	}
	if (mysql_query(mysql, insertsql) == 0)		//mysql_query()执行sql语句
	{
		MysqlConnector::close();			//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}

int InsertDAO::insert(CreditCard *card)
{
	mysql = MysqlConnector::getConnector();						// 连接数据库

	char insertsql[1024];
	int len = -1;

	len = sprintf_s(insertsql, 256, "INSERT INTO credit_card (user_idcard ,password,phone) values (%lld,%d,%lld);", card->getUserIDCard(), card->getPassword() , card->getPhone());


	if (len < 0)
	{
		return 0;
	}
	if (mysql_query(mysql, insertsql) == 0)		//mysql_query()执行sql语句
	{
		MysqlConnector::close();			//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}

int InsertDAO::insert(DepositCard* card)
{
	mysql = MysqlConnector::getConnector();						// 连接数据库

	char insertsql[1024];
	int len = -1;

	len = sprintf_s(insertsql, 256, "INSERT INTO deposit_card (user_idcard ,password,phone) values (%lld,%d,%lld);", card->getUserIDCard(), card->getPassword(), card->getPhone());
	
	if (len < 0)
	{
		return 0;
	}
	if (mysql_query(mysql, insertsql) == 0)		//mysql_query()执行sql语句
	{
		MysqlConnector::close();			//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}

#endif // !_INC_INSERTDAO_