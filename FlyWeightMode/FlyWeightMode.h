#pragma once
//��Ԫģʽ һ����Ϊ��������
//������Ԫ��ɫ��������Ԫ��ɫ����Ԫ������ɫ
//��ؼ��ǰ�һ�Ѷ���ŵ�һ�������� ��ͬ���� ��һ��������ʹ�����ȡ ���������´���
#include <iostream>
using namespace std;
#include "string"
#include "map"

//������Ԫ ���ˡ�
class Person
{
public:
	Person(string name,int age,int sex)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
	}
	string getName() { return name; }
	int getAge() { return age; }
	int getSex() { return sex; }
protected:
	string name;
	int age;
	int sex;
};

//������Ԫ ����ʦ��
class Teacher:public Person
{
public:
	Teacher(string id, string name, int age, int sex) :Person(name ,age ,sex)
	{
		this->id = id;
	}
	string getId() { return id; }
	void printT()
	{
		cout << "id:" << id << "\t" << "name:" << name << "\t" << "age:" << age << "\t" << "sex:" << sex << "\t" << endl;
	}

private:
	string id;
};

//��Ԫ����
class TeacherFactory
{
public:
	TeacherFactory() { m_tpool.empty(); }
	~TeacherFactory()
	{ 
		while (!m_tpool.empty())
		{
			Teacher* tmp = nullptr;
			map<string, Teacher*>::iterator it = m_tpool.begin();
			tmp = it->second;
			m_tpool.erase(it);
			delete tmp;
		}
	}
	//ͨ��Teacher��pool���������ʦ��㣬��TeacherFactory�д�����ʦ��������ʦ
	Teacher* getTeacher(string tid)
	{
		string	name;
		int		age;
		int		sex;

		Teacher* tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(tid);
		if (it == m_tpool.end())
		{
			cout << "idΪ: " << tid << " ����ʦ������,ϵͳΪ�㴴������ʦ��������������Ϣ" << endl;
			cout << "��������ʦ������";
			cin >> name;
			cout << "��������ʦ���䣺";
			cin >> age;
			cout << "��������ʦ�Ա� 1�� 2Ů��";
			cin >> sex;
			tmp = new Teacher(tid, name, age, sex);
			m_tpool.insert(pair<string, Teacher*>(tid, tmp));
		}
		else
		{
			tmp = (it->second);
		}
		return tmp;
	}

private:
	map<string, Teacher*> m_tpool;
};
