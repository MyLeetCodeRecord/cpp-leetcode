#include <cstdio>
using namespace std;

/* 归并排序
 * ⚠️ 快排是基于元素划分, 归并排序是基于位置划分
 * 递归: 找到mid位置, 分别对左、右两部分递归
 * 合并: 递归后可以认为左右两边分别有序, 此时逐一弹出, 合并至tmp[]数组
 *      !!! 最后要将tmp[]的[l, r]区间拷贝回原数组q[], 因为tmp在递归过程中被重复利用, 不能用做最终结果存储
 */

const int N = 100010;
int n;
int q[N], tmp[N];   // 需要一个额外空间tmp用来合并, tmp[]是分段使用的, 所以一个就够了

void mergeSort(int q[], int l, int r){
    if(l>=r)
        return ;
    // 递归 => 先让左右两部分分别有序
    int mid = (r-l)/2+l;
    mergeSort(q, l, mid);
    mergeSort(q, mid+1, r);
    // 合并
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(q[i]<=q[j])      // "=": 稳定
            tmp[idx++] = q[i++];
        else
            tmp[idx++] = q[j++];
    }
    // 下面两个条件互斥, 不用额外加if
    while(i <= mid){   // left剩余
        tmp[idx++] = q[i++];
    }
    while(j <= r){     // right剩余
        tmp[idx++] = q[j++];
    }
    // !!!将合并结果从tmp复制回原始数组q
    for(int i=l; i<=r; i++){
        q[i] = tmp[i];
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    mergeSort(q, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", q[i]);
    }
    return 0;
}