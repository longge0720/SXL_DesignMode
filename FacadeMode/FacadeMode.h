#pragma once
#include <iostream>
using namespace std;

class SubSystemOne
{
public:
	void MethodOne() { cout << "SubSystemOne" << endl; }
};

class SubSystemTwo
{
public:
	void MethodTwo() { cout << "SubSystemTwo" << endl; }
};

class SubSystemThree
{
public:
	void MethodThree() { cout << "SubSystemThree" << endl; }
};

class SubSystemFour
{
public:
	void MethodFour() { cout << "SubSystemFour" << endl; }
};

//���ģʽ�ĺ������� facade �� ������������������
class Facade
{
private:
	SubSystemOne s1;
	SubSystemTwo s2;
	SubSystemThree s3;
	SubSystemFour s4;
public:
	void MethodA()
	{
		s1.MethodOne();
		s2.MethodTwo();
		s4.MethodFour();
	}

	void MethodB()
	{
		s3.MethodThree();
		s1.MethodOne();
		s4.MethodFour();
	}
};