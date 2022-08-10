#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int element[N], pre[N], post[N];
int idx;

// 设置两个空节点表示端点: 0位置表示head, 1位置表示tail
void init(){
    post[0] = 1;
    pre[1] = 0;
    idx = 2;
}
// leftInsert(k,x)可以通过rightInsert(pre[k],x)实现
void rightInsert(int k, int x){
    element[idx] = x;
    post[idx] = post[k];
    pre[idx] = k;
    pre[post[k]] = idx;
    post[k] = idx;
    idx++;
}
void deleteNode(int k){
    post[pre[k]] = post[k];
    pre[post[k]] = pre[k];
}
int main(){
    int m;
    scanf("%d", &m);
    init();
    for(int i=0; i<m; i++){
        string op;
        int k, x;
        cin>>op;
        if(op=="L"){
            scanf("%d", &x);
            rightInsert(0, x);
        }
        else if(op=="R"){
            scanf("%d", &x);
            rightInsert(pre[1], x); // tail不能直接接新节点, 而是找到pre[tail]
        }
        else if(op=="D"){
            scanf("%d", &k);
            deleteNode(k+1);    // idx从2开始存储
        }
        else if(op=="IL"){
            scanf("%d %d", &k, &x);
            rightInsert(pre[k+1], x);
        }
        else{
            scanf("%d %d", &k, &x);
            rightInsert(k+1, x);
        }
    }
    int cur = post[0];
    while(cur != 1){
        printf("%d ", element[cur]);
        cur = post[cur];
    }
    return 0;
}