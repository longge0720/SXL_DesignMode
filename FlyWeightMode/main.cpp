#include "FlyWeightMode.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Teacher *t1 = new Teacher("001", "С��", 30, 1);
	Teacher *t2 = new Teacher("002", "С��", 30, 1);
	Teacher *t3 = new Teacher("001", "С��", 30, 1);
	Teacher *t4 = new Teacher("004", "С��", 30, 1);
	//
	cout << "t1 t3�� ����һ��������Ҳ����ͬһ���� " << endl;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	*/
	TeacherFactory* teacherFactory = new TeacherFactory;
	Teacher* t1 = teacherFactory->getTeacher("001");
	t1->printT();

	Teacher* t2 = teacherFactory->getTeacher("001");
	t2->printT();
	delete teacherFactory;
	system("pause");


	return 0;
}