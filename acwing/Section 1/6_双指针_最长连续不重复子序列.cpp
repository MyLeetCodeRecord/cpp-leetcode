#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

/* 双指针
 * 指针 i 逐位右移, 在满足check()的条件下, 指针 j 最左能保持在什么位置
 */

const int N = 100010;
int q[N], n;

unordered_map<int, int> mp;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    int ans = 1;
    for(int i=0, j=0; i<n; i++){
        // 右边界 i 无脑加入
        mp[q[i]]++;
        // 持续收缩左边界 j
        while(j<=i && mp[q[i]] > 1){    // 这里的check(): 如果有重复元素, 一定是q[i], 所以简化为 mp[q[i]] > 1
            mp[q[j++]]--;
        }
        ans = max(ans, i-j+1);
    }
    printf("%d\n", ans);
    return 0;
}