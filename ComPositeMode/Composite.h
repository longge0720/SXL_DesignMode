#pragma once
#include <vector>
#include <iostream>
using namespace std;

//组合模式简单的理解就是 调用根节点的方法 会把所有子节点的重载方法全部执行一遍

//抽象基类 为组合中的对象声明接口 
class Component
{
public:
	Component() {}
	virtual ~Component() {}
	//纯虚函数 只提供接口没有默认的实现 子类必须重新实现
	virtual void Operation() = 0;

	//虚函数 提供接口由默认实现，什么都不做
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

//Leaf是叶子节点 也就是不含有子组件的节点类 所以不用实现 Add Remove GetChild等方法
class Leaf :public Component 
{
public:
	//纯虚函数 只提供接口没有默认的实现 子类必须重新实现
	virtual void Operation()
	{
		cout << "Leaf::Operation" << endl;
	}
	Leaf() {}
	virtual ~Leaf() {}
};

//Composite:含有子组件的类
class Composite :public Component
{
private:
	vector<Component*>m_ComVec;
public:
	Composite() {};
	virtual ~Composite() {};

	//实现所有接口 为组合类中的所有叶子执行该方法
	virtual void Operation()
	{
		cout << "Composite::Operation" << endl;
		vector<Component*>::iterator iter = this->m_ComVec.begin();
		for (; iter != this->m_ComVec.end(); iter++)
		{
			(*iter)->Operation();
		}
	}

	//虚函数 提供接口由默认实现，什么都不做
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