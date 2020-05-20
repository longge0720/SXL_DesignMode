#include <iostream>
using namespace std;
#include "AbstractFactoryMode.h"


void testAbstractFactoryMode()
{
	FruitFactory* ff = NULL;
	Fruit* fruit = NULL;

	ff = new SouthFruitFactory();
	fruit = ff->getApple();
	fruit->sayName();
	fruit = ff->getBanana();
	fruit->sayName();

	delete fruit;
	delete ff;

	ff = new NorthFruitFactory();
	fruit = ff->getApple();
	fruit->sayName();
	fruit = ff->getBanana();
	fruit->sayName();

	delete fruit;
	delete ff;

	system("pause");


}





int main(void)
{
	testAbstractFactoryMode();
	return 0;
}