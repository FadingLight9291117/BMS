//@author 方舟	
/************************************************/
/*			RemoveDAO类，删除对象					*/
/*												*/
/************************************************/

#ifndef _INC_REMOVE_
#define _INC_REMOVE_



#include<string>
#include<iostream>
#include"MysqlConnector.h"
#include"Model.h"
using namespace std;


class RemoveDAO
{
private:
	MYSQL* mysql;
public:
	int removeUser(long long IDCard);									//根据身份证号删除
	int removeCredit(long long cardNum);					//根据卡号删除银行卡记录
	int removeDeposit(long long cardNum);						//根据卡号删除银行卡记录

};

int RemoveDAO::removeUser(long long IDCard)
{
	MYSQL* mysql = MysqlConnector::getConnector();			// 连接数据库

	int len = -1;
	char removesql[1024];
	len = sprintf_s(removesql, 256, "DELETE FROM user WHERE id_card = %lld;", IDCard);
	
	if(	mysql_query(mysql, removesql) == 0)	//mysql_query()执行sql语句
	{
		MysqlConnector::close();		//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}

int RemoveDAO::removeDeposit(long long cardNum)
{
	mysql = MysqlConnector::getConnector();			// 连接数据库

	char removesql[1024];

	sprintf_s(removesql, 256, "DELETE FROM deposit_card WHERE card_number = %lld;", cardNum);

	if (mysql_query(mysql, removesql) == 0)
	{
		MysqlConnector::close();		//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}

int RemoveDAO::removeCredit(long long cardNum)
{
	mysql = MysqlConnector::getConnector();			// 连接数据库

	char removesql[1024];
	sprintf_s(removesql, 256, "DELETE FROM credit_card WHERE card_number = %lld;", cardNum);
	if (mysql_query(mysql, removesql) == 0)		//mysql_query()执行sql语句
	{
		MysqlConnector::close();		//关闭连接
		return 1;
	}
	else
	{
		MysqlConnector::close();		//关闭连接
		return 0;
	}
}


#endif // !_INC_REMOVE_
