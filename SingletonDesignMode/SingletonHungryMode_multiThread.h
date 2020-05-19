#pragma once
//#include "stdafx.h"
#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"
#include <tchar.h>

using namespace std;
///////////////////////////////////////////////////
//����ģʽ
class SingletonHungryMode_multiThread
{
private:
	SingletonHungryMode_multiThread()
	{
		count++;
		cout << "SingletonHungryMode_multiThread���캯��begin\n" << endl;
		Sleep(1000);
		cout << "SingletonHungryMode_multiThread���캯��end\n" << endl;

	}
private:
	//��ֹ��������͸�ֵ����
	SingletonHungryMode_multiThread(const SingletonHungryMode_multiThread& obj) { ; }
	SingletonHungryMode_multiThread& operator=(const SingletonHungryMode_multiThread& obj) { ; }
public:
	static SingletonHungryMode_multiThread* getSingelton()
	{
		//1"����"ģʽ��Ȼ���ŵ㣬����ÿ�ε���GetInstance()��̬����ʱ�������ж�
		//	NULL == m_instance��ʹ������Կ�������
		//2���߳��лᵼ�¶��ʵ���Ĳ������Ӷ��������д��벻��ȷ�Լ��ڴ��й¶��
		//3�ṩ�ͷ���Դ�ĺ���
		return single;
	}

	static SingletonHungryMode_multiThread* releaseSingelton()
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
	static SingletonHungryMode_multiThread* single;
	static int count;
};


//note ��̬���������ʼ��
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
	SingletonHungryMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
