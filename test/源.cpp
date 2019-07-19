//#include<iostream>
//#include<string>
//#include<map>
//using namespace std;
//
//class Response
//{
//public:
//	map<string, string>* response(map<string, string>* m)
//	{
//		map<string, string>* mm = new map<string, string>;
//		string name = (*m)["name"];//判断调用哪个控制器
//		string cardNumber = (*m)["cardNumber"];//卡号
//		if ( name.compare("LoginController"))
//		{
//			//--………………………………调用控制器，获取数据
//			string  money = "100";
//			(*mm)["check"] = "true";
//			(*mm)["money"] = money;
//		}
//		else
//		{
//			(*mm)["check"] = "false";
//		}
//
//
//		return mm;
//	}
//};
//
//
//class Request
//{
//public:
//	map<string, string>* request(map<string, string>* m)
//	{
//		Response a;
//		return a.response(m);
//	}
//};
//
//int main()
//{
//	string a = "123445", b = "134";//a:卡号,  b:密码或金额
//	Request r;
//	map<string, string>* m = new map<string,string>;
//	(*m)["name"] = "LoginController";
//	(*m)["cardNumber"] = a;
//	(*m)["password"] = b;
//	m = r.request(m);
//	cout << (*m)["money"] << endl;
//	return 0;
//}
