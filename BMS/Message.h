#ifndef _INC_MESSAGE_
#define _INC_MESSAGE_

#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;
class Message
{
private:
	static list<string> split(string str, char dim);
public:
	static map<string, string> parse(string str);
	static string serialize(map<string, string> m);
};

list<string> Message::split(string  str, char dim)
{
	char* d = &dim;
	list<string> ls;

	char* strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());

	char* p = strtok(strs, d);
	while (p) {
		string s = p;
		ls.push_back(s);
		p = strtok(NULL, d);
	}
	return ls;
}

string Message::serialize(map<string, string> m)
{
	string str;
	map<string, string>::iterator iter = m.begin();
	while (1)
	{

		str += iter->first + "=" + iter->second;
		++iter;
		if (iter != m.end())
		{
			str += " ";
		}
		else
		{
			break;
		}
	}
	return str;
}

map<string, string> Message::parse(string str)
{
	map<string, string> mm;
	list<string> ll = split(str, ' ');
	list<string>::iterator iter;
	string temp;
	for (iter = ll.begin(); iter != ll.end(); ++iter)
	{
		temp = *iter;
		int i = temp.find('=');
		mm[temp.substr(0, i)] = temp.substr(i + 1);
	}
	return mm;
}


#endif // !_INC_MESSAGE_
