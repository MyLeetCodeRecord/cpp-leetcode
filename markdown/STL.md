##### vector
`vi.insert(it, val)`: 在指定位置loc前插入值为val的元素, 返回指向这个元素的迭代器


##### queue
`que.insert(it, val)`: 在指定位置loc前插入值为val的元素, 返回指向这个元素的迭代器


##### map
`iterator lower_bound(const key_type &key)`: 返回一个迭代器, 指向键值 >=key 的第一个元素

`iterator upper_bound(const key_type &key)`: 返回一个迭代器, 指向键值 > key 的第一个元素


##### list 双向链表

<img src="https://img2018.cnblogs.com/blog/1169804/201903/1169804-20190310232157215-1540369555.png">

<img src="../appendix/list.png">


##### `prev(iterator)` & `next(iterator)`

> 找到上一个迭代器
> 
> [示例](https://leetcode.cn/problems/design-a-text-editor/solution/lian-biao-mo-ni-pythonjavacgo-by-endless-egw4/)