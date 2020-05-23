#include <iostream>
using namespace std;
#include "ProtoType.h"

int main()
{
	Prototype* proA = new ConcretePrototype();
	Prototype* proB = proA->clone();
	Prototype* proC = proA->clone();
	Prototype* proD = proC->clone();

	cout << proA->getName() << endl;
	cout << proB->getName() << endl;
	cout << proC->getName() << endl;
	cout << proD->getName() << endl;
	delete proA; proA = nullptr;
	delete proB; proB = nullptr;
	delete proC; proC = nullptr;
	delete proD; proD = nullptr;


	return 0;
}