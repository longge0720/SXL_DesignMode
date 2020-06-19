#pragma once
#include <iostream>
using namespace std;
#include "list"

//将请求封装成类对象 客户端 对请求对象 进行操作 执行请求内容


//vender作为客户端 有两个请求 卖香蕉和卖苹果 
//将卖香蕉和卖苹果封装成类 command类 command包括两个子类 Applecommand bananaCommand 分别执行两个请求
//
class Vendor
{
public:
	void sailbanana()
	{
		cout << "卖香蕉" << endl;
	}
	void sailapple()
	{
		cout << "卖苹果" << endl;
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
//为什么要通过waiter执行请求？ 
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

