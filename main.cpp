#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main() {

	int kks = 1;


	auto l = [&] { return ++kks; };

	kks++;

	auto c = l();


	vector<int> a;

	auto inserter = back_inserter(a);

	*inserter = 2;
	a.push_back(3);
	*inserter = 2;
	auto asd = *inserter;


	vector<int> b = {2, 22, 999, 0};
	auto sd = copy(begin(a), end(a), begin(b));
	*sd = 999123;

	for_each(begin(a), end(a), [](const int &s) { cout << s << endl; });
	auto gg = [=] { return sd; };
	sort(b.begin(), b.end());

//	auto ret = unique()


	auto f = [] { return 43; };


	auto s = [sd](const int &a) { return *sd > a; };


	return 0;
}