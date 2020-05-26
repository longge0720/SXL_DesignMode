#pragma once
#include <iostream>
#include <string>
using namespace std;
//装饰模式就是动态的给类添加一些属性 方法
//首先创建一个共同的公共抽象类（父类）供子类继承 和 实现多态
	//子类去继承并实现
	//装饰类去继承和实现
//装饰类里 对传入的父类对象进行装饰使传入的对象具备新特性

//公共抽象类 整个装饰模式的顶层父类
class Phone
{
public:
	Phone() {};
	virtual ~Phone() {};
	virtual void ShowDecorate(){}
};

class iPhone : public Phone
{
private:
	string m_name;//手机名称
public:
	iPhone(string name):m_name(name){}
	~iPhone() {};
	void ShowDecorate() { cout << "iPhone"<<m_name << "的装饰" << endl; }
};

class NokiaPhone : public Phone
{
private:
	string m_name;//手机名称
public:
	NokiaPhone(string name) :m_name(name) {}
	~NokiaPhone() {};
	void ShowDecorate() { cout <<"Nokia" << m_name << "的装饰" << endl; }
};

//装饰类的实现  装饰类也要继承顶层父类 Phone
class DecoratorPhone :public Phone
{
private:
	Phone* m_phone;
public:
	DecoratorPhone(Phone* phone):m_phone(phone){}
	virtual void ShowDecorate() { m_phone->ShowDecorate(); }

};

//装饰子类  里面实现具体的对对象的装饰
class DecoratorPhoneA :public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* phone) :DecoratorPhone(phone) {}
	void ShowDecorate() {DecoratorPhone::ShowDecorate(); AddDecorate();	}
private:
	void AddDecorate() { cout <<"增加挂件" << endl; }

};

//装饰子类  里面实现具体的对对象的装饰
class DecoratorPhoneB :public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* phone) :DecoratorPhone(phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "增加贴膜" << endl; }

};