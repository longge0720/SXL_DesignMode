#include <iostream>
using namespace std;
#include "BridgeMode.h"


int main()
{
	OS* pIOS1 = new IOSSubSystem1();
	//Phone* iphone = new Phone(); 不允许使用抽象类创建对象 
	Phone* iphone4 = new iPhone(pIOS1);//但是允许使用实现了抽象类纯虚函数的子类 创建对象 赋值给抽象类
	iphone4->setOS();

	OS* pIOS2 = new IOSSubSystem2();
	Phone* iphoneX = new iPhone(pIOS2);
	iphoneX->setOS();

	OS* pSaiBian1 = new SaiBianSubSystem1();
	NokiaPhone* NokiaN72 = new NokiaPhone(pSaiBian1);
	NokiaN72->setOS();

	OS* pSaiBian2 = new SaiBianSubSystem2();
	NokiaPhone* Nokia6300 = new NokiaPhone(pSaiBian2);
	Nokia6300->setOS();

	return EXIT_SUCCESS;
}
