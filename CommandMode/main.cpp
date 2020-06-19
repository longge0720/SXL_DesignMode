
#include <iostream>
using namespace std;
#include "CommandMode.h"

//小商贩 直接 卖 水果
void main25_01()
{
	Vendor* v = new Vendor;
	v->sailapple();
	v->sailbanana();

	delete v;
	return;
}

//小商贩 通过命令 卖 水果
void main25_02()
{
	Vendor* v = new Vendor;
	AppleCommand* ac = new AppleCommand(v);
	ac->sail();

	BananaCommand* bc = new BananaCommand(v);
	bc->sail();

	delete bc;
	delete ac;
	delete v;
}

//小商贩 通过waiter 卖 水果 为什么通过waiter卖水果

void main25_03()
{
	Vendor* v = new Vendor;
	AppleCommand* ac = new AppleCommand(v);
	BananaCommand* bc = new BananaCommand(v);

	Waiter* w = new Waiter;
	w->setCommand(ac);
	w->sail();

	w->setCommand(bc);
	w->sail();

	delete w;
	delete bc;
	delete ac;
	delete v;
}

//小商贩 通过advwaiter 批量下单 卖水果
void main25_04()
{
	Vendor* v = new Vendor;
	AppleCommand* ac = new AppleCommand(v);
	BananaCommand* bc = new BananaCommand(v);

	AdvWaiter* w = new AdvWaiter;
	w->setCommands(ac);
	w->setCommands(bc);
	w->sail();

	delete w;
	delete bc;
	delete ac;
	delete v;
}

void main()
{
	//main25_01();
	//main25_02();
	//main25_03();
	main25_04();
	system("pause");
}
