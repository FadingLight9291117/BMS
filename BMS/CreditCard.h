/*************************************************/
/*			CreditCard 模型类,继承Card类			*/
/************************************************/

#ifndef _INC_CREDITCARD_
#define _INC_CREDITCARD_

#include<string>

using namespace std;

class CreditCard {
private:
	long long user_idcard;
	long long int card_number;
	int password;
	long long int phone;
	int balance;
	string state;
	long long credit_line;
public:
	CreditCard() {};
	CreditCard(long long user_idcard,
		long long int card_number,
		int password,
		long long int phone,
		int credit_line,
		int balance,
		string state)
	{
		this->user_idcard = user_idcard;
		this->card_number = card_number;
		this->password = password;
		this->phone = phone;
		this->credit_line = credit_line;
		this->balance = balance;
		this->state = state;
	}
	long long getUserIDCard() { return user_idcard; }
	long long getCardnum() { return card_number; }
	int getPassword() { return password; }
	long long getPhone() { return phone; }
	long long getCreditline() { return credit_line; }
	int getBalance() { return balance; }
	string getState() { return state; }

	void setUserIDCard(long long muser_id) { user_idcard = muser_id; }
	void setCardnum(long long int mcard_number) { card_number = mcard_number; }
	void setPassword(int mpassword) { password = mpassword; }
	void setPhone(long long int mphone) { phone = mphone; }
	void setCreditline(long long  mcredit_line) { credit_line = mcredit_line; }
	void setBalance(int mbalance) { balance = mbalance; }
	void setState(string mstate) { state = mstate; }
};

#endif