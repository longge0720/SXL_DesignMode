//#include "stdafx.h"
#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"
#include <tchar.h>

using namespace std;
/////////////////////////////////////////////////////
////����ģʽ
//class SingletonLazyMode_multiThread
//{
//private:
//	SingletonLazyMode_multiThread()
//	{
//		count++;
//		cout << "SingletonLazyMode_multiThread���캯��begin\n" << endl;
//		Sleep(1000);
//		cout << "SingletonLazyMode_multiThread���캯��end\n" << endl;
//
//	}
//private:
//	//��ֹ��������͸�ֵ����
//	SingletonLazyMode_multiThread(const SingletonLazyMode_multiThread& obj) { ; }
//	SingletonLazyMode_multiThread& operator=(const SingletonLazyMode_multiThread& obj) { ; }
//public:
//	static SingletonLazyMode_multiThread* getSingelton()
//	{
//		//1"����"ģʽ��Ȼ���ŵ㣬����ÿ�ε���GetInstance()��̬����ʱ�������ж�
//		//	NULL == m_instance��ʹ������Կ�������
//		//2���߳��лᵼ�¶��ʵ���Ĳ������Ӷ��������д��벻��ȷ�Լ��ڴ��й¶��
//		//3�ṩ�ͷ���Դ�ĺ���
//		return single;
//	}
//
//	static SingletonLazyMode_multiThread* releaseSingelton()
//	{
//		if (single != NULL) //��Ҫ�ж�
//		{
//			cout << "�ͷ���Դ\n" << endl;
//			delete single;
//			single = NULL;
//		}
//		return single;
//	}
//	void pirntS() //���Ժ���
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
			cout << "SingletonLazyMode_multiThread���캯��begin\n" << endl;
			Sleep(1000);
			cout << "SingletonLazyMode_multiThread���캯��end\n" << endl;
	
		}
private:
	//��ֹ��������͸�ֵ����
	SingletonLazyMode_multiThread(const SingletonLazyMode_multiThread& obj) { ; }
	SingletonLazyMode_multiThread& operator=(const SingletonLazyMode_multiThread& obj) { ; }
public:
	static SingletonLazyMode_multiThread* getSingelton()
	{
		//1"����"ģʽ��Ȼ���ŵ㣬����ÿ�ε���GetInstance()��̬����ʱ�������ж�
		//	NULL == m_instance��ʹ������Կ�������
		//2���߳��лᵼ�¶��ʵ���Ĳ������Ӷ��������д��벻��ȷ�Լ��ڴ��й¶��
		//3�ṩ�ͷ���Դ�ĺ���
		if (single == nullptr)
		{
			single = new SingletonLazyMode_multiThread();
		}
		return single;
	}

	static SingletonLazyMode_multiThread* releaseSingelton()
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
	static SingletonLazyMode_multiThread* single;
	static int count;
};
//note ��̬���������ʼ��
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
	SingletonLazyMode_multiThread::releaseSingelton();
	cout << "hello...." << endl;
	system("pause");
	return 0;
}
