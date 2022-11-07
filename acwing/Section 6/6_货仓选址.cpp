#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* 中位数贪心 */

const int N = 1000010;
int pos[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &pos[i]);
    }
    sort(pos, pos+n);
    int base = pos[n/2];
    cout<<base<<endl;
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(base-pos[i]);
    }
    cout<<ans<<endl;
    return 0;
}