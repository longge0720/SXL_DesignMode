#include "Composite.h"
#include <iostream>

using namespace std;

int main()
{
    /*
      ������Ҷ��Leaf����Composite����pRoot��pCom��ʵ����Operation�ӿڣ����Կ���һ�¶Դ���ֱ�ӵ���Operation()
      �����ˡ�ʹ���û��Ե����������϶����ʹ�þ���һ���ԡ���
    */
    Composite* pRoot = new Composite();

    //��϶������Ҷ�ӽڵ�
    pRoot->Add(new Leaf());

    Leaf* pLeaf1 = new Leaf();
    Leaf* pLeaf2 = new Leaf();

    ////�����Ҷ�������Ҷ����û������ġ�
    ////����Ҷ������϶���̳�����ͬ�Ľӿڣ������﷨���ǶԵģ�ʵ����ʲôҲû��(�̳��Ի���Component��Add����)��
    ////Ҷ�ӽڵ�ֻʵ����Operation����������Add��Remove��GetChild���̳��Ի��࣬û��ʵ�����塣
    //pLeaf1->Add(pLeaf2);
    //pLeaf1->Remove(pLeaf2);
    ////ִ��Ҷ��Operation����
    //pLeaf1->Operation();

    //��϶���ʵ���˻���Component�����нӿڣ����Կ��������ֲ���(Add��Remove��GetChild��Operation)��
    Composite* pCom = new Composite();
    //��϶������Ҷ�ӽڵ�
    pCom->Add(pLeaf1);
    //��϶������Ҷ�ӽڵ�
    pCom->Add(pLeaf2);
    //ִ����϶���Operation����
    pCom->Operation();

    //��϶��������϶���
    pRoot->Add(pCom);

    //ִ����϶���Operation����
    pRoot->Operation();

    //Component* cp = pCom->GetChild(0);
    //cp->Operation();

    //pCom->Remove(pLeaf1);

    return 0;
}