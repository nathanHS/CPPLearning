#include <iostream>

int main() {

	std::string st{"123"};

	auto a = st.c_str();
	char b[3];
	strcpy(b, a);

	st[1] = 'c';

	std::cout << a << b << st;

	std::cout << "Hello, World!" << std::endl;

	return 0;
}