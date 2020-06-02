#include "TemplateMode.h"
#include <iostream>
using namespace std;

int main()
{
	MakeCar* bus = new MakeBus;

	//bus->makeHead();
	//bus->makeBody();
	//bus->makeTail();
	bus->make();

	MakeCar* jeep = new MakeJeep;
	//jeep->makeHead();
	//jeep->makeBody();
	//jeep->makeTail();
	jeep->make();

	delete bus;
	delete jeep;

}