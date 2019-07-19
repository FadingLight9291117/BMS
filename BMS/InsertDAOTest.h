///*@author 车亮召					*/	
///*******************************/
///*      insertdao测试类	     */
///*****************************/
//
//#ifndef _INC_TESTINSERTDAO_
//#define _INC_TESTINSERTDAO_
//
//
//#include<iostream>
//
//#include"insertdao.h"
//using namespace std;
//
//class InsertDAOTest
//{
//public:
//	int run()
//	{
//		CreditCard creditcard;
//		creditcard.setUserIDCard(4200000000000000);
//		creditcard.setPassword(123456);
//		creditcard.setPhone(13222222222);
//
//		DepositCard depositcard;
//		depositcard.setUserIDCard(4200000000000000);
//		depositcard.setPassword(123456);
//		depositcard.setPhone(13222222222);
//
//		User user;
//		user.setName("车亮召");
//		user.setId_card(420325199811170012);
//
//		InsertDAO* dao = new InsertDAO();
//		int m = dao->insert(&creditcard);
//		int n = dao->insert(&depositcard);
//		int k = dao->insert(&user);
//		cout << m << " " << n << " " << k << endl;
//		return 0;
//	}
//
//};
//
//#endif // !_INC_INSERTDAOTEST_