#### Weekly 363

##### 1. [计算 K 置位下标对应元素的和](https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/): `lowbit`

```CPP
int lowbit(int x){
    return x & (-x);
}
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        int cnt = 0;
        int x = i;
        while(x != 0){
            x -= lowbit(x);
            cnt++;
        }
        if(cnt == k)
            ans += nums[i];
    }
    return ans;
}
```

##### 2. [让所有学生保持开心的分组方法数](https://leetcode.cn/problems/happy-students/)

```CPP
int countWays(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = (nums[0]!=0);
    for(int i=0; i<nums.size()-1; i++){
        if(i+1 > nums[i] && i+1 < nums[i+1]){
            ans++;
        }
    }
    if(nums.size() > nums.back())
        ans++;
    return ans;
}
```

##### 3. [最大合金数](https://leetcode.cn/problems/maximum-number-of-alloys/): `能力检测二分`
> 题目要求「所有合金都需要由同一台机器制造」, 所以就是对每台机器, 检查最多能生产多少件产品

```CPP
bool check(long long x, vector<int>& machine, vector<int>& stock, vector<int>& cost, long long budget){
    int n = cost.size();
    for(int i=0; i<n; i++){
        long long need = -stock[i] + (long long)x * machine[i];
        need = (need > 0) ? need : 0;
        budget -= need * cost[i];
        if(budget < 0)
            return false;
    }
    return budget>=0;
}
int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& machines, vector<int>& stock, vector<int>& cost) {
    long long ans = 0;
    for(int i=0; i<k; i++){
        // 二分查找最大能生产的数量
        long long l = 0, r = 2*1e8;
        while(l < r){
            long long mid = (l+r+1)/2;
            if(check(mid, machines[i], stock, cost, budget)==false)
                r = mid-1;
            else
                l = mid;
        }
        ans = max(ans, r);
    }
    return ans;
}
```

##### 4. [完全子集的最大元素和](https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/)

```CPP
long long maximumSum(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;
    vector<long long> squares;
    for(int i=1; i<=n/i; i++){
        squares.push_back((long long)i*i);
        ans = max(ans, (long long)nums[i*i-1]);
        for(int k=1; k<=n; k++){
            long long sum = 0;
            for(int pos: squares){
                if(pos * k > n)
                    break;
                sum += nums[pos*k - 1];
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}
```