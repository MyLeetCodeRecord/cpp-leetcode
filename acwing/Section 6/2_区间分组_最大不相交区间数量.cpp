#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/* 区间分组: 令分组内的所有区间互不相交
 * 1. 将所有区间左侧端点排序
 * 2. 从前往后处理区间, 判断当前区间能否加入现有的某个组中
 *    - 如果不存在这样的组, 则开启一个新的分组将其放入
 *    - 如果存在这样的组, 则将当前区间放入, 并更新该组的maxR
 * 可以用堆维护每个分组的maxR
 */

// 左端点排序, 直接用PII就行了
struct Interval{
    int l;
    int r;
    // 重载小于号, 用左端点排序
    bool operator< (const Interval &W) const{
        return l < W.l;
    }
};
const int N = 100010;
Interval intervals[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].l, &intervals[i].r);
    }
    sort(intervals, intervals+n);
    
    //用堆维护每个分组的maxR, maxR的数量就是分组的数量
    priority_queue<int, vector<int>, greater<int>> heap;

    for(int i=0; i<n; i++){
        auto cur = intervals[i];
        // 如果不存在这样的组, 则开启一个新的分组将其放入
        if(heap.empty() || heap.top()>=cur.l){
            heap.push(cur.r);
        }
        // 如果存在这样的组, 则将当前区间放入, 并更新该组的maxR
        else{
            heap.pop();
            heap.push(cur.r);
        }
    }
    cout<<heap.size()<<endl;
    return 0;
}
