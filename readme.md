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
    
