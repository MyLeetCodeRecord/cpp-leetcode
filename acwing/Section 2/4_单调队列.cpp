#include <cstdio>
#include <iostream>
using namespace std;

/* 单调队列
 * 1. 思考普通队列如何解决?
 *    - 维护: 加入新元素, 大于k则弹出head
 *    - 查找min/max: 直接遍历窗口内的k个值
 *    - 复杂度: 总体上 O(n*k)
 * 2. 单调队列如何优化该问题?
 *    单调队列: 保持队列内元素单调性(递增/递减)
 *    “比你年轻(新加进队列的)又比你强(更满足条件), 你就永远没有出头之日”
 *    - 维护: (连续)删除队尾大于新元素的值, 加入新元素
 *    - 查找min/max: 返回单调队列队首head
 *    - 复杂度: O(1)就可以取出min/max
 */

const int N = 1000010;
int a[N];

// 数组模拟(单调)队列: q[]中存储的是下标
int q[N];
int h = 0, t = -1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    h = 0;
    t = -1;
    // 窗口内最小
    for(int i=0; i<n; i++){
        // 检查 head 是不是滑出了窗口
        if(h<=t && i - q[h] + 1 > k)
            h++;
        // 弹出"older & worse"队尾元素
        while(h<=t && a[i] <= a[q[t]])
            t--;
        // 插入当前元素(无论如何都需要插入)
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    printf("\n");
    h = 0;
    t = -1;
    // 窗口内最大
    for(int i=0; i<n; i++){
        // 检查 head 是不是滑出了窗口
        if(h<=t && i - q[h] + 1 > k)
            h++;
        // 弹出"older & worse"队尾元素
        while(h<=t && a[i] >= a[q[t]])
            t--;
        // 插入当前元素(无论如何都需要插入)
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    return 0;
}