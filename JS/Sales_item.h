#include<IOSTREAM>
#include<STRING>
#include"StdAfx.h"

using namespace std;

class Sales_item {
	
public:
	// ���캯��
	Sales_item():units_sold(0),revenue(0.0){}
	double avg_price() const;
	//�ж�����isbn�Ƿ���ͬ
	bool same_isbn(const Sales_item &rhs) const{ 
		//return false;
			return isbn == rhs.isbn; 
	}
	// private members as before
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};
