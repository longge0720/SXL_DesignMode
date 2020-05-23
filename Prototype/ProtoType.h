#pragma once
#include <iostream>
using namespace std;


//基类 供各个派生类去继承 ， 目的就是让他们继承并实现各自的clone 函数
class Prototype
{
protected:
	Prototype() { cout << "Prototype" << endl; };
public:
	virtual Prototype* clone()const = 0;
	virtual ~Prototype() { cout << "~Prototype" << endl; };
public:
	string name;
	int m_number;

	virtual string getName()
	{
		return this->name;
	}
	virtual int getNumber()
	{
		return this->m_number;
	}
};

class ConcretePrototype :public Prototype
{
public:
	ConcretePrototype() { cout << "ConcretePrototype" << endl; name = "NAME", m_number = 1; };	
	ConcretePrototype(const ConcretePrototype& rhs) { cout << "Copy ConcretePrototype" << endl; name = rhs.name, m_number = rhs.m_number; };
	virtual Prototype* clone() const { return new ConcretePrototype(*this); };//原型模式的关键在于对自身的拷贝构造
	~ConcretePrototype() { cout << "~ConcretePrototype" << endl; };
//private:
//	string name;
//	int m_number;
public:
	string getName()
	{
		return this->name;
	}
	int getNumber()
	{
		return this->m_number;
	}
};