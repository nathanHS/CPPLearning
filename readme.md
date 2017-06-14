
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

