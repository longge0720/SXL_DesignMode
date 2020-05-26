#include "DecorateMode.h"
#include <iostream>
using namespace std;


int main()
{
	Phone* iphone = new NokiaPhone("6300");
	Phone* dpa = new DecoratorPhoneA(iphone);
	Phone* dpb = new DecoratorPhoneB(dpa);
	dpb->ShowDecorate();
	delete dpa;
	delete dpb;
	delete iphone;


	return 0;
}