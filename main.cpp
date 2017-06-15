#include <iostream>
#include <cassert>

int a(std::string a) { std::cout << a; }

int temp2(int = 0) { return 12; }
int main() {

	int const aa = 10;
//	int a = 10;
//
//	int const *p = &a;
//	int * const pp = &a;
//
//	int *ppp = pp;


//	列表初始化
//	a({'1','2'});


	int a[10];
	assert(0);
	int *p = a;
	int (*pp)[10] = &a;

	temp2();
	std::cout << "Hello, World!" << std::endl;

	return 0;
}