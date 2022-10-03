#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], nxt[N], idx=0;
int d[N];
// bool visited[N];    // visited可以用d[j]==-1来替换

void insert(int a, int b){
    e[idx] = b;
    nxt[idx] = h[a];
    h[a] = idx++;
}
int BFS(){
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=h[cur]; i!=-1; i=nxt[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[cur]+1;
                q.push(j);
            }
        }
    }
    return d[n];
}
int main(){
    memset(h, -1, sizeof h);
    memset(d, -1, sizeof d);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        insert(a, b);
    }
    cout<<BFS()<<endl;
    return 0;
}