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
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int d=0; d<4; d++){
        int nextX = x + directions[d][0];
        int nextY = y + directions[d][1];
        if(nextX>=0 && nextX<r && nextY>=0 &&nextY<c){
            if(g[x][y] > g[nextX][nextY]){
                dp[x][y] = max(dp[x][y], DFS(nextX, nextY)+1);
            }
        }
    }
    return dp[x][y];
}
int main(){
    scanf("%d %d", &r, &c);
    int maxH = -1;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &g[i][j]);
            maxH = max(maxH, g[i][j]);
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