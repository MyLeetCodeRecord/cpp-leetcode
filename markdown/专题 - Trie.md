#### 前缀树 Trie

###### [LC208. 实现Trie](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC208.%20%E5%AE%9E%E7%8E%B0Trie.md)

###### [LC211. 添加与搜索单词](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC211.%20%E6%B7%BB%E5%8A%A0%E4%B8%8E%E6%90%9C%E7%B4%A2%E5%8D%95%E8%AF%8D.md)

###### [LC212. 单词搜索Ⅱ](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC212.%20%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2%E2%85%A1.md)

###### [LC720. 词典中最长的单词](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC720.%20%E8%AF%8D%E5%85%B8%E9%87%8C%E6%9C%80%E9%95%BF%E7%9A%84%E5%8D%95%E8%AF%8D.md)

###### [LC421. 数组中两个数的最大异或值](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC421.%20%E6%95%B0%E7%BB%84%E4%B8%AD%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BC%82%E6%88%96%E5%80%BC.md)

###### [LC472. 连接词](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC472.%20%E8%BF%9E%E6%8E%A5%E8%AF%8D.md)

###### [LC648. 单词替换](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/markdown/LC648.%20%E5%8D%95%E8%AF%8D%E6%9B%BF%E6%8D%A2.md)

###### [LC758. 字符串中的加粗单词](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/workspace/758.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8A%A0%E7%B2%97%E5%8D%95%E8%AF%8D.cpp)
> 使用`vector<bool> bold`标记是否加粗, 最后使用`bold`恢复加粗后的字符串
> 
> 将`wordList`插入`Trie`中
> 
> 使用`search`查找是否加粗, `startWith`进行提前终止

###### [LC616. 给字符串添加加粗标签](https://github.com/MyLeetCodeRecord/cpp-leetcode/blob/master/workspace/616.%E7%BB%99%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%B7%BB%E5%8A%A0%E5%8A%A0%E7%B2%97%E6%A0%87%E7%AD%BE.cpp)
> 在`LC758`的基础上优化了`lenList`, 减少重复search, 另外注意要对`lenList`排序