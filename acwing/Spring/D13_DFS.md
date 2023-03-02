### DFS

#### 1. [Acwing3502. 不同路径数](https://www.acwing.com/problem/content/3505/)

> 数据范围太小了, 直接`DFS`就行了, 注意「加入路径」写在`DFS()`的哪里

```CPP
#include <cstdio>
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 10;
int g[N][N];
int n, m, k;

unordered_set<int> st;

void DFS(int i, int j, int cur, int &ans){
    if(i<0 || i>=n || j<0 || j>=m)
        return ;
    ans = ans*10 + g[i][j];
    if(cur==k){
        st.insert(ans);
    }
    else{
        DFS(i+1, j, cur+1, ans);
        DFS(i, j+1, cur+1, ans);
        DFS(i-1, j, cur+1, ans);
        DFS(i, j-1, cur+1, ans);
    }
    ans /= 10;
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            DFS(i, j, 0, ans);
    cout<<st.size()<<endl;
    return 0;
}
```


#### 2. [Acwing842. 排列数字](/acwing/Section%203/1_%E6%8E%92%E5%88%97%E6%95%B0%E5%AD%97.cpp)


#### 3. [Acwing843. N皇后](/acwing/Section%203/1_N%E7%9A%87%E5%90%8E.cpp)