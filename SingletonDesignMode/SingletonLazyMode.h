#pragma once
#include <iostream>
using namespace std;
//实现方法 懒汉模式 每次只有当静态全局变量为null时才创建
//a)	构造函数私有化
//b)	提供一个全局的静态方法（全局访问点）
//c)	在类中定义一个静态指针，指向本类的变量的静态变量指针

//懒汉模式
class SingletonLazyMode
{
private:
	//3. 在类中定义一个静态指针，指向本类的变量的静态变量指针
	static SingletonLazyMode*m_psl;
	static int SingletonCount;
private:
	//1.构造函数私有化
	SingletonLazyMode()
	{
		cout << "SingletonLazy构造函数执行次数:" << SingletonCount << endl;
	}
public:
	//2.提供一个全局的静态方法 用来返回单例对象
	static SingletonLazyMode* getInstance()
	{
		if (m_psl == nullptr)
		{
			SingletonCount++;
			m_psl = new SingletonLazyMode();
		}

		return m_psl;
	}

	//释放单例
	static void freeInstance()
	{
		if (m_psl != nullptr)//懒汉模式 每次只有当静态全局变量为null时才创建
		{
			delete m_psl;
			SingletonCount--;
		}
		m_psl = nullptr;//指针和指针指向的空间是两个概念都需要释放
	}
};
//类的静态成员的初始化
SingletonLazyMode* SingletonLazyMode::m_psl = nullptr;
int SingletonLazyMode::SingletonCount = 0;