#include<iostream>
#include"TransController.h"
using namespace std;

int main()
{
	TransController controller;
	cout << controller.actionRequests(1000000000000023, 1000000000000021, 1000) << endl;
}