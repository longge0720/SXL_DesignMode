#pragma once
#include <iostream>
using namespace std;
//ʵ�ַ��� ����ģʽ ���ȴ���һ��ȫ�ֱ�������
//a)	���캯��˽�л�
//b)	�ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
//c)	�����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��

//����ģʽ
class SingletonHungryMode
{
private:
	//3. �����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��
	static SingletonHungryMode* m_psl;
	static int SingletonCount;
private:
	//1.���캯��˽�л�
	SingletonHungryMode()
	{
		cout << "SingletonHungry���캯��ִ�д���:" << SingletonCount << endl;
	}
public:
	//2.�ṩһ��ȫ�ֵľ�̬���� �������ص�������
	static SingletonHungryMode* getInstance()
	{
		//if (m_psl == nullptr)
		//{
		//	SingletonCount++;
		//	m_psl = new SingletonHungryMode();
		//}

		return m_psl;
	}

	//�ͷŵ���
	static void freeInstance()
	{
		if (m_psl != nullptr)
		{
			delete m_psl;
			SingletonCount--;
		}
		m_psl = nullptr;//ָ���ָ��ָ��Ŀռ������������Ҫ�ͷ�
	}
};
//��ľ�̬��Ա�ĳ�ʼ��
SingletonHungryMode* SingletonHungryMode::m_psl = new SingletonHungryMode;
int SingletonHungryMode::SingletonCount = 1;