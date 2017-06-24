
拷贝控制
------------

#### 拷贝构造函数

拷贝构造函数的一个参数是自身类型的引用，如果有其他参数，其他参数都有默认值。

```C++
#include <iostream>

using namespace std;

class a {
private:
	int kk = 1;
public:
	a() {
		cout << "默认构造函数" << endl;
	}

	a(int k) : kk(k) { cout << "一个参数的构造函数" << endl; }

	// 注释即默认的拷贝构造
	//a(const a& tem){ cout << "拷贝构造函数" << endl;}
};

int main() {

	a b;
	a c(22);
	a d(c);
	a g = c;
	a f = 12;
	a h = {13};
	a i = {a(232)};
	return 0;
}
```

> 如果一个类自定义析构函数，几乎可以肯定它也要自定义拷贝赋值运算符和拷贝构造函数！！
>> 否则，析构时 delete 的掉相同的内容。

#### 阻止拷贝

```C++
class b{
	b(const b&) = delete;
	b& operator=(const b&) = delete;
	
// 或者用下面的方法
private:
    b(const b&);

};
```
> 推荐使用 delete 的方式阻止拷贝。

#### 行为像值的类、行为像指针的类

#### 右值引用

> 如果一个类定义了自己的拷贝构造函数，编译器就不会为他合成移动构造函数和移动赋值运算符。 

[参考资料1][1]

[1]:http://blog.csdn.net/yapian8/article/details/42341307

[参考资料2][2]

[2]:https://www.zhihu.com/question/22111546

```C++
int b = 9;
int a&& = b + 1;

// 左值转右值的方法

int a&& = std::move(b);
```
