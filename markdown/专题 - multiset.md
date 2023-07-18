#### `multiset`

> `multiset`和`set`的差别在于`multiset`允许键值重复, `set`和`multiset`的底层实现是**红黑树** (因此也是平衡二叉树)。
> 
> `multiset`打破了`set`的互异性, 可以存放多个相同的元素
>
> ![multiset](/appendix/multiset.png)
> 
> - `二分`: `set`和`multiset`都可以应用`lower_bound()`, 寻找第一个大于等于某个值的迭代器, 找不到就返回`st.end()`
> 
> - `insert(val)`: 允许集合内存在相同元素
> 
> - `erase`:
>   - `erase(val)`: 值删除, 允许删除该值的所有元素
>   - `erase(iterator)`: 迭代器删除, 只删除迭代器对应的一个元素 (这里可以搭配find使用: `st.erase(st.find(val))`)
>
> - `count(val)`: 返回元素值为`val`的个数
>
> - `begin()` & `rbegin()` & `end()` & `rend()`


##### 1. 窗口最大最小值
> 用`multiset`维护窗口内所有元素, 并通过`O(1)`时间获取最大/最小值、插入/删除元素
>
> - 最小值: `st.begin()`
> 
> - 最大值: `*st.rbegin()`
>
> - 删除某个值的一个元素: `st.erase(st.find(val))`

[LC1438. 绝对差不超过限制的最长连续子数组](/workspace/1438.%E7%BB%9D%E5%AF%B9%E5%B7%AE%E4%B8%8D%E8%B6%85%E8%BF%87%E9%99%90%E5%88%B6%E7%9A%84%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84.cpp)

[LC2762. 不间断子数组](/record/2023/Weekly%20352.md)