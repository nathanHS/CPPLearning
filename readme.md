# CPPLearning

I will share my cpp learning experience in this project.

And __each branch__ of it will be a full test with the readme doc.

const
-------



- 常量必须被初始化。
- 可以在**运行时**给常量赋初值。
- 如果想要使用**全局**的const：
    1.  不论声明还是定义都需要在 const 前加入 `extern` 。
    2.  全部`cpp文件`中只能有一处初始化。
    3.  其他文件需要声明后使用，一般把声明放在`.h文件`中。
- 通过下面语句可以创建一个**只读的** const 变量。
``` C++ 
 const int var = somthing;
``` 
- high-level const 不可以改变自身的指向
``` C++ 
 int *const var = &somthing;
``` 
- low-level const 不可以改变指向的值
``` C++ 
 const int *var = &somthing;
``` 
constexpr
----------


- 什么是常量表达式？
    -   字面值
    -   用常量表达式初始化的 const 对象 
    -   常量表达式函数
        -   用 `constexpr`修饰
        -   定义时约束
            -   返回值必须是字面值
        -   作为赋值对象付给某个常量构成新的常量表达式时约束：
            -   C++11
                -   函数体必须只包含一个return语句
                -   函数提可以包含其他的语句，但是这些语句不能在运行期起作用
                -   函数可以不返回常量，但是在调用的时候实参必须传入常量表达式
            -   C++14
                -   无 C++11 那些
        -   正常情况下使用无约束
```C++

// constexpr 的功能: 约束返回值必须为字面值；当这个函数作为另一个 constexpr 的赋值者时，约束参数必须为 constexpr
constexpr int something(int var){return var;}

int var = 1;
// 是合法的
something(var)；
// 是非法的
constexpr int ret = something(var)；


```
[参考链接][1]
      
[1]: http://www.cnblogs.com/boydfd/p/5041316.html "Effect C++ 翻译"


auto
--------

-   不带自动匹配 `顶层const` 修饰 
-   自动匹配 `底层 const` 修饰
-   不自动匹配引用
-   **当使用`&`表示引用时，自动包含本体的 const 属性（如果有的话）**

decltype
--------

作用：通过某个表达式判断其类型，用于声明定义（不计算表达时的值）。

-   decltype 自动匹配`引用`、`顶层 const` 
-   自动匹配 `底层 const` 修饰
-   不自动匹配引用
-   **对指针解引的类型是该类型的引用**
    ```C++
    auto var = 1, &ref_var = var, *p = &var;
    
	//对指针解引的类型是引用
	decltype(*p) test_p = *p;
	test_p = 10;
    ```
-   **给变量加上括号就是引用类型**
    ```C++
    auto var = 1, &ref_var = var, *p = &var;
    decltype((var)) ref = *p;
    ```
-   赋值语句是引用类型


struct
--------

-   会默认初始化（各成员被初始化成0或者空串）
-   使用花括号初始化
    -   花括号初始化内置类型时，如果有数据丢失风险会报错，结构体不会
-   也可以使用等号后在使用花括号，不过这个多了赋值过程
-   **每个头文件都加上判断重定义宏**

namespace
-------
-   直接使用
```C++
std::string var_string = "something";
```
-   单独声明使用一个命名空间变量
```C++
using std::string;
```
-   声明使用完整的命名空间
```C++
using namespace::std;
```

string
--------

#### 初始化方式
-   默认初始化
```C++
//	默认初始化
string default_init_var;
```
-   拷贝初始化
```C++
//	拷贝初始化
	string copy_init_var = "copy";
	string copy_init_var1 = construct_init_var1;
```
-   直接初始化
```C++
//	直接初始化
	string construct_init_var("test");
	string construct_init_var1(10,'c');
```
#### 相关操作
-   重载 `>>`，`<<`:覆盖式赋值,输出
```C++
	string test;
// 从 cin 中读一个字符串给test，遇到空白符为止，最后一个非空白符后面的空白符全部都会留在 cin 中
	cin >> test;
	cout << test << std::endl;
```
-   `getline(is,a)`:从 is 中读一行赋值给 a,**实测不会截断前后方的空白符**。
-   `s.empty()`: 判断字符串是否是空串
-   `s.size()`: 字符串有多少个字符
-   `+`：连接
    -   **使用两个字面值是无法使用加号连接的**
