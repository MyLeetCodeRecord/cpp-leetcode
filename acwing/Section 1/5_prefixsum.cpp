#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], prefixSum[N];

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        prefixSum[i+1] = prefixSum[i] + a[i];
    }
    for(int i=0; i<m; i++){
        int l, r;
        scanf("%d %d", &l, & r);
        printf("%d\n", prefixSum[r]-prefixSum[l-1]);
    }
    return 0;
}