#### 哈希表

> Q: 和`离散化`的区别?
> 
> A: [离散化](/acwing/Section%201/acwing%20-%20%E7%A6%BB%E6%95%A3%E5%8C%96.md)是一种需要**保序**的特殊哈希

> 解决冲突的两种方式
> - 链表法
> - 开放寻址法

##### 方法一: 链表法
###### (1) 存储结构
> `hash_table`
```CPP
const int N = 100003;
int hash_table[N], e[N], nxt[N], idx;
```
> 并且需要将`hash_table[]`初始化为-1, 这样采用**头插法**也能保证链表的末尾为`-1`

```CPP
#include <cstring>
memset(hash, -1, sizeof hash);  // hash值初始化为-1
```

###### (2) 插入元素
> 先定位到`hash_table`下标, 然后用[数组模拟链表](/acwing/Section%202/1_linkedlist.cpp)的方式创建新结点, 插入到`hash_table[h]`对应链表的头部
> 
> `memset(arr, -1, sizeof arr)`: 初始化`hash_table`的所有“链表”, 使用`sizeof`需要`#include <cstring>`

```CPP
void insert(int x){
    int h = (x % N + N) % N;
    e[idx] = x;
    nxt[idx] = hash_table[h];
    hash_table[h] = idx++;
}
```

###### (3) 查找元素
> **头插法**保证了链表末尾元素是`-1`
> 
> 如果没想清楚也可以`memset(nxt, -1, sizeof nxt);`

```CPP
bool find(int x){
    int h = (x % N + N) % N;
    int start = hash_table[h];
    while(start != -1){     // -1表示链表结尾(也可以为空)
        if(e[start]==x)
            return true;
        start = nxt[start];
    }
    return false;
}
```

##### 完整实现
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>  // sizeof
using namespace std;

const int N = 100003;
int hash_table[N], e[N], nxt[N], idx;

void insert(int x){
    int h = (x % N + N) % N;
    e[idx] = x;
    nxt[idx] = hash_table[h]; // 新插入节点作为链表的head
    hash_table[h] = idx++;
}
bool find(int x){
    int h = (x % N + N) % N;
    int start = hash_table[h];
    while(start!=-1){
        if(e[start]==x)
            return true;
        start = nxt[start];
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    memset(hash_table, -1, sizeof hash_table);
    for(int i=0; i<n; i++){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I')
            insert(x);
        else{
            if(find(x))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
```