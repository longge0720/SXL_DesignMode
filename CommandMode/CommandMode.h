#pragma once
#include <iostream>
using namespace std;
#include "list"

//�������װ������� �ͻ��� ��������� ���в��� ִ����������


//vender��Ϊ�ͻ��� ���������� ���㽶����ƻ�� 
//�����㽶����ƻ����װ���� command�� command������������ Applecommand bananaCommand �ֱ�ִ����������
//
class Vendor
{
public:
	void sailbanana()
	{
		cout << "���㽶" << endl;
	}
	void sailapple()
	{
		cout << "��ƻ��" << endl;
	}
};

class Command
{
public:
	virtual void sail() = 0;
};

class BananaCommand : public Command
{
public:
	BananaCommand(Vendor* v)
	{
		m_v = v;
	}
	Vendor* getV(Vendor* v)
	{
		return m_v;
	}

	void setV(Vendor* v)
	{
		m_v = v;
	}
	virtual void sail()
	{
		m_v->sailbanana();
	}
protected:
private:
	Vendor* m_v;
};

class AppleCommand : public Command
{
public:
	AppleCommand(Vendor* v)
	{
		m_v = v;
	}
	Vendor* getV(Vendor* v)
	{
		return m_v;
	}

	void setV(Vendor* v)
	{
		m_v = v;
	}
	virtual void sail()
	{
		m_v->sailapple();
	}
protected:
private:
	Vendor* m_v;
};
//ΪʲôҪͨ��waiterִ������ 
class Waiter
{
public:
	Command* getCommand()
	{
		return m_command;
	}
	void setCommand(Command* c)
	{
		m_command = c;
	}
	void sail()
	{
		m_command->sail();
	}
protected:
private:
	Command* m_command;
};

class AdvWaiter
{
public:
	AdvWaiter()
	{
		m_list = new list<Command*>;
		m_list->resize(0);
	}
	~AdvWaiter()
	{
		delete m_list;
	}
	void setCommands(Command* c)
	{
		m_list->push_back(c);
	}
	list<Command*>* getCommands()
	{
		return m_list;
	}
	void sail()
	{
		for (list<Command*>::iterator it = m_list->begin(); it != m_list->end(); it++)
		{
			(*it)->sail();
		}
	}
protected:
private:
	list<Command*>* m_list;
};

