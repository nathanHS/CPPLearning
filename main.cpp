#include <iostream>
#include <fstream>
#include <sstream>

class s {
};

using namespace std;
int main() {

	string test;
	while (getline(cin, test)) {
		istringstream i(test);

		string s1;
		string s2;
		string s3;

		i >> s1;
		i >> s2;
		i >> s3;


		int asc = 12;
	}


	string string1s;
	string string23;

	cin >> string1s;
	char st[20];
	char k;
	cin.get(k);
	cin.getline(st, 5);
	ifstream input_file("sss.f");
	s as;


	int a = 5;
	if (cin >> a) {
		cout << a;
	}
	if (cin.bad()) {
		cout << "error";
	}
	if (cin.fail()) {
		cout << "fail\n";
		if (cin >> a) {
			cout << a;
		} else {
			cout << "continue fail\n";
			//cin.clear();
			cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
			if (cin.good()) {
				cout << "已经设置成 good 了\n";
			}
			//auto c = cin.sync();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//auto ss = cin.rdbuf()->in_avail();
			//cin.ignore(cin.rdbuf()->in_avail()+1);
			//cin.ignore(10000,'\n');
			auto d = cin.good();

			int dds = 1;
			auto s = &dds;
			*s = 2;


			auto ty = cin.tie(nullptr);
			cin.tie(ty);
			cin >> a;
		}
	}
	return 0;
}