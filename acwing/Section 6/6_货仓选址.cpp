#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* 中位数贪心 */

const int N = 100010;
int stores[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &stores[i]);
    }
    sort(stores, stores+n);
    long long ans = 0;
    int base = stores[n/2];
    for(int i=0; i<n; i++){
        ans += abs(stores[i]-base);
    }
    cout<<ans<<endl;
    return 0;
}