#include <iostream>

using namespace std;

int kk = 2;

int &ins() { return kk; }

int main() {

	allocator<string> allo;
//	分配
	auto p = allo.allocate(3);
	auto q = p;
//	构造
	allo.construct(p++, "++");
	allo.construct(p++, "--");
	allo.construct(p++, "ss");
//	销毁
	allo.destroy(p--);
	allo.destroy(p--);
	allo.destroy(p);
//	收回
	allo.deallocate(p, 3);


	auto c = 1;
	auto ss = 0;

	unique_ptr<int> np(new int(10));
//	转移
	unique_ptr<int> next_np(np.release());

	unique_ptr<int> temp_np(new int(9));
//	重置
	next_np.reset(temp_np.release());


	while (c) {
		auto c = new int(1);
		cout << "new " << ++ss << "个" << endl;
	}
	int s = ins();
	s++;
	shared_ptr<int> sp = make_shared<int>(4);


	return 0;
}