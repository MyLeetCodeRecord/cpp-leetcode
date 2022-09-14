#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], diff[N];

/* 使用场景: 频繁对[l,r]区间内统一进行+c操作, 使每次操作O(c)操作变为O(1)完成
 * 
 * 差分数组diff[]の初始化 => 视作初始为全0数组, 在(i,j)这个1*1范围的插入操作(+c) => "差分不需要额外初始化"
 */

// 注意这里的数组a[]也是从下标1开始的, 如果不是, 注意diff[]和prefixSum[]需要错位 
void diff_operation(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    scanf("%d %d", &n, &m);
    // 求差分 => diff[]
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        // diff[i] = a[i] - a[i-1];
        diff_operation(i, i, a[i]);
    }
    // 对diff[]执行m次操作
    int l, r, c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &l, &r, &c);
        diff_operation(l, r, c);
    }
    // a[]不再是原来的作用, 只作为对diff[]求前缀和的载体
    // 求前缀和 => 覆盖回数组a[]  
    for(int i=1; i<=n; i++){
        a[i] = a[i-1] + diff[i];
        printf("%d ", a[i]);
    }
    return 0;
}