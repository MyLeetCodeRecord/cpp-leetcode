#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 12, M = 1<<N;
long long dp[N][M];  // 行数=N; 列数=状态数M=2^N
bool st[N];          // 记录状态合法性

int main(){
    int n, m;
    while(cin>>n>>m, n||m){
        // 预处理, 检查所有状态合法性, 即有没有连续奇数个0
        for(int i=0; i<(1<<n); i++){
            st[i] = true;
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i>>j & 1){       // 当前位为1, 说明可能有一段连续0结束了
                    if(cnt & 1){    // 如果前一段是奇数个1, 标记当前状态为非法, st[i]=false
                        st[i] = false;
                        break;
                    }
                }
                else{
                    cnt++;
                }
            }
            // 最后可能以0结尾, 没办法用1分割出这段连续0, 所以单独检查一下尾部连续0
            if(cnt & 1)
                st[i] = false;
        }
        // 状态初始化
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        // 状态转移
        for(int i=1; i<=m; i++){        // 一共N列, 转移要发生N次
            for(int j=0; j<(1<<n); j++){
                for(int k=0; k<(1<<n); k++){
                    if((j&k)==0 && st[j|k]==true)   // 检查状态 k 转移到状态 j 是否合法
                        dp[i][j] += dp[i-1][k];     // 合法则 + dp[i-1][k]
                }
            }
        }
        cout<<dp[m][0]<<endl;   // 最后多加一层 & 0状态, 表示没有前一列延伸出来的横条
    }
    return 0;
}