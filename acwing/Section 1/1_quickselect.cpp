#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int n, k;
int q[N];

int quickselect(int q[], int k, int l, int r){
    if(l == r)
        return q[l];
    int x = q[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = j - l + 1;
    // 选一边递归
    if(leftCnt >= k)
        quickselect(q, k, l, j);
    else
        return quickselect(q, k-leftCnt, j+1, r);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    cout<<quickselect(q, k, 0, n-1)<<endl;
    return 0;
}