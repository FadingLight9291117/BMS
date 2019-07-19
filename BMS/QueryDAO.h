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
	map<string,string> * query(long long num,string type);
private:
	CreditCard* query(CreditCard* cc);					
	DepositCard* query(DepositCard* dc);				//根据卡号查询银行卡全部信息
	User* query(User* usr);								//根据身份证号查询用户全部信息
};

map<string, string> *QueryDAO::query(long long num ,string type)
{
	if (type.compare("card") == 0)   // 如果是查询银行卡
	{
		map<string, string>* m = new map<string,string>;
		ostringstream* os;
		istringstream* is;
		CreditCard cc;
		cc.setCardnum(num);
		DepositCard dc;
		cc.setCardnum(num);

		if (query(&cc) != NULL)				//	判断如果是信用卡
		{
			os = new ostringstream;
			*os << cc.getCardnum();
			is = new istringstream((*os).str());
			*is >> (*m)["cardNum"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getPassword();
			is = new istringstream((*os).str());
			*is >> (*m)["password"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getUserIDCard();
			is = new istringstream((*os).str());
			*is >> (*m)["IDCard"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getPhone();
			is = new istringstream((*os).str());
			*is >> (*m)["phone"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getBalance();
			is = new istringstream((*os).str());
			*is >> (*m)["balance"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getState();
			is = new istringstream((*os).str());
			*is >> (*m)["state"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << cc.getCreditline();
			is = new istringstream((*os).str());
			*is >> (*m)["credit_line"];
			delete is;
			delete os;

			return m;
		}
		else if (query(&dc) != NULL)		// 判断如果是储蓄卡
		{
			os = new ostringstream;
			*os << dc.getCardnum();
			is = new istringstream((*os).str());
			*is >> (*m)["cardNum"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << dc.getPassword();
			is = new istringstream((*os).str());
			*is >> (*m)["password"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << dc.getUserIDCard();
			is = new istringstream((*os).str());
			*is >> (*m)["IDCard"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << dc.getPhone();
			is = new istringstream((*os).str());
			*is >> (*m)["phone"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << dc.getBalance();
			is = new istringstream((*os).str());
			*is >> (*m)["balance"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << dc.getState();
			is = new istringstream((*os).str());
			*is >> (*m)["state"];
			delete is;
			delete os;

			return m;
		}
		else
		{
			return NULL;
		}
	}
	else if (type.compare("user") == 0)
	{
		map<string, string>* m = new map<string,string>;
		ostringstream* os;
		istringstream* is;
		User user;
		user.setId_card(num);

		if (query(&user) != NULL)
		{
			os = new ostringstream;
			*os << user.getName();
			is = new istringstream((*os).str());
			*is >> (*m)["name"];
			delete is;
			delete os;

			os = new ostringstream;
			*os << user.getId_card();
			is = new istringstream((*os).str());
			*is >> (*m)["IDCard"];
			delete is;
			delete os;

			return m;
		}
		else
		{
			return NULL;
		}

	}
	

}

CreditCard* QueryDAO::query(CreditCard* cc)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];
	long long cardNum=cc->getCardnum();

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

DepositCard* QueryDAO::query(DepositCard* dc)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];
	long long cardNum=dc->getCardnum();

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

User* QueryDAO::query(User* usr)
{
	MYSQL *mysql = MysqlConnector::getConnector();			// 连接数据库
	char querysql[1024];
	long long idCard=usr->getId_card();

	sprintf_s(querysql, 256, "SELECT * FROM user WHERE id_card = %lld;",idCard);

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