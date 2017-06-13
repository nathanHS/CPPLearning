#include <iostream>
#include <iterator>
#include <array>
#include <vector>

using namespace std;
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


	auto var(test);
//	两个元素
//	decltype(test) test_1 = {'1','2','3'};


	int test1[] = {1, 2, 3, 4, 5, 6};

//	int *pp = test1;
	auto begin1 = begin(test1);
	auto end1 = end(test1);

	while (begin1 != end1) {
		std::cout << *begin1 << std::endl;
		begin1++;
	}
	std::cout << "Hello, World!" << std::endl;

	return 0;
}