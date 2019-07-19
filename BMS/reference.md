# 项目手册

## DAO类

### InsetDAO类

	用于对数据库的插入操作

- 方法说明
	- int insert(User* user)
		- 功能：插入用户数据到用户表user表
		- 参数：User对象指针，user中必须存入 姓名, 身份证
		- 返回值：插入成功返回1，插入失败返回0

	- int insert(CreaditCard* card)
		- 功能：插入信用卡数据到信用卡表credit_card表
		- 参数：CreditCard对象指针，card中必须存入 身份证，密码，手机号
		- 返回值：插入成功返回1，插入失败返回0

	- int insert(DepositCard* card)
		- 功能：插入储蓄卡数据到储蓄卡表deposit_card表
		- 参数：DepositCard对象指针，card中必须存入 身份证，密码，手机号
		- 返回值：插入成功返回1，插入失败返回0

	- 警告⚠：插入银行卡数据前，必须判断是储蓄卡还是信用卡

### RemoveDAO类

	用于对数据库的删除操作

- 方法说明
	- int removeUser(long long IDCard)
		- 功能：删除一条用户数据
		- 参数：IDCard为用户身份证号
		- 返回值：删除成功返回1，删除失败返回0

	- int removeCredit(long long cardNum)
		- 功能：删除一条信用卡数据
		- 参数：cardNum为信用卡号
		- 返回值：删除成功返回1，删除失败返回0

	- int removeDeposit(long long cardNum)
		- 功能：删除一条储蓄卡数据
		- 参数：cardNum为储蓄卡号
		- 返回值：删除成功返回1，删除失败返回0

	- 警告⚠：无

### UpdateDAO类

	用于更新一条数据库数据

- 方法说明
	- int update(long long cardNum,int change,int io)
		- 功能：更新银行卡余额（信用卡或储蓄卡）
		- 参数：cardNum 卡号，change 金额 ，io 1时表示存，0时表示取
		- 返回值：更新成功返回1，更新失败返回0

	- int update(long long cardNum,int password)
		- 功能：更新银行卡密码（信用卡或储蓄卡）
		- 参数：cardNum 卡号 ， password 新密码
		- 返回值：更新成功返回1，更新失败返回0

	- int update(long long cardNum,string state)
		- 功能：更新银行卡状态（信用卡或储蓄卡）
		- 参数：cardNum 卡号，state 新状态 "normal" 正常，"abnormal"冻结或挂失
		- 返回值：更新成功返回1，更新失败返回0

	- 警告⚠：更新前无需判断时储蓄卡还是信用卡

### Query类

	用于查询数据

- 方法说明
	- CreditCard* queryCredit(long long cardNum)
		- 功能：查询一条信用卡全部数据
		- 参数：cardNum 卡号
		- 返回值：返回一个CreditCard指针，存有全部储蓄卡信息

	- DepositCard* queryDeposit(long long cardNum)
		- 功能：查询一条储蓄卡全部数据
		- 参数：cardNum 卡号
		- 返回值：返回一个CreditCard指针，存有全部信用卡信息

	- User* queryUser(long long IDCard)
		- 功能：查询一条用户全部信息
		- 参数：IDCard 身份证号
		- 返回值返回一个User指针，存有用户全部信息

	- 警告⚠：银行卡查询前需要判断是信用卡还是储蓄卡
