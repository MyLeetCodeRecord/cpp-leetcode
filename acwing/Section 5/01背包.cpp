#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int weight[N], value[N];
int dp[N];

int main(){
    int n, V;
    scanf("%d %d", &n, &V);
    for(int i=0; i<n; i++){
        scanf("%d %d", &weight[i], &value[i]);
    }
    // 遍历物品
    for(int i=0; i<n; i++){
        // 遍历背包容量(滚动数组, 倒序)
        for(int j=V; j>=weight[i]; j--){
            dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[V]<<endl;
    return 0;
}