-   `=`：覆盖
-   `==`：如果字符完全一样就相等

#### 范围 for 循环
```C++
for(declaration「&」 : expression)
statement
```

vector
-------

vector 是一个类模板，在 C++ 中，我们可以将模板看成是编译器生成类或函数时写的一份说明。

**vector 是模板而不是类型，vector<int>是类型。**

#### 初始化

-   vector<T> v1 : 空的 vector 执行默认初始化
-   vector<T> v2(v1) : v2 中含有 v1 中所有元素的副本
-   vector<T> v2 = v1 : 同上
-   vector<T> v3(n, val) : 包含 n 个值为 val 的元素
-   vector<T> v4(n) : n个重复地执行了值初始化的对象
-   vector<T> v5{a,b,c} : 初始化各个元素
-   vector<T> v5 = {a,b,c} : 同上

#### 注意

-   如果要在循环里添加或减少 vector 的元素，则不能使用范围 for 循环。
-   下标运算符只能作用于已经拥有的元素

迭代器
-------

> 我们理解一个类型是迭代器当且仅当它支持一套操作，这套操作支持我们能访问容器的元素或者从某个元素引动到另一个元素。
>> 因为模板类都重写了 `==`和`!=`运算符，所以多使用`!=`代替`>`运算符。

迭代器例子：

```C++
	vector<int> v4{1,2,3};

	for(auto it = v4.begin(); it != v4.end(); ++it)
	{
		(*it)++;
	}

```
迭代器操作：
-   *iter
-   iter->item
-   ++iter


数组
---------

-   定义数组的长度必须是常量表达式
    -   但是实测，如果使用非常量表达式定义数组，数组不会出现异常，**但无法写入**。 
-   使用字**面值常量初始化字**符数组时会在最后一个位置添加一个空字符，使用**列表初始化则不会。**
-   指针的数组
```C++
int *p[10];
```
-   不存在引用的数组
-   指向数组的指针
```C++
int arr[10];
int (*k)[10] = &arr; // 指向长度为10的整型数组的指针。
```
-   数组的引用
```C++
int (&p)[10] = arr;
```
-   指向数组的指针的引用(***和变量名在同括号内，就是指针**)
```C++
int (&*rp)[10] = k; // *&和&*同义
```
-   `auto var(数组名)`或 `auto var(&数组名[0])`定义一个指针，指向数组首地址。
-   `decltype(数组名)`表示就是数组类型，并且长度和所限定的数组名相同。

-   推荐使用标准库函数构造迭代器进行遍历
    - begin(数组名),必须要是数组名,甚至连指针都不行   
    - end(数组名)


C字符串
-------
- 使用指针 + 字面值方式初始化的字符串，是不可写的


运算符
-------
-   如果非必须情况，不适用递增递减的后置版本
-   int k = {1.2}; 这种语句叫做窄化转换，使用花括号则会出现编译错误
-   条件运算符嵌套不要超过两层
-   `sizeof`:返回运算对象所占的字节数
    -   且指针不需要有效，对指针解引取 `sizeof` 并不会真的获取该数据。
    -   返回值是一个常量表达式

#### 常见的不易被察觉的隐式转换

-   数组转换成指针
```C++
int ia[10];
int *ip = ia;
```
-   指针转换
    -   `0 `或 `nullptr` 可以转换成任意指针类型
    -   任意**指向非常量**的指针可以转换成`void *`
    -   **指向任意对象**的指针可以转换成`const void *`
#### C++式强制转换
格式：`cast-name<type>(expression)`
cast-name:
-   static_cast:
只要不包含底层 const，都可以使用 static_cast。**把较大算数类型赋值给一个较小的算术类型时，非常有用**。

对于找回指针内的值也很有作用。
```C++
void *p = &d;
double *dp = static_cast<double *>(p);
```
    
    
    
-   dynamic_cast:
-   const_cast:
取消`底层 const` 属性，但是通过取消后的变量写值是未定义行为。
```C++
const char *cp;
char *q = const_cast<char *>(cp);
```
-   reinterpret_cast:避免使用，在位模式上重新解释对象

语句
--------
#### 块
块也是语句，块的内部是零个或多个语句，块不以分号结尾。

