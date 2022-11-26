#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int r, c;
int g[N][N];
int dp[N][N];
int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int DFS(int x, int y){
    // 如果dp[x][y]已经求过了, 则直接返回
    // Q: 不会"求到一半"吗? A: 只能走向更低位置, 所以不可能存在环路
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int d=0; d<4; d++){
        int nextX = x + directions[d][0];
        int nextY = y + directions[d][1];
        if(nextX>=0 && nextX<r && nextY>=0 &&nextY<c){
            // 只能走向更低的位置 => 保证了滑雪路径不会存在环
            if(g[x][y] > g[nextX][nextY]){
                dp[x][y] = max(dp[x][y], DFS(nextX, nextY)+1);
            }
        }
    }
    return dp[x][y];
}
int main(){
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &g[i][j]);
        }
    }
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ans = max(ans, DFS(i, j));
        }
    }
    cout<<ans<<endl;
    return 0;
}