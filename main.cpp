#include <iostream>

int main() {

	unsigned cnt = 42;
	constexpr unsigned sz = 42;

//	非常量表达式定义数组
//	int bad[cnt];
//	int a = bad[cnt+1];
//	bad[1] = 2;
//	std::cout << bad[1];

//	因为空字符长度不够
//	char test[2] = "23";

	char test[2] = {'2', '3'};


	int arr[10];

	int (*p)[10] = &arr;
	int (*&d)[10] = p;

	std::cout << "Hello, World!" << std::endl;

	return 0;
}