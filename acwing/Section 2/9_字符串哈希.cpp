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
        p[i] = p[i-1]*P;    // unsigned long long 溢出就等同于取模(对多少取模不重要, 反正也不做冲突处理)
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