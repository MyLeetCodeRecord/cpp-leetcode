#### 字符串(前缀)哈希法
> 题目: 
> 
> [LC2430. 对字母串可执行的最大删除数](https://leetcode.cn/problems/maximum-deletions-on-a-string/): [Oct Weekly 1](/record/Oct-Weekly-1.md)第四题, (频繁)比较子串是否相等

```CPP
str = "ABCABCDEFG"`
h[0] = 0
h[1] = "A"的hash值
h[2] = "AB"的hash值
h[3] = "ABC"的hash值
······
```

> 如何定义字符串的hash值 => 将字符串看作**P进制数**
> 
> `"ABCD" = (1234)p = (1*p^3 + 2*p^2 + 3*p^1 + 4*p^0)`
> 
> - 字符串对应的**P进制数**可能很大, 因此要`mod Q`映射回较小范围 => 可能发生冲突(但字符串哈希中不处理冲突)
> - 字母对应关系应该**从 1 开始**, 否则`A`, `AA`, `AAA`会重复映射到同一个数组

[Acwing841. 字符串哈希](https://www.acwing.com/problem/content/843/)
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010 , P=131;
char str[N];
ULL h[N], p[N];

ULL getHash(int l, int r){
    return h[r] - h[l-1]*p[r-l+1];
}
int main(){
    int n, m;
    scanf("%d%d%s", &n, &m, str+1);
    // Step1: 求所有前缀的hash值
    p[0] = 1;
    for(int i=1; i<=n; i++){
        p[i] = p[i-1]*P;    // unsigned long long 溢出就等同于取模
        h[i] = h[i-1]*P + str[i];
    }
    // Step2: hash[l:r] = h[r] - h[l-1]*p[r-l+1]
    for(int i=0; i<m; i++){
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(getHash(l1, r1) == getHash(l2, r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
```

> 目前还没做过应用题, 但是`字符串前缀哈希`相比`map`的优势应该是, 可以用差值求子串?