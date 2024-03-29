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
        // 不匹配则退🤺一步
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