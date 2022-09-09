#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;   // 逆序对数量 => O(N^2) => long long
int n;
int q[N], tmp[N];

// 逆序对: "合并"时, 待弹出的q[j]与q[i]及它后面的数组成逆序对, sum+=mid-i+1
long long mergeSort(int q[], int l, int r){
    if(l>=r)
        return 0;
    // 递归
    int mid = (l+r)/2;
    long long sum = mergeSort(q, l, mid) + mergeSort(q, mid+1, r);
    // 合并【计算逆序对】
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        // 逆序对统计: 遇到待弹出的q[j]
        if(q[j] < q[i]){
            tmp[idx++] = q[j++];
            sum += mid-i+1;
        }
        else{ 
            tmp[idx++] = q[i++];
        }
    }
    while(i <= mid){
        tmp[idx++] = q[i++];
    }
    while(j <= r){
        tmp[idx++] = q[j++];
    }
    // !!!将合并结果从tmp复制回原始数组q
    for(int i=l; i<=r; i++){
        q[i] = tmp[i];
    }
    return sum;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    cout<<mergeSort(q, 0, n-1)<<endl;
    return 0;
}