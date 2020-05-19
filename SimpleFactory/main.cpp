#include <iostream>
using namespace std;
#include "SimpleFactoryMode.h"


void testSimpleFactory()
{
	Fruit* pear = sFactory::createFruit("pear");
	if (pear == NULL)
	{
		cout << "创建pear失败\n";
	}
	pear->getFruit();

	Fruit* banana = sFactory::createFruit("banana");
	if (banana == NULL)
	{
		cout << "创建banana失败\n";
	}
	banana->getFruit();

	system("pause");

}





int main(void)
{
	testSimpleFactory();
	return 0;
}