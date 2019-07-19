/************************************************************************/
/*                         C API连接MySQL                               */
/************************************************************************/

#include<iostream>
#include<stdio.h>
#include"MysqlConnector.h"
using namespace std;

int main()
{
	MYSQL* mysql;
	MYSQL_RES *result;															//查询到的结果集
	MYSQL_FIELD *field;															//数据表字段指针
	MYSQL_ROW row;																//数据行变量，后面用来保存列数组

	mysql = MysqlConnector::getConnector();
	


	mysql_query(mysql, "SELECT * FROM user");									//mysql_query()执行sql语句


	result = mysql_store_result(mysql);											//mysql_store_result()获取结果集,存入result

	while(field = mysql_fetch_field(result))									//mysql_fetch_field()循环获取结果集表字段，field->name
	{	
		printf("%s\t",field->name);
	}
	printf("\n");

	while (row = mysql_fetch_row(result))										//mysql_fetch_row()循环获取结果集行数据数组
	{
		printf("%s\t%s\t%s \n",row[0],row[1],row[2]);							//row[0],row[1]... 行数组各字段数据
	}
	mysql_free_result(result);													//mysql_free_result()释放result所指内存

	MysqlConnector::close();													//mysql_close()断开MySQL连接
	return 0;
}