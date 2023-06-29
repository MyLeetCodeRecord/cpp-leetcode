#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/* 链表法: 这里的`hash函数`就是把`x`取余后映射到[0,100003]范围内 (100003是一个质数, 哈希性质更好)
 * 注意负数hash值的计算, hashVal = (x%N+N)%N
 */
const int N = 100003;
int h[N], e[N], nxt[N], idx=0;

void insert(int x){
    int hashVal = (x % N + N) % N;
    e[idx] = x;
    nxt[idx] = h[hashVal];
    h[hashVal] = idx++;
}
bool query(int x){
    int hashVal = (x % N + N) % N;
    for(int i=h[hashVal]; i!=-1; i=nxt[i]){
        int j = e[i];
        if(j == x)
            return true;
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    string op;
    int x;
    for(int i=0; i<n; i++){
        cin>>op>>x;
        if(op=="I")
            insert(x);
        else{
            if(query(x))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}