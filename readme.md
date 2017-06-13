
string
=========

####初始化方式
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
####相关操作
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

####范围 for 循环
```C++
for(declaration「&」 : expression)
statement
```



