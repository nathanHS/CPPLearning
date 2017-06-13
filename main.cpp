#include <iostream>

int main() {

//	顶层 const
	const int const_var = 50;
	auto auto_var = const_var;
	auto_var++;


	int const *low_level_const = &auto_var;

	auto p = low_level_const;
//	底层 const 被自动匹配
//	(*p)++;


	std::cout << "Hello, World!" << std::endl;

	return 0;
}