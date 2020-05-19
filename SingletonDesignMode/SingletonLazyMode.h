#pragma once
#include <iostream>
using namespace std;
//ʵ�ַ��� ����ģʽ ÿ��ֻ�е���̬ȫ�ֱ���Ϊnullʱ�Ŵ���
//a)	���캯��˽�л�
//b)	�ṩһ��ȫ�ֵľ�̬������ȫ�ַ��ʵ㣩
//c)	�����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��

//����ģʽ
class SingletonLazyMode
{
private:
	//3. �����ж���һ����ָ̬�룬ָ����ı����ľ�̬����ָ��
	static SingletonLazyMode*m_psl;
	static int SingletonCount;
private:
	//1.���캯��˽�л�
	SingletonLazyMode()
	{
		cout << "SingletonLazy���캯��ִ�д���:" << SingletonCount << endl;
	}
public:
	//2.�ṩһ��ȫ�ֵľ�̬���� �������ص�������
	static SingletonLazyMode* getInstance()
	{
		if (m_psl == nullptr)
		{
			SingletonCount++;
			m_psl = new SingletonLazyMode();
		}

		return m_psl;
	}

	//�ͷŵ���
	static void freeInstance()
	{
		if (m_psl != nullptr)//����ģʽ ÿ��ֻ�е���̬ȫ�ֱ���Ϊnullʱ�Ŵ���
		{
			delete m_psl;
			SingletonCount--;
		}
		m_psl = nullptr;//ָ���ָ��ָ��Ŀռ������������Ҫ�ͷ�
	}
};
//��ľ�̬��Ա�ĳ�ʼ��
SingletonLazyMode* SingletonLazyMode::m_psl = nullptr;
int SingletonLazyMode::SingletonCount = 0;