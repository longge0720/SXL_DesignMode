#pragma once
#include <iostream>
using namespace std;
#include <string>

//�򵥹�����һ�����������������еĲ�Ʒ
//����ģʽ�� ÿ����Ʒ����һ������
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
	virtual Fruit* getFruit()
	{
		return new Fruit();
	}
};

class Banana:public Fruit
{
public:
	virtual void sayName()
	{
		cout << "banana" << endl;
	}
};

class BananaFactory:public FruitFactory
{
public:
	virtual Banana* getFruit()
	{
		return new Banana();
	}
};


class Apple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "apple" << endl;
	}
};

class AppleFactory :public FruitFactory
{
public:
	virtual Apple* getFruit()
	{
		return new Apple();
	}
};


class Pear :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "pear" << endl;
	}
};

class PearFactory :public FruitFactory
{
public:
	virtual Pear* getFruit()
	{
		return new Pear();
	}
};