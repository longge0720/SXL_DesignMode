#pragma once
//#include "stdafx.h"
#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"
#include <tchar.h>
#include <thread>
#include <mutex>

using namespace std;
mutex mux;
class SingletonLazyModeDoubleCheck
{
private:
	SingletonLazyModeDoubleCheck()
	{
		count++;
		cout << "SingletonLazyModeDoubleCheck构造函数begin\n" << endl;
		Sleep(1000);
		cout << "SingletonLazyModeDoubleCheck构造函数end\n" << endl;

	}
private:
	//防止拷贝构造和赋值操作
	SingletonLazyModeDoubleCheck(const SingletonLazyModeDoubleCheck& obj) { ; }
	SingletonLazyModeDoubleCheck& operator=(const SingletonLazyModeDoubleCheck& obj) { ; }
public:
	static SingletonLazyModeDoubleCheck* getSingelton()
	{
		//两次判断对象是否为空并进行加锁
		if (single == nullptr)
		{
			mux.lock();
			if (single == nullptr)
			{
				single = new SingletonLazyModeDoubleCheck();
			}
			mux.unlock();
		}
		return single;
	}

	static SingletonLazyModeDoubleCheck* releaseSingelton()
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
	static SingletonLazyModeDoubleCheck* single;
	static int count;
};
//note 静态变量类外初始化
//SingletonLazyModeDoubleCheck* SingletonLazyModeDoubleCheck::single = new SingletonLazyModeDoubleCheck();
SingletonLazyModeDoubleCheck* SingletonLazyModeDoubleCheck::single = nullptr;
int SingletonLazyModeDoubleCheck::count = 0;

int _tmainTTTDC(int argc, _TCHAR* argv[])
{
	SingletonLazyModeDoubleCheck* s1 = SingletonLazyModeDoubleCheck::getSingelton();
	SingletonLazyModeDoubleCheck* s2 = SingletonLazyModeDoubleCheck::getSingelton();
	if (s1 == s2)
	{
		cout << "ok....equal" << endl;
	}
	else
	{
		cout << "not.equal" << endl;
	}
	s1->pirntS();
	SingletonLazyModeDoubleCheck::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}

unsigned int threadfunc2DC(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	return 1;
}

void threadfuncDC(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	SingletonLazyModeDoubleCheck::getSingelton()->pirntS();
	return;
}

int _tmainDC(int argc, _TCHAR* argv[])
{
	int i = 0;
	DWORD dwThreadId[201], dwThrdParam = 1;
	HANDLE hThread[201];
	int threadnum = 3;

	for (i = 0; i < threadnum; i++)
	{
		//hThread[i] = (HANDLE)_beginthreadex( NULL, 0, &threadfunc, NULL, 0,&dwThreadId[i] );
		hThread[i] = (HANDLE)_beginthread(&threadfuncDC, 0, 0);
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
	SingletonLazyModeDoubleCheck::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
