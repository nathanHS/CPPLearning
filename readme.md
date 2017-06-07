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
