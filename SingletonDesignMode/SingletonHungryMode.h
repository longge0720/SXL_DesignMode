#pragma once
#include <iostream>
using namespace std;
//实现方法 饿汉模式 首先创建一个全局变量对象
//a)	构造函数私有化
//b)	提供一个全局的静态方法（全局访问点）
//c)	在类中定义一个静态指针，指向本类的变量的静态变量指针

//饿汉模式
class SingletonHungryMode
{
private:
	//3. 在类中定义一个静态指针，指向本类的变量的静态变量指针
	static SingletonHungryMode* m_psl;
	static int SingletonCount;
private:
	//1.构造函数私有化
	SingletonHungryMode()
	{
		cout << "SingletonHungry构造函数执行次数:" << SingletonCount << endl;
	}
public:
	//2.提供一个全局的静态方法 用来返回单例对象
	static SingletonHungryMode* getInstance()
	{
		//if (m_psl == nullptr)
		//{
		//	SingletonCount++;
		//	m_psl = new SingletonHungryMode();
		//}

		return m_psl;
	}

	//释放单例
	static void freeInstance()
	{
		if (m_psl != nullptr)
		{
			delete m_psl;
			SingletonCount--;
		}
		m_psl = nullptr;//指针和指针指向的空间是两个概念都需要释放
	}
};
//类的静态成员的初始化
SingletonHungryMode* SingletonHungryMode::m_psl = new SingletonHungryMode;
int SingletonHungryMode::SingletonCount = 1;