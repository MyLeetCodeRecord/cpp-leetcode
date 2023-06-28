#### 前缀树 Trie

> https://oi-wiki.org/string/trie/
> 
> 有大量查询需求 & 对每一步分支选择有限制的, 比如大写字母/小写字母/0~9/0~1这种

##### 1. 简单实现
###### [LC208. 实现Trie](/markdown/LC208.%20%E5%AE%9E%E7%8E%B0Trie.md): `Trie`的原理和实现

###### [LC211. 添加与搜索单词](/markdown/LC211.%20%E6%B7%BB%E5%8A%A0%E4%B8%8E%E6%90%9C%E7%B4%A2%E5%8D%95%E8%AF%8D.md)

###### [LC212. 单词搜索II](/markdownx/LC212.%20%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2%E2%85%A1.md): `DFS`, 注意`trie`不存储字符信息, 应该用`trie->child[ch-'a']`

###### [LC421. 数组中两个数的最大异或值](/markdown/LC421.%20%E6%95%B0%E7%BB%84%E4%B8%AD%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%9A%84%E6%9C%80%E5%A4%A7%E5%BC%82%E6%88%96%E5%80%BC.md) / [Acwing143. 最大异或对](/acwing/Section%202/6_Trie_%E6%9C%80%E5%A4%A7%E5%BC%82%E6%88%96%E5%AF%B9.cpp)


##### 2. 长的依赖短的, 需要注意放入顺序
###### [LC720. 词典中最长的单词](/markdown/LC720.%20%E8%AF%8D%E5%85%B8%E9%87%8C%E6%9C%80%E9%95%BF%E7%9A%84%E5%8D%95%E8%AF%8D.md)

###### [LC472. 连接词](/markdown/LC472.%20%E8%BF%9E%E6%8E%A5%E8%AF%8D.md)

###### [LC648. 单词替换](/markdown/LC648.%20%E5%8D%95%E8%AF%8D%E6%9B%BF%E6%8D%A2.md)

###### [LC758. 字符串中的加粗单词](/workspace/758.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8A%A0%E7%B2%97%E5%8D%95%E8%AF%8D.cpp)
> 使用`vector<bool> bold`标记是否加粗, 最后使用`bold`恢复加粗后的字符串
> 
> 将`wordList`插入`Trie`中
> 
> 使用`search`查找是否加粗, `startWith`进行提前终止
>
> [方式一](/workspace/758.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8A%A0%E7%B2%97%E5%8D%95%E8%AF%8D.cpp): 两层循环匹配, 外层起点i, 内层长度len
>
> [方式二](/workspace/758.%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E5%8A%A0%E7%B2%97%E5%8D%95%E8%AF%8D-2.cpp): 只枚举起点, 直接让字符串在search里面自行匹配

###### [LC616. 给字符串添加加粗标签](/workspace/616.%E7%BB%99%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%B7%BB%E5%8A%A0%E5%8A%A0%E7%B2%97%E6%A0%87%E7%AD%BE.cpp)
> 在`LC758`的基础上优化了`lenList`, 减少重复search, 另外注意要对`lenList`排序

###### [LC676. 实现一个魔法字典](/workspace/676.%E5%AE%9E%E7%8E%B0%E4%B8%80%E4%B8%AA%E9%AD%94%E6%B3%95%E5%AD%97%E5%85%B8.cpp) - `DFS`
> `search`要用`DFS`实现, 类似**使用通配符的Trie**, 对匹配和剩余25个`child`都依情况(changed次数)进行`DFS`

###### [LC820. 压缩的单词编码](/workspace/820.%E5%8D%95%E8%AF%8D%E7%9A%84%E5%8E%8B%E7%BC%A9%E7%BC%96%E7%A0%81.cpp)
> 对单词逆序得到后缀(time->emit), 将后缀插入`Trie`中
> 
> 如果是新插入的叶节点(更长后缀)则将单词插入`Trie`中
> 
> 先放长单词(emit), 再放短单词(em), 这样才能不重复计数
