#include <iostream>
using namespace std;
#include "AdapterMode.h"
//������ģʽ�����Ǻ�����
int main() 
{
    Target* target = new Adapter();
    target->Request();

    delete target;
    return 0;
}