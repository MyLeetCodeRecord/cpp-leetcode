#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
// head - 头节点下标
// element[i] - 节点i元素值
// nextNode[i] - 指向节点i的下一个节点的下标
int head, element[N], nextNode[N];
// 数组空间指针, 指向下一个可以分配的位置
int idx;

void init(){
    head = -1;
    idx = 0;
}
void insertHead(int x){
    element[idx] = x;
    nextNode[idx] = head;
    head = idx++;
}
void insertNode(int k, int x){
    element[idx] = x;
    nextNode[idx] = nextNode[k-1];
    nextNode[k-1] = idx++;
}
void deleteNode(int k){
    if(k==0){
        head = nextNode[head];
        return ;
    }
    nextNode[k-1] = nextNode[nextNode[k-1]];
}
void printLinkedList(){
    int cur = head;
    while(cur!=-1){
        printf("%d ", element[cur]);
        cur = nextNode[cur];
    }
}
int main(){
    int m;
    scanf("%d", &m);
    init();
    for(int i=0; i<m; i++){
        char op;
        cin>>op;
        int k, x;
        if(op == 'H'){
            scanf("%d", &x);
            insertHead(x);
        }
        else if(op == 'D'){
            scanf("%d", &k);
            deleteNode(k);
        }
        else{
            scanf("%d %d", &k, &x);
            insertNode(k, x);
        }
    }
    printLinkedList();
    return 0;
}