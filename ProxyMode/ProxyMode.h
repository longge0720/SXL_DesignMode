#pragma once
#include <iostream>
using namespace std;
//代理模式
//有一个抽象类 作为实体类（比如厂家）的父类，和代理类（经销商）的父类 ，里面定义一个抽象方法（卖货）
//实体类（厂家）有自己真实的销售方法 价格、数量、策略 等等
//代理类（经销商）在实体类的基础上 对价格数量方法 等销售属性进行 新的定义
enum eStrategy
{
	NORMAL,
	DOUBLE_11,
	DOUBLE_12
};
//抽象接口 销售
class Interface
{
public:
	virtual void SaleProduct(eStrategy strategy) = 0;
};

class Factory:public Interface
{
public:
	virtual void SaleProduct(eStrategy strategy){ cout << "进货无策略，厂家直销....\n"; }
};

class ProxyTaoBao :public Interface
{
public:
	virtual void SaleProduct(eStrategy strategy)
	{ 
		fc.SaleProduct(strategy);
		switch (strategy)
		{
		case NORMAL: {cout << "代理商正常盈利价格*1.5倍" << endl; }break;
		case DOUBLE_11: {cout << "代理商双11活动超级大促销半价" << endl; }break;
		case DOUBLE_12: {cout << "代理商双12活动促销厂家原价" << endl; }break;
		default:break;

		}	
		 
	}
private:
	Factory fc;
};