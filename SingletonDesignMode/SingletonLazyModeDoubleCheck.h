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
		cout << "SingletonLazyModeDoubleCheck���캯��begin\n" << endl;
		Sleep(1000);
		cout << "SingletonLazyModeDoubleCheck���캯��end\n" << endl;

	}
private:
	//��ֹ��������͸�ֵ����
	SingletonLazyModeDoubleCheck(const SingletonLazyModeDoubleCheck& obj) { ; }
	SingletonLazyModeDoubleCheck& operator=(const SingletonLazyModeDoubleCheck& obj) { ; }
public:
	static SingletonLazyModeDoubleCheck* getSingelton()
	{
		//�����ж϶����Ƿ�Ϊ�ղ����м���
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
		if (single != NULL) //��Ҫ�ж�
		{
			cout << "�ͷ���Դ\n" << endl;
			delete single;
			single = NULL;
		}
		return single;
	}
	void pirntS() //���Ժ���
	{
		printf("Singelton printS test count:%d \n", count);
	}

private:
	static SingletonLazyModeDoubleCheck* single;
	static int count;
};
//note ��̬���������ʼ��
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
	//�ȴ����е����̶߳�������Ϻ�,��ִ�� �������
	for (i = 0; i < threadnum; i++)
	{
		WaitForSingleObject(hThread[i], INFINITE);
	}
	printf("�ȴ��߳̽���\n");
	for (i = 0; i < threadnum; i++)
	{
		//CloseHandle( hThread[i] );
	}
	SingletonLazyModeDoubleCheck::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
