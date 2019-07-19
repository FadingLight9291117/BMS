
/********************************/
/*			User模型类			*/
/*******************************/

#ifndef _INC_USER_
#define _INC_USER_
#include<string>
using namespace std;
class User
{
private:
	string  name; 
	long long id_card;

public:
  User();
  User(string ,long long);
  void setName(string name );
  void setId_card(long long id);
  string  getName();
  long long getId_card();

};

inline User::User()
{
}

User::User(string name,long long id_card ){
	this->name =name ;
	this->id_card = id_card;
}

void User::setName(string name)
{
	this->name = name;
}

void User::setId_card(long long id)
{
	this->id_card = id;
}

string User::getName(){
	return name;
}

long long User::getId_card(){
	return  id_card;
}


#endif