#### 使用花括号控制条件路径
如何使得 `else` 表达成并不是紧跟的 `if` 的 `else`？
```C++
if(a){
    if(b)
    ...
}
else
    doSomething();
```

> 一般不要省略 `case` 分支最后的 `break` 语句。如果没写，最好加上注释。

> 最好在每个 case 加上花括号，从而保证不会出现跨标签使用未初始化变量的问题。

#### 异常

异常使用 `what()`成员函数获取`c式字符串`表示的异常内容。


函数
--------

> 函数参数尽量使用引用避免拷贝过程，如果不需要改变就是用`const type& name`。

#### 使用引用形参返回额外数据
当函数需要返回多个数据是，可以将参数设为引用，在函数体内修改引用。
```C++
// occurs   :   出现的次数
// ret      :   第一次出现的索引值 
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i;)
    {
        if(s[i] == c)
        {
            if(ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}
```

#### const 形参和实参

-   当形参有 const 时，可以用非 const 的变量作为实参传入，但是在函数内他会变成 const 的。
-    **不能用 `底层 const` 和 `const引用` 初始化非 const 对象。**

#### 数组操作使用标准库规范
传递 `begin` 和 `end` 参数。
```C++
void print(const int* beg, const int* end)
{
    while(beg != end){
        cout << *beg++ << endl;
    }
}
```
#### 可变形参函数

如果实参类型相同，使用一个名为`initializer_list`的标准库模板类型。

如果实参类型不同，使用`可变参数模板`。

或者`省略符`，不过一般只用于与C 函数交互的接口程序。

-   initializer_list(实参以包裹花括号的形式传入)

    和 vector 一样，有以下操作：

    -   initializer_list<T> lst;
    -   initializer_list<T> lst{a,b,c...};
    -   initializer_list<T> lst2(lst);
    -   initializer_list<T> lst2 = lst;
    -   lst.size();
    -   lst.begin();
    -   lst.end();
    
```C++
void err_msg(initializer_list<string> il)
{
    for(auto beg=il.begin(); beg != il.end(); ++beg){
        cout << *beg << " ";
    }
    cout << endl;
}

err_msg({"134","23123"});
```

#### 返回值

> 不要返回局部对象的引用或指针。

引用返回左值：
```C++
char &get_val(string &str, string::size_type ix){
    return str[ix];
}

get_val(s,0) = 'A';
```
### 声明一个返回数组*指针*的函数

`Type (* function(parameter_list))[dimension]`

例如：`int (*func(int i))[10];`

1.  func(int i)     : 表示调用函数需要一个 int 实参

2.  (*func(int i))  : 表示函数的返回值可以被解引用

3.  (*func(int i))[10]  : 表示函数的返回值解引用后是一个大小为10的数组

4.  int (*func(int i))[10]  : 表示数组是 int 类型的


#### 使用尾置返回值

```C++
auto function(int i) -> int(*)[10]
```

#### 使用 decltype
```C++
int odd[] = {1,2,3};

decltype(odd) *function(int i);
```

#### 重载

> 如果同一作用域内的几个函数名字相同但是形参列表不同，我们称之为重载函数。

**底层 const 和 const 引用可以重载（相比于无 const 属于不同类型）。**

```C++
Record lookup(Account&);
Record lookup(const Account&);
```

**最好把默认参数放在后面，这样就可以直接省略不写，否则起不到默认的作用**
```C++
int temp(int a, int b = 0);
temp(1);


int temp2(int b=0,int a);
temp(2,2);
```
#### inline
> 函数体短小且使用频繁的函数建议使用内联。

> **把`内联函数`和 `constexpr 函数`放在头文件内。**


#### 调试帮助

`assert(expression)`：assert(0) 则会输出信息并终止程序的执行

通常使用 assert(应该的逻辑)

#### 函数指针

> 作为形参，函数和函数指针是等价的。
```C++
void a(int (*p)());

void a(int p());
```
三种方式定义函数指针：

```C++
int (*f(int))(int *,int);
 // 1. f 是个函数，因为有形参int
 // 2. f 返回指针因为有 *
 // 返回的指针指向的函数类型 外层括号 和 int。
```

```C++
auto f(int) -> int(*)(int *,int);
```

```C++
int func(int*,int);

decltype(func) *f(int);
```

