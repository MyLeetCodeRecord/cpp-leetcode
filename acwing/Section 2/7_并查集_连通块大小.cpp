#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int father[N];
int sizeList[N];

void init_ufs(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
        sizeList[i] = 1;
    }
}
int find_ufs(int u){
    if(u != father[u])
        father[u] = find_ufs(father[u]);
    return father[u];
}
void union_ufs(int u, int v){
    int fu = find_ufs(u);
    int fv = find_ufs(v);
    // !!! 不同根节点才需要合并, 否则会导致sizeList被错误更新
    if(fu != fv){
        father[fv] = fu;
        sizeList[fu] += sizeList[fv];
    }
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
        if(op=="C"){
            scanf("%d %d", &a, &b);
            union_ufs(a, b);            
        }
        else if(op=="Q1"){
            scanf("%d %d", &a, &b);
            if(inSame(a, b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if(op=="Q2"){
            scanf("%d", &a);
            printf("%d\n", sizeList[find_ufs(a)]);
        }
    }
    return 0;
}