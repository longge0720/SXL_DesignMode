#include "ProxyMode.h"
#include <iostream>
using namespace std;



int main()
{
	ProxyTaoBao ptb;
	
	ptb.SaleProduct(NORMAL);
	ptb.SaleProduct(DOUBLE_11);
	ptb.SaleProduct(DOUBLE_12);

	return 0;
}