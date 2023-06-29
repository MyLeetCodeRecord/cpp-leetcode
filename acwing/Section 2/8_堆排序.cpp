#include <cstdio>
#include <iostream>
using namespace std;

/* 小顶堆排序
 * Step 1: 建堆
 *   x 不要逐个插入 => O(nlogn)
 *   o 调整前n/2个位置
 * Step 2: m次删除堆顶元素
 */
const int N = 100010;
int heap[N], _size=0;

void down(int k){
    int smaller = k;
    if(2*k <= _size && heap[2*k] < heap[smaller])
        smaller = 2*k;
    if(2*k+1 <= _size && heap[2*k+1] < heap[smaller])
        smaller = 2*k+1;
    if(smaller != k){
        swap(heap[k], heap[smaller]);
        down(smaller);  // k和smaller都是下标, 所以这里的smaller指向的其实是移动后的输入元素所在位置, 不再具有smaller语义
    }
}
void up(int k){
    if(k>1 && heap[k]<heap[k/2]){
        swap(heap[k], heap[k/2]);
        up(k/2);
    }
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &heap[i]);
    }
    _size = n;
    // 不考虑最后一层, 需要down({上面O(n/2)个元素}), 整体复杂度O(n)
    for(int i=n/2; i>0; i--){
        down(i);
    }
    for(int i=0; i<m; i++){
        // 获取并删除堆顶元素
        printf("%d ", heap[1]);
        heap[1] = heap[_size--];
        down(1);
    }
    return 0;
}