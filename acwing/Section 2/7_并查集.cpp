#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int father[N];

void init_ufs(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
    }
}
int find_ufs(int u){
    if(u != father[u])
        father[u] = find_ufs(father[u]);  // 路径压缩
    return father[u];
}
void union_ufs(int u, int v){
    int fu = find_ufs(u);
    int fv = find_ufs(v);
    father[fv] = fu;
}
bool inSame(int u, int v){
    int fu = find_ufs(u);
    int fv = find_ufs(v);
    return (fu==fv);
}
int main(){
    int n, m;
    cin>>n>>m;
    init_ufs(n);
    string op;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>op;
        scanf("%d %d", &a, &b);
        if(op=="M"){
            union_ufs(a, b);            
        }
        else if(op=="Q"){
            if(inSame(a, b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}