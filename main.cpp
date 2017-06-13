#include <iostream>

int main() {

	auto var = 1, &ref_var = var, *p = &var;
	const auto const_var = var;

	decltype(const_var) test_const = var;
//	自动匹配顶层 const
//	test_const++;

//	整型
	decltype(ref_var + 0) test_expression = 1;

//	对指针解引的类型是引用
	decltype(*p) test_p = *p;
	test_p = 10;

//	给变量加上括号就是引用类型
	decltype((var)) ref = *p;
	std::cout << "Hello, World!" << std::endl;

	return 0;
}