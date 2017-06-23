
动态内存
---------

#### 智能指针

-   shared_ptr
-   unique_ptr
-   weak_ptr

#### shared_ptr

> 最安全的分配和使用动态内存的方法是调用`make_shared`函数，返回一个`shared_ptr`。
```C++
	shared_ptr<int> sp = make_shared<int>(4);
```

> 如果把 shared_ptr 放在容器里，不再需要它的时候记得 erase 掉。

> **异常如果未在发生的函数内部被捕获，那么函数内部的 shared_ptr 都将被释放**

#### 删除器

当 p 被销毁的时候执行的函数，

```C++
shared_ptr<connection> p(&c, [](Connection *p){disconnect(p);});
```

#### unique_ptr

```C++
	auto c = 1;
	auto ss = 0;

	unique_ptr<int> np(new int(10));
//	转移
	unique_ptr<int> next_np(np.release());

	unique_ptr<int> temp_np(new int(9));
//	重置
	 next_np.reset(temp_np.release());
```

#### allocator 类
先分配，后构造，最后使用。

先销毁，后归还内存。
```C++
	allocator<string> allo;
//	分配
	auto p = allo.allocate(3);
	auto q = p;
//	构造
	allo.construct(p++,"++");
	allo.construct(p++,"--");
	allo.construct(p++,"ss");
//	销毁
	allo.destroy(p--);
	allo.destroy(p--);
	allo.destroy(p);
//	收回
	allo.deallocate(p,3);
```

#### 