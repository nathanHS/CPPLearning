
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
