#include <iostream>
using namespace std;
#include "FactoryMode.h"


void testFactory()
{
	FruitFactory* ff = nullptr;
	Fruit* fruit = nullptr;

	ff = new BananaFactory();
	fruit = ff->getFruit();
	fruit->sayName();

	delete fruit;
	delete ff;

	ff = new AppleFactory();
	fruit = ff->getFruit();
	fruit->sayName();

	delete fruit;
	delete ff;

	ff = new PearFactory();
	fruit = ff->getFruit();
	fruit->sayName();

	delete fruit;
	delete ff;

	system("pause");

}





int main(void)
{
	testFactory();
	return 0;
}