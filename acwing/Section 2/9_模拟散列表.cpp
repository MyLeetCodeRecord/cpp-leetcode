#include <cstdio>
#include <iostream>
#include <cstring>  // sizeof
using namespace std;

/* 链表法 */
const int N = 100003;
int hash_table[N], e[N], nxt[N], idx;

// 找到位置, 作为head插入
void insert(int x){
    int h = (x % N + N) % N;
    e[idx] = x;
    nxt[idx] = hash_table[h];  // 新插入节点作为链表的head
    hash_table[h] = idx++;
}
// 找到位置, 遍历链表
bool find(int x){
    int h = (x % N + N) % N;
    int start = hash_table[h];
    while(start!=-1){
        if(e[start]==x)
            return true;
        start = nxt[start];
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    memset(hash_table, -1, sizeof hash_table);
    for(int i=0; i<n; i++){
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I')
            insert(x);
        else{
            if(find(x))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}