//#include "stdafx.h"
#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"
#include <tchar.h>

using namespace std;
/////////////////////////////////////////////////////
////饿汉模式
//class SingletonLazyMode_multiThread
//{
//private:
//	SingletonLazyMode_multiThread()
//	{
//		count++;
//		cout << "SingletonLazyMode_multiThread构造函数begin\n" << endl;
//		Sleep(1000);
//		cout << "SingletonLazyMode_multiThread构造函数end\n" << endl;
//
//	}
//private:
//	//防止拷贝构造和赋值操作
//	SingletonLazyMode_multiThread(const SingletonLazyMode_multiThread& obj) { ; }
//	SingletonLazyMode_multiThread& operator=(const SingletonLazyMode_multiThread& obj) { ; }
//public:
//	static SingletonLazyMode_multiThread* getSingelton()
//	{
//		//1"懒汉"模式虽然有优点，但是每次调用GetInstance()静态方法时，必须判断
//		//	NULL == m_instance，使程序相对开销增大。
//		//2多线程中会导致多个实例的产生，从而导致运行代码不正确以及内存的泄露。
//		//3提供释放资源的函数
//		return single;
//	}
//
//	static SingletonLazyMode_multiThread* releaseSingelton()
//	{
//		if (single != NULL) //需要判断
//		{
//			cout << "释放资源\n" << endl;
//			delete single;
//			single = NULL;
//		}
//		return single;
//	}
//	void pirntS() //测试函数
//	{
//		printf("Singelton printS test count:%d \n", count);
//	}
//
//private:
//	static SingletonLazyMode_multiThread* single;
//	static int count;
//};


class SingletonLazyMode_multiThread
{
private:
		SingletonLazyMode_multiThread()
		{
			count++;
			cout << "SingletonLazyMode_multiThread构造函数begin\n" << endl;
			Sleep(1000);
			cout << "SingletonLazyMode_multiThread构造函数end\n" << endl;
	
		}
private:
	//防止拷贝构造和赋值操作
	SingletonLazyMode_multiThread(const SingletonLazyMode_multiThread& obj) { ; }
	SingletonLazyMode_multiThread& operator=(const SingletonLazyMode_multiThread& obj) { ; }
public:
	static SingletonLazyMode_multiThread* getSingelton()
	{
		//1"懒汉"模式虽然有优点，但是每次调用GetInstance()静态方法时，必须判断
		//	NULL == m_instance，使程序相对开销增大。
		//2多线程中会导致多个实例的产生，从而导致运行代码不正确以及内存的泄露。
		//3提供释放资源的函数
		if (single == nullptr)
		{
			single = new SingletonLazyMode_multiThread();
		}
		return single;
	}

	static SingletonLazyMode_multiThread* releaseSingelton()
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
	static SingletonLazyMode_multiThread* single;
	static int count;
};
//note 静态变量类外初始化
//SingletonLazyMode_multiThread* SingletonLazyMode_multiThread::single = new SingletonLazyMode_multiThread();
SingletonLazyMode_multiThread* SingletonLazyMode_multiThread::single = nullptr;
int SingletonLazyMode_multiThread::count = 0;

int _tmainTTT(int argc, _TCHAR* argv[])
{
	SingletonLazyMode_multiThread* s1 = SingletonLazyMode_multiThread::getSingelton();
	SingletonLazyMode_multiThread* s2 = SingletonLazyMode_multiThread::getSingelton();
	if (s1 == s2)
	{
		cout << "ok....equal" << endl;
	}
	else
	{
		cout << "not.equal" << endl;
	}
	s1->pirntS();
	SingletonLazyMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}

unsigned int threadfunc2(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	return 1;
}

void threadfunc(void* myIpAdd)
{
	int id = GetCurrentThreadId();
	printf("\n threadfunc%d \n", id);
	SingletonLazyMode_multiThread::getSingelton()->pirntS();
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	DWORD dwThreadId[201], dwThrdParam = 1;
	HANDLE hThread[201];
	int threadnum = 3;

	for (i = 0; i < threadnum; i++)
	{
		//hThread[i] = (HANDLE)_beginthreadex( NULL, 0, &threadfunc, NULL, 0,&dwThreadId[i] );
		hThread[i] = (HANDLE)_beginthread(&threadfunc, 0, 0);
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
	SingletonLazyMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
