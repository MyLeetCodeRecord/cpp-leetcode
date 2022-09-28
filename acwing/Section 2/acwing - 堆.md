#### 堆

> - 插入一个数
> - 求集合中的最小值
> - 删除最小值
> - 删除任意一个元素
> - 修改任意一个元素

##### 0. 定义
###### (1) 数据结构
> 完全二叉树 => 数组`heap[]`存储, 从**下标 `1` 开始**
> 
> 对于节点`x`, `leftchild`对应的数组下标为`2 * x`, `rightchild`对应的数组下标为`2 * x + 1`
> 
> 对于需要索引`第k个插入元素`的情况, 需要`hp[]`&`ph[]`记录双向映射关系, `idx`是`k`的指针

```CPP
int heap[N], hp[N], ph[N];
int _size = 0, idx = 0;
```

###### (2) 基础操作
**交换堆中元素 heap_swap**
> 如果题目中不要求索引(`修改/删除第k个元素`), 直接`swap(heap[a], heap[b])`即可
> 
> 否则, 要建立双向的索引 `hp[]`, `ph[]`, 并自定义如下的`heap_swap(a, b)`操作
> 
> ![acwing-模拟堆](/appendix/acwing-%E6%A8%A1%E6%8B%9F%E5%A0%86.png)

```CPP
// ph: pointer->heap; hp: heap->pointer
int heap[N], ph[N], hp[N];

void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}
```

**向下调整 Down**
> 以小顶堆为例, 当前元素与`leftchild`和`rightchild`比较, 如果存在更小的, 与**最小的**交换, 即选择三个节点中最小的作为`father`
```CPP
void down(int k){
    int smaller = k;
    if(2*k <= _size && heap[2*k] < heap[smaller])
        smaller = 2*k;
    if(2*k+1 <= _size && heap[2*k+1] < heap[smaller])
        smaller = 2*k+1;
    if(smaller != k){
        swap(heap[k], heap[smaller]);
        down(smaller);
    }
}
```
**向上调整 Up**
> 如果当前节点比`father`更小, 则进行交换
```CPP
void up(int k){
    if(k>1 && heap[k]<heap[k/2]){
        swap(heap[k], heap[k/2]);
        up(k/2);
    }
}
```

##### 1. 插入一个数
```CPP
// 不使用ph[] & hp[]
heap[++_size] = x;
up(_size);

// 使用ph[] & hp[], 建立"第idx个加入"和"在heap中的实际位置(随着插入删除发生变化)"的映射
heap[++_size] = x;
ph[++idx] = _size;
hp[_size] = idx;
up(_size);
```

##### 2. 求堆中最小值
```CPP
heap[1]
```

##### 3. 删除最小值
```CPP
// 最后一个元素覆盖到堆顶
heap_swap(1, _size);
_size--;
down(1);
```

##### 4. 删除任意一个元素 (删除第k个元素)
```CPP
// 第k个插入元素当前在heap中的实际位置
k = ph[k];
// 最后一个元素覆盖heap[k]
heap_swap(k, _size);
_size--;
// 无脑up & down [只会执行一个]
up(k);
down(k);
```

##### 5. 修改任意一个元素
```CPP
// 第k个插入元素当前在heap中的实际位置
k = ph[k];
// 修改元素
heap[k] = x;
// 无脑up & down [只会执行一个]
up(k);
down(k);
```

##### [Acwing839. 模拟堆](https://www.acwing.com/problem/content/841/)完整实现
```CPP
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
```