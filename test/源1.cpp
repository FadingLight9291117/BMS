#include<iostream>
using namespace std;
class Father
{
public:
	virtual int foo() = 0;
};

class Son :public Father
{
public:
	int foo();
	int foo(int a);
	int foo(int a, int b);
};

int Son::foo()
{
	return 0;
}

int Son::foo(int a)
{
	return a;
}

int Son::foo(int a, int b)
{
	return a + b;
}

int main()
{
	Father* a = new Son();
	cout << a->foo() << endl;
}