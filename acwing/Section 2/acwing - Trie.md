#### Trie

> 前缀树: 高效地存储和查找**字符串集合**的数据结构
> - [acwing-Trie](/acwing/Section%202/6_Trie.cpp)
> - [acwing-最大异或对](/acwing/Section%202/6_Trie_最大异或对.cpp)

##### 1. 数据结构
```CPP
struct TrieNode{
    TrieNode* child[26];
    // 根据需要选择
    bool isEnd;
    int time;
    string word;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
            isEnd = true;
            time = 0;
            word = "";
    }
};
```

##### 2. 操作
###### Insert
```CPP
void insert(TrieNode* trie, string word){
    TrieNode* t;    // 用于遍历的指针, 不能直接在root上操作
    for(int i=0; i<word.size(); i++){
        if(t->child[word[i]-'a'] == null)
            t->child[word[i]-'a'] = new TrieNode();
        t = t->child[word[i]-'a'];
    }
    t->isEnd = true;
    t->time ++;
}
```

###### 3. Search
> 是否存在/出现次数
```CPP
int/bool search(TrieNode* trie, string word){
    TrieNode* t;    // 用于遍历的指针, 不能直接在root上操作
    for(int i=0; i<word.size(); i++){
        if(t->child[word[i]-'a'] == null)
            return false/0;
        t = t->child[word[i]-'a'];
    }
    return t->isEnd/t->time;
}
```