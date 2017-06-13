#include <iostream>
#include "vector"

using std::vector;

int main() {

//	默认构造
	vector<int> v1;
	//v1.push_back(60);

	vector<int> v2(v1);
	vector<int> v3 = v1;

	vector<int> v4{1, 2, 3};

	//v1[100] = 1;

	for (auto it = v4.begin(); it != v4.end(); ++it) {
		(*it)++;
	}



	std::cout << "Hello, World!" << std::endl;

	return 0;
}