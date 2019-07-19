#ifndef _INC_REQUEST_
#define _INC_REQUEST_

#include"Response.h"
#include<iostream>
#include<string>
#include<map>

class Request
{
public:
	map<string, string>* request(map<string, string>* m)
	{
		Response a;
		return a.response(m);
	}
};

#endif // !_INC_REQUEST_
