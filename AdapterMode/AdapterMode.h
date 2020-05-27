#pragma once
#include <iostream>
using namespace std;

//������ģʽ �Ǹı����нӿڵ��ڲ�ʵ��
//�������������� ��������ʹ��
//���������� ������Ҫ�̳�Ŀ���� ������һ����������ĳ�Ա����

class Target {  // Target���ͻ������Ľӿڣ�����ʹ����������࣬Ҳ�����ǽӿ�
public:
    virtual void Request() = 0;
    virtual ~Target() {};
};

class Adaptee { // ���������
public:
    void SpecificRequest() { cout << "Adaptee" << endl; }
};

class Adapter : public Target { // ͨ���ڲ���װһ��Adaptee���󣬰�Դ�ӿ�ת��ΪĿ��ӿڣ�
private:
    Adaptee* adaptee;
public:
    Adapter() { adaptee = new Adaptee(); }
    void Request() { adaptee->SpecificRequest(); }  // ����Request()������ת���ɵ���adaptee.SpecificRequest()
    ~Adapter() { delete adaptee; }
};