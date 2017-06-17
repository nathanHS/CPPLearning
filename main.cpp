#include <iostream>

int max() {
	int i;
	std::cin >> i;
	return i;
}

class test {
public:
	int a = 1;
	double b;
	bool c;
	int d;

	test() = default;

	test(int b) { this->b = b; }
};

class X {
	int i = 200;
	int j = 2000;
public:
//	未定义的：i 在 j 之前初始化
	X(int val) : j(val), i(j) {};
};

class J {
	int a = 2222;
public:
	J() {}
};


class Z {
	int a = 1;
	int b = 2;
	int c = 3;
public:
	Z(int s, int d) : a(s), b(d) {
		a = 1;
		b = 2;
	}

	Z() : Z(0, 0) {
		a = 2;
		b = 3;
	}

};


class aa {
	int a;
public:
	aa(int aaa) : a(aaa) {
		a = 22;
	}

	void function(aa aa1) {
		a = aa1.a;
	}
};

class bb {
	aa tete;
public:
	bb() : tete(1) {}
};

class dd {
public:
	int a;
	int b;
	int c;
};

class ee {
public:
	int function(int a = max()) { return a; }

	int a = max();

};

class gg {
public:
	static int ikk = 0;
};

int main() {
	test a;
	test b(11);
	//const test c;
	//c.a = 1;
	std::cout << a.a;

	X aa(1);
	J as;
	Z ass;

	bb ad;

	class aa ss(2);
	ss.function(2);

	class aa ssd = 2;
	//test b(2);
//	dd sscs = {1,2,3};
//	ee sssa;
//	ee ss2sa;
//	ss2sa.function();

	return 1;
}