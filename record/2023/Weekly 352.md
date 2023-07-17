#### Weekly 352

##### 1. [最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/): `双指针`
```CPP
int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int n = nums.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        if(nums[i]<=threshold && nums[i]%2==0){
            int j = i;
            int flag = 0;
            while(j<n && nums[j]<=threshold && nums[j]%2==flag){
                flag = (flag==0)?1:0;
                j++;
            }
            ans = max(ans, j-i);
            i = j-1;
        }
    }
    return ans;
}
```

##### 2. [和等于目标值的质数对](https://leetcode.cn/problems/prime-pairs-with-target-sum/): `math` `筛质数` `map`
> 质数版的两数之和
>
> 看到`n`的范围为`10^6` ➡️ [筛质数](/acwing/Section%204/Acwing%20-%20%E7%AD%9B%E8%B4%A8%E6%95%B0.md)
>
> 将质数放入`map`, 枚举小于等于`n/2`的`primes[i]`, 求`mp[n-primes[i]]`是否存在

```CPP
vector<int> primes;
vector<bool> state;
void getPrime(int n){
    state.resize(n+1);
    for(int i=2; i<=n; i++){
        if(!state[i]){
            primes.push_back(i);
            for(int j=2*i; j<=n; j+=i){
                state[j] = true;
            }
        }
    }
}
vector<vector<int>> findPrimePairs(int n) {
    getPrime(n);
    vector<vector<int>> ans;
    for(int p: primes){
        // [3,7] & [7,3]不要重复计数
        if(p > n-p)
            break;
        if(p <= n && !notPrime[n-p]){
            ans.push_back({p, n-p});
        }
    }
    return ans;
}
```

##### 3. [不间断子数组](https://leetcode.cn/problems/continuous-subarrays/): `map`
> 很重要的一点是题意转换: 「任意两数差的绝对值 <= 2」➡️「最大值-最小值<=2」
>
> 也就是`滑动窗口`内, 必须满足「最大值-最小值<=2」的条件

```CPP
unordered_map<int, int> mp;
bool check(){
    if(mp.size() > 3)
        return false;
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    for(auto &[k,_]: mp){
        mmin = min(mmin, k);
        mmax = max(mmax, k);
    }
    return mmax-mmin<=2;
}
long long continuousSubarrays(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    int l = 0, r = 0;
    while(r < n){
        mp[nums[r++]]++;
        while(check()==false){
            mp[nums[l++]]--;
            if(mp[nums[l-1]]==0)
                mp.erase(nums[l-1]);
        }
        ans += (r-l);
    }
    return ans;
}
```

##### 4. [所有子数组中不平衡数字之和](https://leetcode.cn/problems/sum-of-imbalance-numbers-of-all-subarrays/)
