#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1<<N;
int dp[M][N];
int g[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &g[i][j]);
    // 初始化 (从0出发)
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    // 状态转移
    for(int i=0; i<(1<<n); i++){    // 枚举状态
        for(int j=0; j<n; j++){     // 枚举终止节点
            // 检查终止节点是不是在状态i中存在, 否则跳过
            if(i>>j & 1){
                for(int k=0; k<n; k++){
                    // 检查 state_k 到state_j的合法性
                    if(i>>k & 1){
                        dp[i][j] = min(dp[i][j], dp[i-(1<<j)][k]+g[k][j]);
                    }
                }
            }
        }
    }
    // 终点设在(n-1), 并且结束时状态应该为所有节点都在路径中state=1111...1
    cout<<dp[(1<<n)-1][n-1]<<endl;
    return 0;
}