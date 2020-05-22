#include "ConstructorMode.h"
#include <iostream>
using namespace std;

void main()
{
	//�ͻ�ֱ���췿��
	//�ŵ� ���������� 
	//ȱ�� û�н� һ������� ��װ���� ȱ����������˼�� �򵥴ֱ� �������
	//House* pHose = new House;
	//pHose->setDoor("wbm��");
	//pHose->setFloor("wbmFloor");
	//pHose->setWall("wbmWall");
	//delete pHose;


	////���̶�ֱ���췿��
	////�ŵ� �Ծ���Ľ���ϸ�� �����˷�װ 
	////ȱ�� ����Խϲ� һ�������б䶯 ���̶ӽ���������
	//Builder *builder = new FlatBuild;
	//builder->makeFloor();
	//builder->makeWall();
	//builder->makeDoor();


	//���ʦ--��ָ�Ӳ�ͬ�Ĺ��̶�--�����첻ͬ����ķ���

	//ָ���ߣ����ʦ��ָ�� ���̶� �� ������
	Director* director = new Director;

	//����Ԣ ��Ҫ��Ԣ���� ��Ԣ���̶�ȥ����
	Builder* builder = new FlatBuild;
	director->Construct(builder); //���ʦ ָ�� ���̶Ӹɻ�
	House* house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;

	//������  //��Ҫ�������ñ������̶�ȥ����
	builder = new VillaBuild;//���ʱ���Ѿ������˷����������
	//ֻ�������������еķ��� ����û�еõ���Ӧ�ĳ�ʼ�� 
	//�����Ϊ ��ȻҪ�ұ������̶� �������Ѿ�ȷ�����ǽ�������� ���̶� �Ǵ��ű�����˼��� ��������
	director->Construct(builder); //���ʦ ָ�� ���̶Ӹɻ� ����ط����Ѿ��������ڲ�����װ�������
	house = builder->GetHouse();//����ط�ֻ�������õ�������ӵ�Կ�׶��� ������ǰ����������
	cout << house->getFloor() << endl;
	delete house;
	delete builder;

	delete director;

	system("pause");
	return;
}
