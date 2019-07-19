/*@author 车亮召						*/
/*********************************/
/*      RequestSaveTest测试类		*/
/*******************************/
#include"Request.h"
#include<string>
#include<map>
using namespace std;
class RequestSaveTest
{
public:
	int run(string card, string money)
	{
		Request request;
		map<string, string> m;
		m["name"] = "SaveController";
		m["cardNumber"] = card;
		m["money"] = money;

		map<string, string>* result;
		result = request.request(&m);

		return stoi((*result)["check"]);
	}
};
