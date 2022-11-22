#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;
int g[N][N];
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;

int BFS(){
    queue<PII> q;
    q.push({0, 0});
    g[0][0] = -1;
    int layer = 0;
    while(!q.empty()){
        layer++;
        int _size = q.size();
        for(int i=0; i<_size; i++){
            PII cur = q.front();
            q.pop();
            for(int d=0; d<4; d++){
                int nextX = cur.first + direction[d][0];
                int nextY = cur.second + direction[d][1];
                if(nextX==n-1 && nextY==m-1){
                    return layer;
                }
                if(nextX>=0 && nextX<n && nextY>=0 && nextY<m && g[nextX][nextY]==0){
                    q.push({nextX, nextY});
                    g[nextX][nextY] = -1;
                }
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &g[i][j]);
        }
    }
    cout<<BFS()<<endl;
    return 0;
}