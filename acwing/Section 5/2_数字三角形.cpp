#include <cstdio>
#include <iostream>
using namespace std;

const int N = 510;
int triangle[N][N];
int dp[N][N];       // 只依赖上一层, 但[j]的计算依赖[j]和[j+1], 不管j从前向后or从后向前构造, 都不能压缩为一维

int main(){
    int n;
    scanf("%d", &n);
    // 倒着存比较好, 这样和dp计算同向
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n-i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    for(int j=0; j<n; j++){
        dp[0][j] = triangle[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + triangle[i][j];
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}