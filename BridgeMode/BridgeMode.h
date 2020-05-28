#pragma once
#include <iostream>
using namespace std;

//桥接模式中会创造两个 类族  
//其中一个类会包含另一个类的成员对象 
//桥接模式就是为了建立这两个类之间的关系 并尽可能的解耦合 使两个类没有关联

//抽象的操作系统类 
class OS
{
public:
	virtual string GetOS() = 0 ;
};

//OS 的实现类 IOS
class IOS :public OS
{
public:
	virtual string GetOS()
	{
		return  "IOS Operator System";
	}
};

//OS 的实现类 Saibian
class SaiBian:public OS
{
	virtual string GetOS()
	{
		return "SaiBian Operator System";
	}


};


//IOS 的子类IOS 10.1.1
class IOSSubSystem1 :public IOS
{
public:
	virtual string GetOS()
	{
		return "IOS 10.1.1 Operator System";
	}
};

//IOS 的子类IOS 13.1.1
class IOSSubSystem2 :public IOS
{
public:
	virtual string GetOS()
	{
		return "IOS 13.1.1 Operator System";
	}
};

//IOS 的子类IOS 10.1.1
class SaiBianSubSystem1 :public SaiBian
{
public:
	virtual string GetOS()
	{
		return "SaiBian 10.1.1 Operator System";
	}
};

//SaiBian 的子类IOS 13.1.1
class SaiBianSubSystem2 :public SaiBian
{
public:
	virtual string GetOS()
	{
		return "SaiBian 13.1.1 Operator System" ;
	}
};

//////////////////////////////////////////////////////////////////////////////////
//另一个类族phone
class Phone
{
public:
	virtual void setOS() = 0;
};
//苹果手机类 ， 拥有苹果操作系统
class iPhone : public Phone
{
private:
	OS* m_os;
public:
	iPhone(OS* os) { m_os = os; }
	~iPhone() { if(!m_os)delete m_os; }
	virtual void setOS()
	{
		cout << "Set The OS: " << m_os->GetOS().c_str() << endl;
	}
};

//苹果手机类 ， 拥有苹果操作系统
class NokiaPhone : public Phone
{
private:
	OS* m_os;
public:
	NokiaPhone(OS* os) :m_os(os) {}
	~NokiaPhone() { if (!m_os)delete m_os; }
	virtual void setOS()
	{
		cout << "Set The OS: " << m_os->GetOS().c_str() << endl;
	}
};


