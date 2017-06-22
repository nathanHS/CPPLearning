#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {

	set<int> se;
	se.insert(1);
	se.insert(2);

	vector<int> k;
	k.assign(se.begin(), se.end());

	map<string, int> word_count;

	++word_count["hello"];
	--word_count["ss"];
	for_each(begin(word_count), end(word_count),
	         [](pair<string, int> s) { cout << s.first << "  " << s.second << endl; });
	return 0;
}