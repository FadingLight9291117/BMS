//@author 方舟	
/************************************************/
/*			UpdateDAO类，更新对象					*/
/*												*/
/************************************************/

#ifndef _INC_UPDATEDAO_
#define _INC_UPDATEDAO_


#include<iostream>
#include<string>
#include<list>
#include"Model.h"
#include"MysqlConnector.h"

using namespace std;

class UpdateDAO
{
private:
	MYSQL* mysql;
public:
	int update(long long cardNum,int change,int io);					//更新银行卡号对应的余额,实现现金存取
	int update(long long cardNum,int password);							//更新银行卡号对应的密码，实现修改密码
	int update(long long cardNum,string state);							//更新银行卡号对应的状态，实现挂失冻结
	//int update(long long cardNum,int crdline);						//更新信用卡的信用额度
};

int UpdateDAO::update(long long cardNum,int change,int io)
{
	mysql = MysqlConnector::getConnector();			// 连接数据库
	char updatesql[1024];

	if (cardNum % 2 == 1)
	{
		if (io == 1)
			sprintf_s(updatesql, 256, "UPDATE credit_card SET balance=balance+%d WHERE card_number=%lld;", change, cardNum);
		else
			sprintf_s(updatesql, 256, "UPDATE credit_card SET balance=balance-%d WHERE card_number=%lld;", change, cardNum);
		int len = mysql_query(mysql, updatesql);	//mysql_query()执行sql语句

	}

	else
	{
		if (io == 1)
			sprintf_s(updatesql, 256, "UPDATE deposit_card SET balance=balance+%d WHERE card_number=%lld;", change, cardNum);
		else
			sprintf_s(updatesql, 256, "UPDATE deposit_card SET balance=balance-%d WHERE card_number=%lld;", change, cardNum);

		mysql_query(mysql, updatesql);
	}

	MysqlConnector::close();		//关闭连接
	return 1;

}

int UpdateDAO::update(long long cardNum,int password)
{
	mysql = MysqlConnector::getConnector();			// 连接数据库
	char updatesql[1024];
	
	sprintf_s(updatesql, 256, "UPDATE credit_card SET password=%d WHERE card_number=%lld;",password,cardNum);

	if(mysql_query(mysql, updatesql)!=0)		//mysql_query()执行sql语句
	{
		sprintf_s(updatesql, 256, "UPDATE deposit_card SET password=%d WHERE card_number=%lld;",password,cardNum);
		if(mysql_query(mysql, updatesql)!=0)
		{
			MysqlConnector::close();
			return 0;
		}
	}

	MysqlConnector::close();		//关闭连接
	return 1;

}

int UpdateDAO::update(long long cardNum,string state)
{
	mysql = MysqlConnector::getConnector();			// 连接数据库
	char updatesql[1024];
	const char* p = state.data();
	
	sprintf_s(updatesql, 256, "UPDATE credit_card SET state='%s' WHERE card_number=%lld;",p,cardNum);


	if(mysql_query(mysql, updatesql)!=0)		//mysql_query()执行sql语句
	{
		sprintf_s(updatesql, 256, "UPDATE deposit_card SET state='%s' WHERE card_number=%lld;",p,cardNum);
		if(mysql_query(mysql, updatesql)!=0)
		{
			MysqlConnector::close();
			return 0;
		}
	}

	MysqlConnector::close();		//关闭连接
	return 1;

}

//int UpdateDAO::update(long long cardNum,int crdline)
//{
//	mysql = MysqlConnector::getConnector();			// 连接数据库
//	char updatesql[1024];
//	
//	sprintf_s(updatesql, 256, "UPDATE credit_card SET credit_line=%d WHERE card_number=%lld;",crdline,cardNum);
//
//	if(mysql_query(mysql, updatesql)!=0)		//mysql_query()执行sql语句
//	{
//		MysqlConnector::close();
//		return 0;
//	}
//
//	MysqlConnector::close();		//关闭连接
//	return 1;
//
//}
#endif // !_INC_UPDATEDAO_