#pragma once
#include <iostream>
using namespace std;


//���� ������������ȥ�̳� �� Ŀ�ľ��������Ǽ̳в�ʵ�ָ��Ե�clone ����
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
	virtual Prototype* clone() const { return new ConcretePrototype(*this); };//ԭ��ģʽ�Ĺؼ����ڶ�����Ŀ�������
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