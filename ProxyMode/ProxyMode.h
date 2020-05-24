#pragma once
#include <iostream>
using namespace std;
//����ģʽ
//��һ�������� ��Ϊʵ���ࣨ���糧�ң��ĸ��࣬�ʹ����ࣨ�����̣��ĸ��� �����涨��һ�����󷽷���������
//ʵ���ࣨ���ң����Լ���ʵ�����۷��� �۸����������� �ȵ�
//�����ࣨ�����̣���ʵ����Ļ����� �Լ۸��������� ���������Խ��� �µĶ���
enum eStrategy
{
	NORMAL,
	DOUBLE_11,
	DOUBLE_12
};
//����ӿ� ����
class Interface
{
public:
	virtual void SaleProduct(eStrategy strategy) = 0;
};

class Factory:public Interface
{
public:
	virtual void SaleProduct(eStrategy strategy){ cout << "�����޲��ԣ�����ֱ��....\n"; }
};

class ProxyTaoBao :public Interface
{
public:
	virtual void SaleProduct(eStrategy strategy)
	{ 
		fc.SaleProduct(strategy);
		switch (strategy)
		{
		case NORMAL: {cout << "����������ӯ���۸�*1.5��" << endl; }break;
		case DOUBLE_11: {cout << "������˫11�������������" << endl; }break;
		case DOUBLE_12: {cout << "������˫12���������ԭ��" << endl; }break;
		default:break;

		}	
		 
	}
private:
	Factory fc;
};