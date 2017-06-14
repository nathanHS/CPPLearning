#include <iostream>

int main() {

	int ia[10];
	int *ip = ia;


	std::string st{"123"};

	auto a = st.c_str();
	char b[3]; // 这里是3，4就没有问题，3就会导致 a 的内容编程乱码
	strcpy(b, a);
	auto c = 0x9e0 - 0x800;
	std::cout << "Hello, World!" << std::endl;

//	const char *cp = "23";
//	char *q = const_cast<char *>(cp);
//	*q = '1';


	int p[] = {1, 2, 3};
	int *ppp = p;
	auto cc = *ppp;
	cc++;
	char *pp = reinterpret_cast<char *>(ppp);

	auto ccc = *pp;
	ccc++;
	return 0;

}