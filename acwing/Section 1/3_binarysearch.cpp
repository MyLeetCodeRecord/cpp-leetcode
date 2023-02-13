#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
const int Q = 10010;
int arr[N];
int query[Q];
int n, q;

// 两个二分模板求左、右端点, 左侧端点求解后得到的是第一个大于等于x的数的位置, 判断是否等于x即可解决“无解”

// 左侧端点
int binary_search_left(int q[], int l, int r, int target){
    while(l<r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
// 右侧端点 (这里的+1可以用[1,1]+target=1来进行判断)
int binary_search_right(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
int main(){
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<q; i++)
        scanf("%d", &query[i]);
    for(int i=0; i<q; i++){
        int leftEnd = binary_search_left(arr, 0, n-1, query[i]);
        if(arr[leftEnd] != query[i]){
            printf("-1 -1\n");
            continue;
        }
        int rightEnd = binary_search_right(arr, 0, n-1, query[i]);
        printf("%d %d\n", leftEnd, rightEnd);
    }
    return 0;
}