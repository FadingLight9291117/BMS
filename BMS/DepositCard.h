/*************************************************/
/*			DepositCard 模型类，继承Card类		*/
/************************************************/
#ifndef _INC_DEPOSITCARD_
#define _INC_DEPOSITCARD_
#include<string>
using namespace std;



class DepositCard  {
private:
	long long user_idcard;
	long long int card_number;
	int password;
	long long int phone;
	int balance;
	string state;
public:
	DepositCard() {};
	DepositCard(int user_idcard,
		long long int card_number,
		int password,
		long long int phone,
		int balance,
		string state)
	{
		this->user_idcard = user_idcard;
		this->card_number = card_number;
		this->password = password;
		this->phone = phone;
		this->balance = balance;
		this->state = state;
	}

	long long getUserIDCard() { return user_idcard; }
	long long int getCardnum() { return card_number; }
	int getPassword() { return password; }
	long long int getPhone() { return phone; }
	int getBalance() { return balance; }
	string getState() { return state; }

	void setUserIDCard(long long muser_id) { user_idcard = muser_id; }
	void setCardnum(long long int mcard_number) { card_number = mcard_number; }
	void setPassword(int mpassword) { password = mpassword; }
	void setPhone(long long int mphone) { phone = mphone; }
	void setBalance(int mbalance) { balance = mbalance; }
	void setState(string mstate) { state = mstate; }
};

#endif