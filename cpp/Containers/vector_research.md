#vector_research

```c++
	/* 1. 初始化 vector 的方法 */
	vector<int> first();
	vector<int> second(2, 0);
	vector<int> third(second.begin(), second.end());
	vector<int> four(third);

	int myints[] = {16, 2, 77, 29};
	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(myints[0]) );

	/* 2. 存取元素(Element access) */
	int val1 = second[0];
	int val2 = second.front();
	int val3 = second.back();
	int val4 = second.at(0);
	int *ptr = second.data(0);

	/*	--- !!! ---
		用 operator[] 可能會 Segmentation Fault。以 at() 存取會做陣列邊界檢查，
		如果存取越界將會拋出一個例外，這是與operator[]的唯一差異。
		撰寫較嚴肅、安全性較高的程式時使用 at()。
 	 */

	/* 3. 新增或移除元素的用法(Modifiers) */
	/* 3.1 assign */
	first.assign(7, 100);	// 7 ints with 100, 
							// re-capacity || re-size and init val
	second.assign(first.begin()+1, first.end()-1);	// 5 ints

	int myints[] = {1776, 7, 4};
  	third.assign(myints, myints+3);

	/* 3.2 push_back/pop_back */
	first.push_back(1);	// it will realloc memory if necessary。
	first.pop_back(1);

	/* 3.3 insert/erase/clear */
	first.insert();	// insert the ints before iterator pointer
	first.erase(first.begin()+5); // erase the 6th elem
	first.erase(first.begin(), first.begin()+3); // erase the first 3 elem
	first.clear();	// clear all ints

	/*	--- !!! ---
		少依賴 push_back 自動配置記憶體。善用 reserve()、resize() 或 constructor 		  引數。
		STL 迭代器相關函式的設計原則，區間範圍以前閉後開範圍表示[a,b)。
	 */

	/* 4. 記憶體容量(capacity)及元素長度(size) */
	first.empty();	// return ture or false
	first.size();	// get the number of elem
	first.resize();
	first.recapacity();
	first.reserve(n);	// 預先分配 n 元素的儲存空間

	/*	--- !!! ---
		empty() 是比較 begin()、end()，Ｏ(1)。而 size() 是 Ｏ(n)。
	 */

	/* 5. 迭代(iterator) */
	first.begin();	// return the iterator of firt elem
	first.end();	// return the next iterator of last elem
	first.rbegin();	// return the iterator of last elem
	first.rend();	// return the prev iterator of first elem
```


## reference

http://mropengate.blogspot.com/2015/07/cc-vector-stl.html
