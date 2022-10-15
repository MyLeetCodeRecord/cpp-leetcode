#include <cstdio>
#include <iostream>
using namespace std;

/* 完全背包解法: 物品为{1,2,3,···,n}的完全背包 */

const int N = 1010;
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[j] += dp[j-i];
            dp[j] %= 1000000007;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}