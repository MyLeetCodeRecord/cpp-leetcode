#include <cstdio>
#include <iostream>
using namespace std;

const int N = 2010;
const int MOD = 1e9+7;
int dp[N][N];

void calcCombination(){
    for(int i=0; i<N; i++){
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<=i; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];   // 选与不选
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    calcCombination(a, b);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }
    return 0;
}