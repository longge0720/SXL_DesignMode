#pragma once
//#include "stdafx.h"
#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"
#include <tchar.h>

using namespace std;
///////////////////////////////////////////////////
//饿汉模式
class SingletonHungryMode_multiThread
{
private:
	SingletonHungryMode_multiThread()
	{
		count++;
		cout << "SingletonHungryMode_multiThread构造函数begin\n" << endl;
		Sleep(1000);
		cout << "SingletonHungryMode_multiThread构造函数end\n" << endl;

	}
private:
	//防止拷贝构造和赋值操作
	SingletonHungryMode_multiThread(const SingletonHungryMode_multiThread& obj) { ; }
	SingletonHungryMode_multiThread& operator=(const SingletonHungryMode_multiThread& obj) { ; }
public:
	static SingletonHungryMode_multiThread* getSingelton()
	{
		//1"懒汉"模式虽然有优点，但是每次调用GetInstance()静态方法时，必须判断
		//	NULL == m_instance，使程序相对开销增大。
		//2多线程中会导致多个实例的产生，从而导致运行代码不正确以及内存的泄露。
		//3提供释放资源的函数
		return single;
	}

	static SingletonHungryMode_multiThread* releaseSingelton()
	{
		if (single != NULL) //需要判断
		{
			cout << "释放资源\n" << endl;
			delete single;
			single = NULL;
		}
		return single;
	}
	void pirntS() //测试函数
	{
		printf("Singelton printS test count:%d \n", count);
	}

private:
	static SingletonHungryMode_multiThread* single;
	static int count;
};


//note 静态变量类外初始化
SingletonHungryMode_multiThread* SingletonHungryMode_multiThread::single = new SingletonHungryMode_multiThread();

int SingletonHungryMode_multiThread::count = 0;

int _tmainHungry(int argc, _TCHAR* argv[])
{
	SingletonHungryMode_multiThread* s1 = SingletonHungryMode_multiThread::getSingelton();
	SingletonHungryMode_multiThread* s2 = SingletonHungryMode_multiThread::getSingelton();
	if (s1 == s2)
	{
		cout << "ok....equal" << endl;
	}
	else
	{
		cout << "not.equal" << endl;
	}
	s1->pirntS();
	SingletonHungryMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}

unsigned int hungrythreadfunc2(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	return 1;
}

void hungrythreadfunc(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	SingletonHungryMode_multiThread::getSingelton()->pirntS();
	return;
}

int _tmain_tmainHungry(int argc, _TCHAR* argv[])
{
	int i = 0;
	DWORD dwThreadId[201], dwThrdParam = 1;
	HANDLE hThread[201];
	int threadnum = 3;

	for (i = 0; i < threadnum; i++)
	{
		//hThread[i] = (HANDLE)_beginthreadex( NULL, 0, &threadfunc, NULL, 0,&dwThreadId[i] );
		hThread[i] = (HANDLE)_beginthread(&hungrythreadfunc, 0, 0);
		if (hThread[i] == NULL)
		{
			printf("begin thread %d error!!!\n", i);
			break;
		}
	}
	//等待所有的子线程都运行完毕后,才执行 这个代码
	for (i = 0; i < threadnum; i++)
	{
		WaitForSingleObject(hThread[i], INFINITE);
	}
	printf("等待线程结束\n");
	for (i = 0; i < threadnum; i++)
	{
		//CloseHandle( hThread[i] );
	}
	SingletonHungryMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
