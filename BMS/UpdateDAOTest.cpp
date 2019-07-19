/*@author 车亮召					*/
/*******************************/
/*      UpdateDAO测试函数      */
/*****************************/
#include<iostream>
#include<stdlib.h>
#include"UpdateDAO.h"
using namespace std;
int main()
{
	UpdateDAO dao;
	//dao.update(1000000000000007, 2000, 1); // 存钱
	//dao.update(1000000000000007, 1000, 0); // 取钱
	//
	//dao.update(1000000000000007, "abnormal"); // 冻结

	dao.update(1000000000000007, 111111);
}