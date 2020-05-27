#include <iostream>
using namespace std;
#include "AdapterMode.h"
//适配器模式还不是很明白
int main() 
{
    Target* target = new Adapter();
    target->Request();

    delete target;
    return 0;
}