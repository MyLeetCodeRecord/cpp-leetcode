##### 1. linkedlist
```CPP
const int N = 100010;
int element[N], nextNode[N];
int head, idx;

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
```

##### 2. Bi-linkedlist
```CPP
const int N = 100010;
int element[N], pre[N], post[N];    // 0, 1位置分别放
int idx;

void init(){
    pre[1] = 0;
    post[0] = 1;
    idx = 2;
}
void rightInsert(int k, int x){
    element[idx] = x;
    post[idx] = post[k];
    pre[idx] = k;
    pre[post[k]] = idx;
    post[k] = idx;
    idx++;
}
void leftInsert(int k, int x){
    rightInsert(pre[k], x);
}
void deleteNode(int k){
    post[pre[k]] = post[k];
    pre[post[k]] = pre[k];
}
int main(){
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        string op;
        int k, x;
        cin>>op;
        if(op=="L"){
            scanf("%d", &x);
            rightInsert(0, x);      // head和tail始终是空节点
        }
        else if(op=="R"){
            scanf("%d", &x);
            rightInsert(pre[1], x); // tail不能直接接新节点, 而是找到pre[tail]
        }
        else if(op=="D"){
            scanf("%d", &k);
            deleteNode(k+1);        // idx从2开始存储
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
        printf("%d", cur);
        cur = post[cur];
    }
    return 0;
}
```

##### 3. 单调栈 - 左侧最近的小于cur的值
```CPP
stack<int> sk;

int main(){
    int n, cur;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        while(!sk.empty() && cur <= sk.top()){
            sk.pop();
        }
        if(!sk.empty())
            printf("%d ", sk.top());
        else
            printf("-1 ");
        sk.push(cur);
    }
    return 0;
}
```

##### 4. 单调队列 - 滑动窗口内的最小值
```CPP
const int N = 1000010;
int q[N], h, t;

void init(){
    h = 0;
    t = -1;
}
int main(){
    int n, k, cur;
    scanf("%d %d", &n, &k);
    init();
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        if(h<=t && cur-q[h]+1 > k)
            h++;
        // 持续弹出"older & worse"的队尾元素
        while(h<=t && a[cur] < a[q[t]]){
            t--;
        }
        q[++t] = cur;
        printf("%d", a[q[h]]);
    }
    return 0;
}
```

##### 4. 堆排序
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

##### 5. 模拟堆
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