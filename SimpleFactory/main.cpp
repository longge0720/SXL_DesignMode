#include <iostream>
using namespace std;
#include "SimpleFactoryMode.h"


void testSimpleFactory()
{
	Fruit* pear = sFactory::createFruit("pear");
	if (pear == NULL)
	{
		cout << "����pearʧ��\n";
	}
	pear->getFruit();

	Fruit* banana = sFactory::createFruit("banana");
	if (banana == NULL)
	{
		cout << "����bananaʧ��\n";
	}
	banana->getFruit();

	system("pause");

}





int main(void)
{
	testSimpleFactory();
	return 0;
}