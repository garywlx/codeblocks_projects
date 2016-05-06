#include "stdafx.h"
#include "Sales_item.h"

//  求销售平均价格
double Sales_item::avg_price() const{

	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}