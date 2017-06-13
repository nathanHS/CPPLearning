#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {

//	默认初始化
	string default_init_var = " ";

//	直接初始化
	string construct_init_var("test");
	string construct_init_var1(10, 'c');

//	拷贝初始化
	string copy_init_var = "copy";
	string copy_init_var1 = construct_init_var1;

////	不可追加，直接覆盖
//	string test;
//	cin >> test;
//	cin >> test;
//
////	角标写入
//	test[1] = '1';
//	std::cout << test << std::endl;
//
////	读一行覆盖(会保留空白符)
//	getline(cin,test);
//	std::cout << test << std::endl;


//	测试 empty 和 size
//	auto size = default_init_var.size();
//	auto empty = default_init_var.empty();
//	std::cout << size << std::endl;
//	std::cout << empty << std::endl;


//	范围 for
//	string get_chars = "s Ics !!@3ssa";
//	decltype(get_chars.size()) count = 0;
//	for (auto each : get_chars){
//		if (isalpha(each))
//			++count;
//
//	}
//	cout << "count = " << count << endl;



//	角标
//	string chars = "hellowOrld !!!";
//	for (decltype(chars.size()) index = 0; index < chars.size() && !isspace(chars[index]); ++index) {
//		chars[index] = toupper(chars[index]);
//	}
//	cout << "chars = " << chars << endl;


//
//	const string example = "123";
//	for(auto &each : example){
//		each = '1';
//	}

	std::cout << "Hello, World!" << std::endl;

	return 0;
}