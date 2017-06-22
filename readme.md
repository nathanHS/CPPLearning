
泛型算法
----------

- 泛型算法不会检查写操作的合法性。
```C++
vector<int> vec;
fill_n(vec.begin(),10,0);
```

##### back_inserter()

返回一个迭代器，这个迭代器不可移动，每次可以作为左值解引。表示向尾部（不论任何情况）添加一个元素，可以自动扩容。

```C++
	vector<int> a;

	auto inserter = back_inserter(a);

	*inserter = 1;
	a.push_back(3);
	*inserter = 2;
	
	// 结果  1 3 2
```
##### copy(begin(a1),end(a1),(it)a2)

将指定范围的 a1 拷贝给 迭代器a2, 返回 a2 尾元素之后的位置

```C++
	list<int> b = {5,22,999};
	copy(begin(a),end(a),begin(b));
```

##### unique(begin(a1),end(a1))

返回值 unique后最后一个元素的下一个迭代器：长度不变，后面的数据是什么是不确定的。

一般配合 erase 删除后面的元素。

#### 谓词

> 谓词是一个可调用的表达式，其返回结果是一个能用作条件的值。

```C++
 // isShorter(二元谓词)
bool isShorter(const string& s1, const string& s2)
{
    return s1.size() > s2.size();
}
```

##### stable_sort(words.begin(), words.end(), isShorter)

保证按照 isShorter 得出的相同的值元素在容器中的位置不变（在某个基础上，二次排序）。

#### find_if(begin,end,一元谓词)

返回第一个使得谓词非零的元素，否则返回尾迭代器。

##### lambda:由 find_if 可以理解作用

可调用对象：可以使用调用运算符（（））的对象或者表达式。

有四种，分别是 函数，函数指针，重载了调用运算符的类，lambda 表达式。

lambda 表示一个可以调用的代码单元，我们可以将其理解成一个未命名的内联函数。
它具有一个`返回类型`，一个`参数列表`，一个`函数体`。

**但是它与函数不同，他可能定义在函数内部。**

```C++
[capture list](parameter list) -> return type {function body}
```
`capture list`是一个lambda所在函数内定义的局部变量的列表。

> 我们可以省略参数列表和返回类型，但是必须永远包含捕获列表和函数体。

```C++
// 引用捕获
auto f = [&k] {return 43;};

// 隐式捕获(值)
auto g = [=,&ks] {return k + ks; //k 是局部变量的拷贝, ks 是引用};

// 隐式捕获（引用）
auto g1 = [&,=k] {return k + ks; // k 是局部变量的拷贝, ks 是引用};

// 使用 lambda 构造多元谓词，但语法结构是一元谓词
auto s = [sd](const int &a){return *sd > a;};

find_if(begin(a),end(a),s);
```

##### for_each(begin,end,\[](一个元素){这个元素怎么做})

```C++
for_each(begin(a),end(a)-10,[](const int &s){cout << s << endl;});

```

> 捕获列表里的拷贝值，是定义 lambda 时瞬间变量的值，之后变量改变，不会影响捕获列表里面的值。

> > 如果希望改变拷贝的捕获列表的元素的值，使用 mutable。
```C++

	int kks = 1;

	auto l = [=]{return kks;};

	kks++;

	auto c= l();
```

#### 标准库 bind 函数

bind 函数是一个可以解决传递参数长度问题的适配器。他接收一个可调用的对象，返回一个新的可调用的对象，返回的对象接收的参数个数小于等于原对象。

```C++
auto check6 = bind(check_size,_1,6);

// 意味着原来的 check_size 对象被是配成， check6对象，保留了原来的第一个参数（等待调用时输入），第二个参数被设置成6.

check6("23321");

auto g = bind(f,a,b,_2,c,_1);

g(_1,_2);  // 映射为 -> f(a,b,_2,c,_1);

// 如果参数内有引用则，ref(val) 或 cref(val)

```

#### 流迭代器

快速输出容器：

```C++
ostream_iterator<int> it(cout,"   ");

copy(a.begin(),a.end(),it);

cout << endl;
```


