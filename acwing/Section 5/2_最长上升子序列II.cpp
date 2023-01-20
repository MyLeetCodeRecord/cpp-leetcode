#include <cstdio>
#include <iostream>
using namespace std;

/* 朴素做法需要O(n^2)的复杂度 => 贪心
 * [3 1 2 1 8 5 6]
 * 能够以3结尾的一定可以以1结尾, 所以3不需要存
 * 即, 长度为len=1,2,...的递增子序列, 每个len只需要存一个最小的结尾数字
 * dp[len]: 存储长度为len的最小的数字
 *          dp是一个严格递增序列, 可以用反证法证明
 * 对于nums[i], 把它接到dp[]中最大的小于它的数后面
 */

const int N = 100010;
int a[N];
int dp[N], len=0;   // dp是一个大小为len的递增数组, 在上面进行二分查找

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        // 二分查找: 找到dp[]中比a[i]小的最大位置
        int l = 0;
        int r = len;
        while(l < r){
            int mid = (l+r+1)/2;
            if(dp[mid] >= a[i]) // 严格递增 => 小于a[i]的最大位置 => 等于a[i]不是答案
                r = mid-1;
            else
                l = mid;
        }
        len = max(len, l+1);
        dp[l+1] = a[i];     // 更新l+1的最小值, 因为二分查找的就是更小值, 所以不会出现原dp[l+1]<a[i]的情况
    }
    cout<<len<<endl;
    return 0;
}