#### [3. CCC单词搜索](https://www.acwing.com/problem/content/5168/): `DFS`

```CPP
#include<iostream>
#include<cstring>
using namespace std;
const int N = 110;
char s[N][N];
string w;
int n, m;
int res;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int ix[4] = {-1, -1, 1, 1}, iy[4] = {-1, 1, 1, -1};
void dfs(int x, int y, int t, int f, int d, int k){
    if(t == w.size() - 1 && k < 2) {
        res ++;
        return;
    }
    // 竖直水平搜索
    if(f == -1){
        for(int i = 0; i < 4; i ++){
            int a = x + dx[i];
            int b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if(s[a][b] == w[t + 1]){
                if(t != 0 && i != d)
                    dfs(a, b, t + 1, -1, i, k + 1); //需转弯的情况
                else
                    dfs(a, b, t + 1, -1, i, k); //搜索第一次或者没转弯的情况
            }
        }
    }
    // 斜着搜索
    if(f == 1){
        for(int i = 0; i < 4; i ++){
            int a = x + ix[i];
            int b = y + iy[i];
            if(a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if(s[a][b] == w[t + 1]){
                if(t != 0 && i != d)
                    dfs(a, b, t + 1, 1, i, k + 1);
                else
                    dfs(a, b, t + 1, 1, i, k);
            }
        }
    }
}
int main(){
    cin >> w;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> s[i][j];
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++)
            if(s[i][j] == w[0]){
                dfs(i, j, 0, -1, 0, 0); // 水平/垂直
                dfs(i, j, 0, 1, 0, 0);  // 斜着
            }
    }
    cout << res << endl;
    return 0;
}
```