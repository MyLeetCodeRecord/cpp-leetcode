#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* 排序不等式
 * 相同顺序排序 => 最大数与最大数相乘 => 最大
 * 不能顺序排序(升序 & 逆序) => 最大值与最小数相乘 => 最小
 */

const int N = 100010;
int times[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &times[i]);
    }
    sort(time, time+n);
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (times[i] * (n-i-1));
    }
    cout<<sum<<endl;
    return 0;
}
