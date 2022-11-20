##### 1. 堆排序
```CPP
const int N = 100010;
int heap[N], _size = 0;

// 缩水版的heap_swap, 不需要索引"第k个插入堆"的元素
void heap_swap(int a, int b){
    swap(heap[a], heap[b]);
}
void down(int k){
    int smaller = k;
    if(2*k <= _size && heap[2*k] < heap[smaller])
        smaller = 2*k;
    if(2*k+1 <= _size && heap[2*k+1] < heap[smaller])
        smaller = 2*k+1;
    if(smaller != k){
        heap_swap(smaller, k);
        down(smaller);
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    _size = n;
    for(int i=1; i<=n; i++)
        scanf("%d", &heap[i]);
    for(int i=n/2; i>0; i--){
        down(i);
    }
    for(int i=0; i<m; i++){
        printf("%d ", heap[1]);
        heap[1] = heap[_size--];
        down(1);
    }
    return 0;
}
```

##### 2. 模拟堆
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int heap[N], ph[N], hp[N], _size = 0, idx=0;

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
        heap_swap(smaller, k);
        down(smaller);
    }
}
void up(int k){
    if(k>1 && heap[k/2] > heap[k]){
        heap_swap(k/2, k);
        up(k/2);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        string op;
        int k, x;
        cin>>op;
        if(op=="I"){
            scanf("%d", &x);
            heap[++_size] = x;
            ph[++idx] = _size;
            hp[_size] = idx;
            up(_size);
        }
        else if(op=="PM"){
            printf("%d\n", heap[1]);
        }
        else if(op=="DM"){
            heap_swap(1, _size);    // 由于涉及ph和hp, 所有位置变动的操作都必须用heap_swap()
            _size--;
            down(1);
        }
        else if(op=="D"){
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, _size);
            _size--;
            up(k);
            down(k);
        }
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
```