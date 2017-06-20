
io 流
---------
> 对于流内的数据 -> 变量的过程，之前的(空格、tab、换行符)等数据会被抛弃掉（或者指针后移），后面的（空格，tab，换行符等）会被留下来，如果下次 getline 会被读到。

> 常用条件判断来检测流是否出错
```C++
	int a = 1;
	if (cin >> a){
		cout << a;
	}
	cout << "error";
```

##### 查询流的状态

-   函数形参和返回值不能是IO流对象，必须是引用，而且形参不能是const--因为读写都会改变状态。
-   只有支持复制的元素类型可以存储在 vector 或其他容器类型里。由于流对象不能复制，因此不能存储在 vector （或其他）容器中 （即不存在存储流对象的 vector 或其他容器）。

所有的流对象，都包含一个条件状态成员，该成员由`setstate`和`clear`操作管理，该成员类型为`iostate` 。

另外有三个常量，代表三种状态，可进行位操作:badbit、failbit、eofbit。

流的状态检查操作则有：bad、fail、eof、good。如果bad、fail、eof中任一个返回true，则流处于错误状态，否则good操作返回true。

clear和setstate操作用于改变条件成员的状态。clear会重设为有效状态。setstate用于打开某个条件，用于表示某个问题的发生。setstate会保留其他状态。
```C++
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(),'\n');
// 不要用 cin.syn()
```

> 对于 fail 的 cin, 先 clear(除错) 再 ignore（清理掉缓冲区中会继续引发错误的数据） 就可以再一次正常输入了。

##### 刷新输出缓冲区

```C++
cout << flush;
cout << unitbuf; // 切换成无缓冲
cout << nounitbuf; // 切换成正常缓冲
```

缓冲区绑定：当操作输入流之前都会刷新输出流;也可以输出流绑定输出流

```C++
// 绑定
cin.tie(&cout);

// 取消绑定
auto ty = cin.tie(nullptr);
cin.tie(ty);
```

#### fstream

可以使用 `条件语句` 判断流是否是成功的。

文件模式：

-   in
-   out
-   app（追加文件）
-   ate(定位到文件末尾)
-   trunc（out 状态下默认的，截断文件）
-   binary

#### stringstream

```C++
	string test;
	while (getline(cin,test)){
		istringstream i(test);

		string s1;
		string s2;
		string s3;

		i >> s1;
		i >> s2;
		i >> s3;


		int asc = 12;
	}
```
