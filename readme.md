
关联容器
---------

map:键值对，set:集合。

#### map

```C++
	map<string,int> word_count;

	++word_count["hello"];
	--word_count["ss"];
	for_each(begin(word_count),end(word_count),[](pair<string,int> s){cout << s.first << "  " << s.second << endl;});
	
    // hello  1
    // ss  -1
```

#### set

```C++
	set<int> se;
	se.insert(1);
	se.insert(2);
```

##### 关联容器添加元素即排序

```C++
bool func(Sales_data a,Sales_data b){return a > b;}

multiset<Sales_data,decltype(func)*> exmaple(func);


```