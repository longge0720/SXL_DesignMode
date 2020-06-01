#pragma once
//享元模式 一共分为三个部分
//抽象享元角色、具体享元角色、享元工厂角色
//其关键是把一堆对象放到一个池子里 共同管理 有一样的需求就从里面取 而不再重新创建
#include <iostream>
using namespace std;
#include "string"
#include "map"

//抽象享元 “人”
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

//具体享元 “老师”
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

//享元工厂
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
	//通过Teacher的pool，来存放老师结点，在TeacherFactory中创建老师、销毁老师
	Teacher* getTeacher(string tid)
	{
		string	name;
		int		age;
		int		sex;

		Teacher* tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(tid);
		if (it == m_tpool.end())
		{
			cout << "id为: " << tid << " 的老师不存在,系统为你创建该老师，请输入以下信息" << endl;
			cout << "请输入老师姓名：";
			cin >> name;
			cout << "请输入老师年龄：";
			cin >> age;
			cout << "请输入老师性别 1男 2女：";
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
