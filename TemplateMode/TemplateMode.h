#pragma once
#include <iostream>
using namespace std;


//Template Methodģʽһ��Ӧ���ھ�����������
//��Ӧ���У�
//- ����ͳһ�Ĳ���������������
//- ���в�ͬ�Ĳ���ϸ��
//- ���ڶ������ͬ�����������Ӧ�ó�������ĳЩ����Ĳ���ϸ��ȴ������ͬ
//�ܽ᣺
//�ڳ�������ͳһ�������裬���涨�ýӿڣ�������ʵ�ֽӿڡ��������԰Ѹ������������Ͳ�����������
//AbstractClass��
//������ĸ���
//ConcreteClass��
//�����ʵ������
//templateMethod()��
//ģ�巽��
//method1()��method2()��
//���岽�跽��


class MakeCar
{
public:
	virtual void makeHead() = 0;
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};

class MakeBus:public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "bus ��װ ��ͷ" << endl;
	}
	virtual void makeBody()
	{
		cout << "bus ��װ ����" << endl;
	}
	virtual void makeTail()
	{
		cout << "bus ��װ ��β" << endl;
	}

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};

class MakeJeep :public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "Jeep ��װ ��ͷ" << endl;
	}
	virtual void makeBody()
	{
		cout << "Jeep ��װ ����" << endl;
	}
	virtual void makeTail()
	{
		cout << "Jeep ��װ ��β" << endl;
	}

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};