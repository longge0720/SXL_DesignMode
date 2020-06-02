#pragma once
#include <iostream>
using namespace std;


//Template Method模式一般应用在具有以下条件
//的应用中：
//- 具有统一的操作步骤或操作过程
//- 具有不同的操作细节
//- 存在多个具有同样操作步骤的应用场景，但某些具体的操作细节却各不相同
//总结：
//在抽象类中统一操作步骤，并规定好接口；让子类实现接口。这样可以把各个具体的子类和操作步骤接耦合
//AbstractClass：
//抽象类的父类
//ConcreteClass：
//具体的实现子类
//templateMethod()：
//模板方法
//method1()与method2()：
//具体步骤方法


class MakeCar
{
public:
	virtual void makeHead() = 0;
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};

class MakeBus:public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "bus 组装 车头" << endl;
	}
	virtual void makeBody()
	{
		cout << "bus 组装 车身" << endl;
	}
	virtual void makeTail()
	{
		cout << "bus 组装 车尾" << endl;
	}

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};

class MakeJeep :public MakeCar
{
public:
	virtual void makeHead()
	{
		cout << "Jeep 组装 车头" << endl;
	}
	virtual void makeBody()
	{
		cout << "Jeep 组装 车身" << endl;
	}
	virtual void makeTail()
	{
		cout << "Jeep 组装 车尾" << endl;
	}

public:
	void make()
	{
		makeHead();
		makeBody();
		makeTail();
	}
};