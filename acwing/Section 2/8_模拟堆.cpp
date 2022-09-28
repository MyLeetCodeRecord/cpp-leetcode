#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int heap[N], ph[N], hp[N], _size=0; // ph: pointer->heap; hp: heap->pointer

void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}
void down(int k){
    int smaller = k;
    if(2*k <= _size && heap[2*k] < heap[smaller])
        smaller = 2*k;
    if(2*k+1 <= _size && heap[2*k+1] < heap[smaller])
        smaller = 2*k+1;
    if(smaller != k){
        heap_swap(k, smaller);
        down(smaller);
    }
}
void up(int k){
    if(k>1 && heap[k] < heap[k/2]){
        heap_swap(k, k/2);
        up(k/2);
    }
}
int main(){
    int n;
    int idx = 0;    // 第"k"个插入的数
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        string op;
        int k, x;
        cin>>op;
        // 插入
        if(op=="I"){
            scanf("%d", &x);
            heap[++_size] = x;
            ph[++idx] = _size;
            hp[_size] = idx;
            up(_size);
        }
        // 查询min
        else if(op=="PM"){
            printf("%d\n", heap[1]);
        }
        // 删除min
        else if(op=="DM"){
            heap_swap(1, _size);
            _size--;
            down(1);
        }
        // 删除第 k=ph[k] 个插入的元素
        else if(op=="D"){
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, _size);
            _size--;
            up(k);
            down(k);
        }
        // 修改第 k=ph[k] 个插入的元素
        else{
            scanf("%d %d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}