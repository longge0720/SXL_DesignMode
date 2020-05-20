#pragma once
#include <iostream>
using namespace std;
#include <string>

//简单工厂是一个工厂可以生产所有的产品
//工厂模式是 每个产品都有一个工厂
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