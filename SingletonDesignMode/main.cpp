#include <iostream>
using namespace std;
#include "SingletonLazyMode.h"
#include "SingletonHungryMode.h"
#include "SingletonLazyMode_multiThread.h"
#include "SingletonHungryMode_multiThread.h"
#include "SingletonLazyModeDoubleCheck.h"

void testSingletonLazyModeDoubleCheck()
{
	//_tmainTTT(0, nullptr);//�Ƕ��̵߳������ ����ģʽ����û������
	_tmainDC(0, nullptr);//���߳�ģʽ������ģʽ�ĵ���ģʽ �ܿ��ܻᵼ�� �����������
}

void testSingletonHungryMode_multiThread()
{
	//_tmainHungry(0, nullptr);//�Ƕ��̵߳������ 
	_tmain_tmainHungry(0, nullptr);//
}

void testSingletonLazyMode_multiThread()
{
	//_tmainTTT(0, nullptr);//�Ƕ��̵߳������ ����ģʽ����û������
	_tmain(0, nullptr);//���߳�ģʽ������ģʽ�ĵ���ģʽ �ܿ��ܻᵼ�� �����������
}

void testSingletonLazyMode()
{
	SingletonLazyMode* p1 = SingletonLazyMode::getInstance();
	SingletonLazyMode* p2 = SingletonLazyMode::getInstance();

	if (p1 == p2)
	{
		cout << "����ģʽ�ɹ������ζ���Ϊͬһ��" << endl;
	}
	else
	{
		cout << "����ģʽʧ�ܣ����ζ���Ϊͬһ��" << endl;
	}

	SingletonLazyMode::freeInstance();
}

void testSingletonHungryMode()
{
	SingletonHungryMode* p1 = SingletonHungryMode::getInstance();
	SingletonHungryMode* p2 = SingletonHungryMode::getInstance();

	if (p1 == p2)
	{
		cout << "����ģʽ�ɹ������ζ���Ϊͬһ��" << endl;
	}
	else
	{
		cout << "����ģʽʧ�ܣ����ζ���Ϊͬһ��" << endl;
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