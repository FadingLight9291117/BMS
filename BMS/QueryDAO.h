//@author 方舟	
/************************************************/
/*			QueryDAO类，查询对象					*/										
/***********************************************/
#ifndef _INC_QUERYDAO_
#define _INC_QUERYDAO_


#include<iostream>
#include<sstream>
#include<string>
#include<list>
#include"Model.h"
#include"MysqlConnector.h"
#include<map>

using namespace std;

class QueryDAO
{
public:
	CreditCard* queryCredit(long long cardNum);					
	DepositCard* queryDeposit(long long cardNum);				//根据卡号查询银行卡全部信息
	User* queryUser(long long IDcard);								//根据身份证号查询用户全部信息
};

CreditCard* QueryDAO::queryCredit(long long cardNum)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];

	CreditCard* cc = new CreditCard();

	sprintf_s(querysql, 256, "SELECT * FROM credit_card WHERE card_number = %lld;",cardNum);


	if(mysql_query(mysql, querysql)!=0)		//mysql_query()执行sql语句
	{
		return NULL;
	}
	MYSQL_RES *res;             //返回行的查询结果集
	MYSQL_FIELD *fd;            //字段列数组
	MYSQL_ROW column;
	char field[32][32];

	res=mysql_store_result(mysql);		//获得sql语句结束后返回的结果集
	column = mysql_fetch_row(res);

	cc->setUserIDCard(atoi(column[1]));

	cc->setPassword(atoi(column[3]));
	cc->setPhone(atoll(column[4]));
	cc->setCreditline(atoi(column[5]));
	cc->setBalance(atoi(column[6]));
	cc->setState(column[7]);

	MysqlConnector::close();		//关闭连接
	return cc;

}

DepositCard* QueryDAO::queryDeposit(long long cardNum)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];

	DepositCard* dc = new DepositCard();

	sprintf_s(querysql, 256, "SELECT * FROM deposit_card WHERE card_number = %lld;",cardNum);

	if(mysql_query(mysql, querysql)!=0)		//mysql_query()执行sql语句
	{
		return NULL;
	}
	MYSQL_RES *res;             //返回行的查询结果集
	MYSQL_FIELD *fd;            //字段列数组
	MYSQL_ROW column;
	char field[32][32];

	res=mysql_store_result(mysql);		//获得sql语句结束后返回的结果集
	column = mysql_fetch_row(res);

	dc->setUserIDCard(atoi(column[1]));

	dc->setPassword(atoi(column[3]));
	dc->setPhone(atoll(column[4]));
	dc->setBalance(atoi(column[5]));
	dc->setState(column[6]);

	MysqlConnector::close();		//关闭连接
	return dc;

}

User* QueryDAO::queryUser(long long IDCard)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];

	sprintf_s(querysql, 256, "SELECT * FROM user WHERE id_card = %lld;", IDCard);

	if(mysql_query(mysql, querysql)!=0)		//mysql_query()执行sql语句
	{
		return NULL;
	}
	MYSQL_RES *res;             //返回行的查询结果集
	MYSQL_FIELD *fd;            //字段列数组
	MYSQL_ROW column;
	char field[32][32];

	res=mysql_store_result(mysql);		//获得sql语句结束后返回的结果集
	column = mysql_fetch_row(res);

	usr->setName(column[1]);

	MysqlConnector::close();		//关闭连接
	return usr;
}

#endif // !_INC_QUERYDAO_