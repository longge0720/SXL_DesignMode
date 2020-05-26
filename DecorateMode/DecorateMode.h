#pragma once
#include <iostream>
#include <string>
using namespace std;
//װ��ģʽ���Ƕ�̬�ĸ������һЩ���� ����
//���ȴ���һ����ͬ�Ĺ��������ࣨ���ࣩ������̳� �� ʵ�ֶ�̬
	//����ȥ�̳в�ʵ��
	//װ����ȥ�̳к�ʵ��
//װ������ �Դ���ĸ���������װ��ʹ����Ķ���߱�������

//���������� ����װ��ģʽ�Ķ��㸸��
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
	string m_name;//�ֻ�����
public:
	iPhone(string name):m_name(name){}
	~iPhone() {};
	void ShowDecorate() { cout << "iPhone"<<m_name << "��װ��" << endl; }
};

class NokiaPhone : public Phone
{
private:
	string m_name;//�ֻ�����
public:
	NokiaPhone(string name) :m_name(name) {}
	~NokiaPhone() {};
	void ShowDecorate() { cout <<"Nokia" << m_name << "��װ��" << endl; }
};

//װ�����ʵ��  װ����ҲҪ�̳ж��㸸�� Phone
class DecoratorPhone :public Phone
{
private:
	Phone* m_phone;
public:
	DecoratorPhone(Phone* phone):m_phone(phone){}
	virtual void ShowDecorate() { m_phone->ShowDecorate(); }

};

//װ������  ����ʵ�־���ĶԶ����װ��
class DecoratorPhoneA :public DecoratorPhone
{
public:
	DecoratorPhoneA(Phone* phone) :DecoratorPhone(phone) {}
	void ShowDecorate() {DecoratorPhone::ShowDecorate(); AddDecorate();	}
private:
	void AddDecorate() { cout <<"���ӹҼ�" << endl; }

};

//װ������  ����ʵ�־���ĶԶ����װ��
class DecoratorPhoneB :public DecoratorPhone
{
public:
	DecoratorPhoneB(Phone* phone) :DecoratorPhone(phone) {}
	void ShowDecorate() { DecoratorPhone::ShowDecorate(); AddDecorate(); }
private:
	void AddDecorate() { cout << "������Ĥ" << endl; }

};