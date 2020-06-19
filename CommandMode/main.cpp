
#include <iostream>
using namespace std;
#include "CommandMode.h"

//С�̷� ֱ�� �� ˮ��
void main25_01()
{
	Vendor* v = new Vendor;
	v->sailapple();
	v->sailbanana();

	delete v;
	return;
}

//С�̷� ͨ������ �� ˮ��
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

//С�̷� ͨ��waiter �� ˮ�� Ϊʲôͨ��waiter��ˮ��

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

//С�̷� ͨ��advwaiter �����µ� ��ˮ��
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
