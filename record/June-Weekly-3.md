#### Weekly 3


##### [1. 兼具大小写的最好英文字母](https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/)


##### [2. 个位数字为K的整数之和](https://leetcode.cn/problems/sum-of-numbers-with-units-digit-k/)
> 使用次数没有限制, 想到用完全背包, 重量和价值都是个位数字为K的数字

```CPP
// 可以重复包含同一个整数 => 完全背包
int minimumNumbers(int num, int k) {
    // dp[j]: 由kSet中元素构成的和为j的集合的最小长度
    vector<int> dp(num+1, INT_MAX);
    vector<int> kSet;
    int tmp = k;
    while(tmp <= num){
        kSet.push_back(tmp);
        tmp+=10;
    }
    dp[0] = 0;
    for(int i=0; i<kSet.size(); i++){
        for(int j=kSet[i]; j<=num; j++){
            if(dp[j-kSet[i]]<INT_MAX)
                dp[j] = min(dp[j], dp[j-kSet[i]]+1);
        }
    }
    return (dp[num]==INT_MAX) ? -1 : dp[num];
}
```

##### [3. 小于等于K的最长二进制子序列](https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/)
> `滑动窗口`, 难度在于移动窗口时如何有效率地修改val
> 
> - 右移: `val * 2 + (s[right++]-'0')`
> - 左移: 移除最高位(共K位) `val - 2^K`

```CPP
int trans(int n){
    int tmp = n;
    int k = 0;
    while(n / 2!=0){
        n /= 2;
        k++;
    }
    int highest = 1;
    while(k!=0){
        highest *= 2;
        k--;
    }
    return tmp-highest;
}
int longestSubsequence(string s, int k) {
    int ans = 1;
    // 滑动窗口
    int left = 0;
    int right = 0;
    int val = 0;
    while(right < s.size()){
        val = val * 2 + (s[right++]-'0');
        while(val > k && left < right){
            left++;
            val = trans(val);
        }
        ans = max(ans, right-left);
    }
    return ans;
}
```