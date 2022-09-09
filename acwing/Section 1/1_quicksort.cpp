#include <iostream>
#include <cstdio>
using namespace std;

/* 快速排序
 * 1. 确定分界点, 一般选择`x = q[(l+r)/2]`
 * 2. 单次循环 => 交换左侧第一个遇到的"大于x"和右侧第一个遇到的“小于x”的元素
 * 3. quicksort() => 使小于x的在左边, 大于x的在右边 (下面代码等于x可以在任意一边)
 * 4. 递归左右区间, 继续快排
 */

const int N = 1e6+10;
int n;
int q[N];

void quicksort(int q[], int l, int r){
    if(l>=r)
        return ;
    int x = q[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);   // 注意这里的条件是i和j, 而不是q[i],q[j]
    }
    // i不一定等于j
    quicksort(q, l, j);         // q[j]不一定为x, 因此这个终止的j位置也要参与递归子问题
    quicksort(q, j+1, r);
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    quicksort(q, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d ", q[i]);
    return 0;
}

