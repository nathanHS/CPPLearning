#include <iostream>
#include <vector>

using namespace std;
int main() {

	string a = "123";
	string b = "345";

	vector<int> ss(2, 1);
	int gg = 23;
	ss.emplace_back(gg);


	ss.emplace(ss.begin(), 22121);
	++gg;
	auto &c = b;

	swap(a, b);

	int k = 1;

	auto g = ss.size();

	return 0;
}