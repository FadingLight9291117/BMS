/*************************************/
/*            银行卡基类Card			*/
/*************************************/
#ifndef _INC_CARD_
#define _INC_CARD_
#include<iostream>
#include<string>
using namespace std;

class Card {
public:
		virtual void setUserIDCard(int muser_id) = 0;
		virtual void setCardnum(long long int mcard_number) = 0;
		virtual void setPassword(int mpassword) = 0;
		virtual void setPhone(long long int mphone) = 0;
		virtual void setBalance(int mbalance) = 0;
		virtual void setState(string mstate) = 0;
		virtual int getUserIDCard() = 0;
		virtual long long getCardnum() = 0;
		virtual int getPassword() = 0;
		virtual long long  getPhone() = 0;
		virtual int getBalance() = 0;
		virtual string getState() = 0;
};


#endif // !_INC_CARD_