#pragma once
#include <vector>
#include <iostream>
using namespace std;

//���ģʽ�򵥵������� ���ø��ڵ�ķ��� ��������ӽڵ�����ط���ȫ��ִ��һ��

//������� Ϊ����еĶ��������ӿ� 
class Component
{
public:
	Component() {}
	virtual ~Component() {}
	//���麯�� ֻ�ṩ�ӿ�û��Ĭ�ϵ�ʵ�� �����������ʵ��
	virtual void Operation() = 0;

	//�麯�� �ṩ�ӿ���Ĭ��ʵ�֣�ʲô������
	virtual void Add(Component* com)
	{
		cout << "Add" << endl;
	}
	virtual void Remove(Component* com)
	{

	}
	virtual Component* GetChild(int index)
	{
		return nullptr;
	}
};

//Leaf��Ҷ�ӽڵ� Ҳ���ǲ�����������Ľڵ��� ���Բ���ʵ�� Add Remove GetChild�ȷ���
class Leaf :public Component 
{
public:
	//���麯�� ֻ�ṩ�ӿ�û��Ĭ�ϵ�ʵ�� �����������ʵ��
	virtual void Operation()
	{
		cout << "Leaf::Operation" << endl;
	}
	Leaf() {}
	virtual ~Leaf() {}
};

//Composite:�������������
class Composite :public Component
{
private:
	vector<Component*>m_ComVec;
public:
	Composite() {};
	virtual ~Composite() {};

	//ʵ�����нӿ� Ϊ������е�����Ҷ��ִ�и÷���
	virtual void Operation()
	{
		cout << "Composite::Operation" << endl;
		vector<Component*>::iterator iter = this->m_ComVec.begin();
		for (; iter != this->m_ComVec.end(); iter++)
		{
			(*iter)->Operation();
		}
	}

	//�麯�� �ṩ�ӿ���Ĭ��ʵ�֣�ʲô������
	virtual void Add(Component* com)
	{
		this->m_ComVec.push_back(com);
	}
	virtual void Remove(Component* com)
	{
		vector<Component*>::iterator iter = find(this->m_ComVec.begin(), this->m_ComVec.end(), com);
		this->m_ComVec.erase(iter);
	}
	virtual Component* GetChild(int index)
	{
		if (index < 0 || index > this->m_ComVec.size())
		{
			 return NULL;
		}
		return this->m_ComVec[index];
	}

};