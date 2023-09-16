/* 单调队列 (用deque实现)
 * p.s. 单调队列不是不能操作队尾...
 * 1. 思考普通队列如何解决?
 *    - 维护: 加入新元素, 间隔大于k则弹出head
 *    - 查找min/max: 直接遍历窗口内的k个值
 *    - 复杂度: 总体上 O(n*k)
 * 2. 单调队列如何优化该问题?
 *    单调队列: 保持队列内元素单调性(递增/递减), 注意存储的是下标
 *    举例杀手 => “比你年轻(新加进队列的)又比你强(更满足条件), 你就永远没有出头之日”
 *    - 维护: (连续)删除「队尾」大于新元素的值, 加入新元素
 *    - 查找min/max: 返回单调队列队首head (因为head并没有被过程淘汰
 *    - 复杂度: O(1)就可以取出min/max
 */

#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1000010;
int a[N];
int n, k;

void getSmall(){
    int deque[N];
    int h = 0, t = -1;
    for(int i=0; i<n; i++){
        if(i - deque[h] >= k)
            h++;
        while(t>=h && a[i] <= a[deque[t]])
            t--;
        deque[++t] = i;
        if(i >= k-1)
            printf("%d ", a[deque[h]]);
    }
}
void getBig(){
    int deque[N];
    int h = 0, t = -1;
    for(int i=0; i<n; i++){
        if(i - deque[h] >= k)
            h++;
        while(t>=h && a[i] >= a[deque[t]])
            t--;
        deque[++t] = i;
        if(i >= k-1)
            printf("%d ", a[deque[h]]);
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    getSmall();
    printf("\n");
    getBig();
    return 0;
}

/* ———————————————————————————————————————————————————— */

#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];

// 数组模拟(单调)队列: q[]中存储的是下标, 因为要维护"固定尺寸窗口"
// head存储的是当前窗口内最大元素的下标, 所以要将队尾比arr[i]更小的删除掉
int q[N];
int h = 0, t = -1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    // 初始化单调队列
    h = 0, t = -1;
    // 窗口内最小
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        // 检查 head 是不是滑出了窗口 (每遍历一个新元素就会检查一次, 所以if就够了)
        if(h<=t && i - q[h] + 1 > k)
            h++;
        // 删除队尾"older & worse"元素  =>  单调队列也会操作队尾
        while(h<=t && a[i] <= a[q[t]])
            t--;
        // 插入当前元素(无论如何都需要插入)
        q[++t] = i;
        // head即为当前窗口答案(的下标)
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    printf("\n");
    // 清空队列
    h = 0;
    t = -1;
    // 窗口内最大
    for(int i=0; i<n; i++){
        if(h<=t && i - q[h] + 1 > k)
            h++;
        while(h<=t && a[i] >= a[q[t]])
            t--;
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    return 0;
}
