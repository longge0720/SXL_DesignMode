#include <iostream>
using namespace std;
#include "BridgeMode.h"


int main()
{
	OS* pIOS1 = new IOSSubSystem1();
	//Phone* iphone = new Phone(); ������ʹ�ó����ഴ������ 
	Phone* iphone4 = new iPhone(pIOS1);//��������ʹ��ʵ���˳����ി�麯�������� �������� ��ֵ��������
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
