//
// Created by Joe on 2017/6/13.
//

#ifndef CPPLEARNING_SALES_DATA_H
#define CPPLEARNING_SALES_DATA_H

#include "string"
struct Sales_data {
//	Sales_data(const std::string &bookNo, unsigned int units_sold, double revenue) : bookNo(bookNo),
//	                                                                                 units_sold(units_sold),
//	                                                                                 revenue(revenue) {}

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

#endif //CPPLEARNING_SALES_DATA_H
