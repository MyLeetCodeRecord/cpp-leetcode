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
int dp[N];  // 递增的, 在该数组上进行二分查找

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int len = 0;
    for(int i=0; i<n; i++){
        // 在dp[]中二分出第一个小于a[i]的数
        int l = 0;
        int r = len;
        while(l < r){
            int mid = (l+r+1)/2;
            if(dp[mid] < a[i])
                l = mid;
            else
                r = mid-1;
        }
        len = max(len, r+1);
        dp[r+1] = a[i];
    }
    cout<<len<<endl;
    return 0;
}