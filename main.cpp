#include <iostream>
#include "Sales_data.h"


int main() {

//	下面的写法更好
//	struct Sales_data{
//		std::string bookNo;
//		unsigned units_sold = 0;
//		double revenue = 0.0;
//	}accum, trans,*salesptr;


//	Sales_data *salesptr;
//	Sales_data accum{"abc",1,11.5};
//	Sales_data trans = {"cc",2,42};


	Sales_data data1,data2;

	double price = 0;
//	读入第一笔交易的书号，数量，单价
	std::cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;

	std::cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;



	std::cout << "Hello, World!" << std::endl;

	return 0;
}