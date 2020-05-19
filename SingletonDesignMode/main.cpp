#include <iostream>
using namespace std;
#include "SingletonLazyMode.h"
#include "SingletonHungryMode.h"
#include "SingletonLazyMode_multiThread.h"
#include "SingletonHungryMode_multiThread.h"
#include "SingletonLazyModeDoubleCheck.h"

void testSingletonLazyModeDoubleCheck()
{
	//_tmainTTT(0, nullptr);//非多线程的情况下 懒汉模式单例没有问题
	_tmainDC(0, nullptr);//多线程模式下懒汉模式的单例模式 很可能会导致 创建多个对象
}

void testSingletonHungryMode_multiThread()
{
	//_tmainHungry(0, nullptr);//非多线程的情况下 
	_tmain_tmainHungry(0, nullptr);//
}

void testSingletonLazyMode_multiThread()
{
	//_tmainTTT(0, nullptr);//非多线程的情况下 懒汉模式单例没有问题
	_tmain(0, nullptr);//多线程模式下懒汉模式的单例模式 很可能会导致 创建多个对象
}

void testSingletonLazyMode()
{
	SingletonLazyMode* p1 = SingletonLazyMode::getInstance();
	SingletonLazyMode* p2 = SingletonLazyMode::getInstance();

	if (p1 == p2)
	{
		cout << "单例模式成功，两次对象为同一个" << endl;
	}
	else
	{
		cout << "单例模式失败，两次对象不为同一个" << endl;
	}

	SingletonLazyMode::freeInstance();
}

void testSingletonHungryMode()
{
	SingletonHungryMode* p1 = SingletonHungryMode::getInstance();
	SingletonHungryMode* p2 = SingletonHungryMode::getInstance();

	if (p1 == p2)
	{
		cout << "单例模式成功，两次对象为同一个" << endl;
	}
	else
	{
		cout << "单例模式失败，两次对象不为同一个" << endl;
	}

	SingletonHungryMode::freeInstance();
}





int main(void)
{
	//testSingletonLazyMode();
	//testSingletonHungryMode();
	//testSingletonLazyMode_multiThread();
	//testSingletonHungryMode_multiThread();
	//testSingletonLazyModeDoubleCheck();
	return 0;
}