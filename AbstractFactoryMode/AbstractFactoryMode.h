#pragma once
#include <iostream>
using namespace std;
#include <string>

//�򵥹�����һ�����������������еĲ�Ʒ
//����ģʽ�� ÿ����Ʒ����һ������
//���󹤳�ÿ�ο�������һϵ�в�Ʒ
class Fruit 
{
public:
	virtual void sayName()
	{
		cout << "fruit" << endl;
	}
};

class FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new Fruit();
	}
	virtual Fruit* getBanana()
	{
		return new Fruit();
	}
};

class SouthBanana:public Fruit
{
public:
	virtual void sayName()
	{
		cout << "SouthBanana" << endl;
	}
};
class SouthApple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "SouthApple" << endl;
	}
};
class SouthFruitFactory:public FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new SouthApple();
	}
	virtual Fruit* getBanana()
	{
		return new SouthBanana();
	}
};


class NorthBanana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "NorthBanana" << endl;
	}
};
class NorthApple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "NorthApple" << endl;
	}
};
class NorthFruitFactory :public FruitFactory
{
public:
	virtual Fruit* getApple()
	{
		return new NorthApple();
	}
	virtual Fruit* getBanana()
	{
		return new NorthBanana();
	}
};