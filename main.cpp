#include <iostream>

using namespace std;

class a {
private:
public:
	int kk = 1;

	a() {
		cout << "默认构造函数" << endl;
	}

	a(int k) : kk(k) { cout << "一个参数的构造函数" << endl; }

	// 注释即默认的拷贝构造
	//a(const a& tem){ cout << "引用拷贝构造函数" << endl;}

};

class b {
	b(const b &) = delete;

	b &operator=(const b &) = delete;
};

int main() {


	a b;
//	直接构造
	a c(22);
	a d(c); // 但是这个我觉得也是拷贝构造

//	拷贝构造
	a g = c;
	a f = 12;
	a h = {13};
	a i = {a(232)};

	int a = 1;
	int &&gs = a + 1;
	return 0;
}