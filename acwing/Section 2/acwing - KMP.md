#### KMP

##### 1. 基本思想
> ![KMP-思想](/appendix/acwing-KMP.png)
> 
> Notes: i的下标从1开始, j的下标从0开始, i和j错开一位

##### 2. next数组的含义
> 找到最长的后缀, 满足`p[1:j] = p[i-j+1:i]`
> 
> `next[j]`记录的是最长匹配后缀的开始位置
> 
> ![KMP-next数组](/appendix/acwing-KMP-next.png)
>
> `next[]`数组的求解
> - 模板串从下标1开始记录, 
> - next[i]从2开始计算, 因为next[1]=0即可(无路可退)
> 

```CPP
#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;
char p[N], s[M];    // 下标从1开始
int ne[N];

int main(){
    int n, m;
    cin>>n>>(p+1);    // 字符串p, s下标从1开始存储
    cin>>m>>(s+1);
    // next数组 
    for(int i=2, j=0; i<=n; i++){
        while(j!=0 && p[i] != p[j+1])
            j = ne[j];
        if(p[i] == p[j+1])
            j++;
        ne[i] = j;
    }
    // 匹配过程
    for(int i=1, j=0; i<=m; i++){
        // 不匹配则退一步
        while(j!=0 && s[i] != p[j+1])
            j = ne[j];
        // 匹配则i++, j++
        if(s[i] == p[j+1])
            j++;
        // 匹配成功
        if(j == n){
            printf("%d ", i-n);
            j = ne[j];    // 匹配成功也要退一步
        }
    }
    return 0;
}
```