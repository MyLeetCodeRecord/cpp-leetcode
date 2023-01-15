#### Weekly 328 - 补卡

##### 1. [数组元素和与数字和的绝对差](https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/): `十进制数`

```CPP
int differenceOfSum(vector<int>& nums) {
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<nums.size(); i++){
        sum1 += nums[i];
        int x = nums[i];
        while(x != 0){
            sum2 += (x%10);
            x /= 10;
        }
    }
    return abs(sum1-sum2);
}
```

##### 2. [子矩阵元素加1](https://leetcode.cn/problems/increment-submatrices-by-one/): `二维差分`  `二维前缀和`

> ⚠️注意`diff[][]`没有偏移, `prefixSum[][]`有偏移
> 
> 边界改了半个小时...下次先理清思路

```CPP
void diff_operation(vector<vector<int>>& diff, int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
    for(vector<int> &q: queries){
        diff_operation(diff, q[0], q[1], q[2], q[3], 1);
    }
    // 对diff[][]求前缀和得到a[][]
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j] = diff[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    // 消除前缀和矩阵的错位
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = a[i+1][j+1];
        }
    }
    return ans;
}
```

##### 3. [统计好子数组的数目](https://leetcode.cn/contest/weekly-contest-328/problems/count-the-number-of-good-subarrays/): `滑动窗口`

> 复习一下[滑动窗口](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%8F%8C%E6%8C%87%E9%92%88.md)
>
> 需要维护的性质是`pairs`的数目, 可以发现对于一个出现`cnt`次的元素, 相等下标对的数量`#pairs = C(cnt, 2) = cnt*(cnt-1)/2`
>
> 于是扩大右边界或者收缩左边界就变成了更新两次`#pairs`, 其实可以进一步发现, 两者之差刚好是`cnt`(没看出来就用`C(cnt, 2)`更新两次)

```CPP
long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    long long pairs = 0;
    long long ans = 0;
    int l=0, r=0;
    // pairs数量的更新原则: 对于一个数字x, #pairs = C(cnt, 2) = cnt*(cnt-1)/2
    while(r < n){
        int tmp = ++mp[nums[r++]];
        pairs -= (tmp-1)*(tmp-2)/2;
        pairs += tmp*(tmp-1)/2;
        while(pairs>=k){
            int tmp2 = --mp[nums[l++]];
            pairs -= (tmp2+1)*(tmp2)/2;
            pairs += tmp2*(tmp2-1)/2;
        }
        ans += l;
    }
    return ans;
}
```