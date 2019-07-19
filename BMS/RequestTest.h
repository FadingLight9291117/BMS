/*@author 车亮召						*/
/*********************************/
/*      RequestLoginTest测试类		*/
/*******************************/
#include"Request.h"
#include<string>
#include<map>
using namespace std;
class RequestTest
{
public:
	int run(string card, string passwd)
	{
		Request request;
		map<string, string> m;
		m["name"] = "LoginController";
		m["cardNumber"] = card;
		m["password"] = passwd;
		
		map<string, string>* result;
		result = request.request(&m);

		return stoi((*result)["check"]);
	}
};