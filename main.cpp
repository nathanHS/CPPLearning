#include <iostream>

constexpr int constFunction(int arg) {
//	内部定义变量，if 语句，返回非 constexpr 为 C++14有效
	int var = 1;
	if (1 == arg)
		return var;
	return 2;
}

int function(int var) { return var; }

constexpr int *constFunction2() {
	int a = 1;
	int *b = &a;
	int *&c = b;
	return &a;
}

int main() {
	std::cout << "Hello, World!" << std::endl;
//	检测常量表达式赋值的约束
	int var = 1;
	const int const_var = var;
	const int const_constexpr = 1;

//	常量表达式必须被常量表达式初始化
//	constexpr int test_constexpr = const_var; // 错


//	可以是字面值
	constexpr int test_constexpr_1 = const_constexpr;
	constexpr int (*s)(int)  = constFunction;

//	可以是常量表达式函数的返回值
	constexpr int obj = constFunction(1);

//	常量表达式函数不做赋值语句时正常使用是不被约束的
	std::cout << constFunction(var);
	//constexpr int ret = constFunction(var);
	constFunction2();


//	常量表达式函约束
//	constexpr int ret1 = function(1);

	return 0;
}