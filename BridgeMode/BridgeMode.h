#pragma once
#include <iostream>
using namespace std;

//�Ž�ģʽ�лᴴ������ ����  
//����һ����������һ����ĳ�Ա���� 
//�Ž�ģʽ����Ϊ�˽�����������֮��Ĺ�ϵ �������ܵĽ���� ʹ������û�й���

//����Ĳ���ϵͳ�� 
class OS
{
public:
	virtual string GetOS() = 0 ;
};

//OS ��ʵ���� IOS
class IOS :public OS
{
public:
	virtual string GetOS()
	{
		return  "IOS Operator System";
	}
};

//OS ��ʵ���� Saibian
class SaiBian:public OS
{
	virtual string GetOS()
	{
		return "SaiBian Operator System";
	}


};


//IOS ������IOS 10.1.1
class IOSSubSystem1 :public IOS
{
public:
	virtual string GetOS()
	{
		return "IOS 10.1.1 Operator System";
	}
};

//IOS ������IOS 13.1.1
class IOSSubSystem2 :public IOS
{
public:
	virtual string GetOS()
	{
		return "IOS 13.1.1 Operator System";
	}
};

//IOS ������IOS 10.1.1
class SaiBianSubSystem1 :public SaiBian
{
public:
	virtual string GetOS()
	{
		return "SaiBian 10.1.1 Operator System";
	}
};

//SaiBian ������IOS 13.1.1
class SaiBianSubSystem2 :public SaiBian
{
public:
	virtual string GetOS()
	{
		return "SaiBian 13.1.1 Operator System" ;
	}
};

//////////////////////////////////////////////////////////////////////////////////
//��һ������phone
class Phone
{
public:
	virtual void setOS() = 0;
};
//ƻ���ֻ��� �� ӵ��ƻ������ϵͳ
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

//ƻ���ֻ��� �� ӵ��ƻ������ϵͳ
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


