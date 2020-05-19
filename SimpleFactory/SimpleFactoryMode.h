#pragma once
#include <iostream>
using namespace std;
#include <string>

class Fruit 
{
public:
	virtual void getFruit() = 0;
};

class Banana:public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "Banana" << endl;
	}
};

class Apple : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "Apple" << endl;
	}
};

class Pear :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "Pear" << endl;
	}
};

class sFactory
{
public:
	static Fruit* createFruit(string name)
	{
		Fruit* tmp = NULL;
		if (name.compare("banana") == 0)
		{
			tmp = new Banana();
		}
		else if (name.compare("apple") == 0)
		{
			tmp = new Apple();
		}
		else if (name.compare("pear") == 0)
		{
			tmp = new Pear();
		}
		return tmp;
	}
};