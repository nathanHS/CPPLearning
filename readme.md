
class
-----------
> 可以在类内定义别名。

> 在类外定义函数的时候使用 inline，类内定义会自动 inline。

> IO 类是不能拷贝的类型，所以返回 IO 类型是必须以引用的形式，而且 IO对象经常被改变，所以返回的是普通引用。

> 类内初始值必须用`=`或`{}`初始化。
##### 常量成员函数
> 常量成员函数意味着函数内的 this 被转换成指向常量对象的指针。

### 构造函数
> 当我们创建一个 const 对象时，知道构造函数完成，对象才真正意义上取得其『常量』属性。因此，构造函数可以在 const 对象构造过程中向其写值。
> class_name obj_name();这个语句不是执行默认构造函数，而是定义一个函数。
**实测：不论什么构造，初始值都会先被赋上。如果不是默认初始化，其他重载的初始化，不手动设置 bool 的成员，那么该成员会被设置为 false，如果是默认初始化，则设为 true。**

#### 合成的默认构造函数

编译器创造的默认构造函数又被叫做合成的默认构造函数，他的执行规则是：
-   如果存在类内初始值，用它们来初始化成员。
-   否则，默认初始化该成员。

> 当类包括了内置类型或者符合类型的成员（如指针、数组）时，应当赋予类内初始值，才能被默认初始化，否则结果是未定义的。

#### 现式定义默认构造函数

该方法定义的某人构造函数和`合成的默认构造函数有`相同的功能。

```C++
className() = default;
```

#### 构造函数的初始化列表
当有的编译器不支持`默认初始值`设置的时候，使用`构造函数初始化列表`来为对象成员赋予初值是一个好的方法。
```C++
class_name(int a,int b):member_a(a),member_b(b){}
```

#### 对象拷贝

> 当我们初始化变量以及以值的方式传递或返回一个对象等的时候，会发生对象的拷贝。

```C++
total = trans; 

// 等价于

total.bookNo = trans.bookNo;
total.units_sold = trans.units_sold;
total.revenue = trans.revenue;
```

#### 友元
一个类如果要允许别的类或函数访问自己的 private 数据，只需要用 friend 声明这个函数或者类，必须在类内声明，位置不限，不受控制符（public、private）的影响。
> 建议友元声明放在类的开头。这个声明不是通常意义上的声明，如果用户需要使用这个函数，必须再次用正常的方式声明一遍。
```C++
class a{

friend int add();
friend class b;
friend void b::function();

public:

}
```
#### mutable
声明为可变成员的变量可以出现在 const 函数或 const 类中，并改变它的值。


#### 根据函数是否是 const 重载，根据对象是否是 const 来判断。
> const 对象不能用缺省默认构造函数（不写构造函数，或者 class_name() = default;）来构造。
```C++
class_name func const(A &b);
class_name func(A &b);
```

#### 友元再探

> 每个类负责控制自己的友元类或者友元函数类

#### 类的作用域

类外部需要说明类型名。

```C++
// 类外部
Screen::pos ht = 1;

// 类内部(类中的函数内部，这就意味着**外部定义的函数的返回值不在类的内部**)
void Screen::function(pos ht){}

// 类外定义的返回值 出现在 类名之前所以他需要加以标注 说明他属于这个类

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen&)
```

#### 成员初始化列表中初始化的顺序
> 最好让需要初始化的初始值的顺序和声明时候的顺序一致，如果可能的话避免用一些成员去初始化另一些成员。
```C++
// 初始化的顺序是按照成员的顺序来的**（但是看起来好像有的编译器会自动纠正这个错误）**
class X{
    int i;
    int j;
public:
    // 未定义的：i 在 j 之前初始化
    X(int val):j(val),i(j){};
};
```
#### 委托构造函数
```C++
class Z{
	int a = 1;
	int b = 2;
	int c = 3;
public:
	Z(int s,int d):a(s),b(d){
		a = 1;
		b = 2;
	}
	Z():Z(0,0){
		a = 2;
		b = 3;
	}

};

// 2\3\3(c = 3,是和 a(s),b(d)一起最早初始化的，之后执行 a = 1，b = 2再之后执行 a = 2，b = 3)
Z a;
```
#### 函数参数的隐式类类型转换（只允许一步）
```C++
class aa{
	int a;
public:
	aa(int aaa):a(aaa){
		a = 22;
	}
	void function(aa aa1){
		a = aa1.a;
	}
};

// 2 隐式转换成 aa(2)
aa ss(2);
ss.function(2);
```
#### explicit

##### 抑制构造函数定义的隐式转换
> explicit 只允许出现在类内声明处
```C++
class aa{
	int a;
public:
	explicit aa(int aaa):a(aaa){
		a = 22;
	}
	void function(aa aa1){
		a = aa1.a;
	}
};

// 2 无法隐式转换成 aa(2)
aa ss(2);
ss.function(2);
```
##### explicit 函数只能适用于直接初始化
```C++
class aa{
	int a;
public:
	explicit aa(int aaa):a(aaa){
		a = 22;
	}
	void function(aa aa1){
		a = aa1.a;
	}
};

// 2 无法隐式转换成 aa(2)后拷贝
aa ss = 2;
```

#### 聚合类
-   所有都是 public
-   没有任何构造函数
-   没有初始值
-   没有基类
-   没有虚函数

**那么他可以直接用花括号初始化。**
```C++
class dd{
public:
	int a;
	int b;
	int c;
};

dd sscs = {1,2,3};
```

#### 字面值常量类

-   每个成员都是字面值类型。
-   至少有一个 constexpr 函数。
-   如果有成员初始值，必须是一个常量表达式。
-   使用默认的析构函数。

生成的对象是 constexpr 的。

#### 静态成员

> 外部定义静态函数的时候，不要重复添加 static 关键字。

> 静态成员可以作为实参。

> **静态成员只能在类外初始化。**