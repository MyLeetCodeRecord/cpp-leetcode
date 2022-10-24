#### Weekly 4

##### [2. 最大公因数等于K的子数组数目](https://leetcode.cn/problems/number-of-subarrays-with-gcd-equal-to-k/)
> 一直不敢写暴力...结果灵神写了个最基本暴力就过了...

```python
def subarrayGCD(self, nums: List[int], k: int) -> int:
    ans = 0
    for i in range(len(nums)):
        # 这里可以加个nums[i]%k==0的判断, 但不加竟然也能过啊...
        g = 0
        for j in range(i, len(nums)):
            g = gcd(g, nums[j])
            if g == k:
                ans += 1
    return ans
```

> 想了一个小时最后才想了个`dp`...

```CPP
class Solution {
public:
    int gcd(int n, int m){
        if(n % m == 0){
            return m;
        }
        return gcd(m, n%m);
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[0][i] = nums[i];
            if(nums[i]==k){
                ans++;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=0; i+j<n; j++){
                dp[i][j] = gcd(dp[i-1][j], dp[i-1][j+1]);
                if(dp[i][j]==k){
                    ans++;
                }
                // cout<<dp[i][j]<<"\t";
            }
            // cout<<endl;
        }
        return ans;
    }
};
```

##### [3. 使数组相等的最小开销](https://leetcode.cn/problems/minimum-cost-to-make-array-equal/)

> 周赛的时候完全不会呢...

##### 中位数贪心
> 首先不考虑代价`cost[i]`, 答案应该就是中位数(如果偶数个, 则在最中间两个数区间内即可)
> 
> 原理就是最短距离是`(n/2)`组直接线段
> 
> 如果考虑`cost[i]`, 将数字重复`cost[i]`次即可
> 
> 注意`总开销ans`,`中位数mid`和`找中位数的计数下标idx`都要用`long long`

> 相关题目: [LC462. 最小操作次数使数组元素相等II](/workspace/462.%E6%9C%80%E5%B0%91%E7%A7%BB%E5%8A%A8%E6%AC%A1%E6%95%B0%E4%BD%BF%E6%95%B0%E7%BB%84%E5%85%83%E7%B4%A0%E7%9B%B8%E7%AD%89-ii.cpp), [五月](/record/2022-05.md)的一道每日一题呢...

```CPP
long long minCost(vector<int>& nums, vector<int>& cost) {
    int n = nums.size();
    // Step1: 排序
    vector<vector<int>> pairs;   // 为了排序对齐
    for(int i=0; i<n; i++){
        pairs.push_back({nums[i], cost[i]});
    }
    sort(pairs.begin(), pairs.end());
    // Step2: 计算"总个数", 中位数贪心
    long long totalCost = 0;
    for(int i=0; i<n; i++){
        totalCost += cost[i];
    }
    long long mid = (totalCost+1)/2;
    long long idx = 0;
    for(int i=0; i<n; i++){
        idx += pairs[i][1];
        if(idx >= mid){     // 找到中位数
            long long ans = 0;
            for(int j=0; j<n; j++){     // 计算中位数处的开销作为ans返回
                ans += (long long)abs(pairs[j][0]-pairs[i][0]) * pairs[j][1];
            }
            return ans;
        }
    }
    return 0;
}
```

##### 第四题以后再说吧 累了