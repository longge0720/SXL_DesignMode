#pragma once
#include <iostream>
using namespace std;

//适配器模式 是改变现有接口的内部实现
//创建几个工具类 供其他类使用
//创建适配器 适配器要继承目标类 并且有一个需适配类的成员对象

class Target {  // Target，客户期望的接口，可以使具体或抽象的类，也可以是接口
public:
    virtual void Request() = 0;
    virtual ~Target() {};
};

class Adaptee { // 需适配的类
public:
    void SpecificRequest() { cout << "Adaptee" << endl; }
};

class Adapter : public Target { // 通过内部包装一个Adaptee对象，把源接口转换为目标接口：
private:
    Adaptee* adaptee;
public:
    Adapter() { adaptee = new Adaptee(); }
    void Request() { adaptee->SpecificRequest(); }  // 调用Request()方法会转换成调用adaptee.SpecificRequest()
    ~Adapter() { delete adaptee; }
};