#include "ProxyMode.h"
#include <iostream>
using namespace std;



int main()
{
	ProxyTaoBao ptb;
	
	ptb.SaleProduct(eStrategy::NORMAL);
	ptb.SaleProduct(eStrategy::DOUBLE_11);
	ptb.SaleProduct(eStrategy::DOUBLE_12);

	return 0;
}