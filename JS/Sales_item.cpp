#include "stdafx.h"
#include "Sales_item.h"

//  ������ƽ���۸�
double Sales_item::avg_price() const{

	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}