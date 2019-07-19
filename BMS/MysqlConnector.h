/*@author 车亮召*/	
/*****************************************/
/*		MySQL连接器，懒汉式单例类			*/
/****************************************/
#ifndef _INC_MYSQLCONNECTOR_
#define _INC_MYSQLCONNECTOR_

#include<stdio.h>
#include<windows.h>																//MySQL5.5的mysql.h头文件需要，否则报错
#include"mysql.h"																//MySQL头文件，在MySQL目录/include中

class MysqlConnector
{
private:
	static MYSQL* mysql;														//指向MySQL结构体
	MysqlConnector();
public:
	static MYSQL* getConnector();												// 获取一个MYSQL结构体
	static void close();														// 关闭连接
};

MYSQL* MysqlConnector::mysql = NULL;

MYSQL* MysqlConnector::getConnector()
{
	if (mysql != NULL)
	{
		return mysql;
	}
	else
	{
		mysql = new MYSQL;
		mysql_init(mysql);																//初始化MYSQL结构体
		mysql_real_connect(mysql, LOCAL_HOST, "test", "m4a1421", "test", 0, NULL, 0);	//连接MySQL服务器，参数含义：
																						//MySQL结构体引用，主机名或IP地址，
																						//用户名，密码，库名，端口号（0默认），
																						//套接字文件的名字（NULL默认），客户端标识（0默认）
		return mysql;
	}
}

void MysqlConnector::close()
{
	mysql_close(mysql);
	mysql = NULL;
}

#endif // !_INC_MYSQLCONNECTOR_
