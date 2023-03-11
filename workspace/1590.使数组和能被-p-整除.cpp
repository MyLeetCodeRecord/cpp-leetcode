/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
int minSubarray(vector<int>& nums, int p) {
    int n = nums.size();
    vector<int> s(n+1, 0);
    for(int i=0; i<n; i++){
        s[i+1] = (s[i] + nums[i]) % p;    // 只有余数是有意义的
    }
    // 下面这个特判可以用「mp[s[i]]=i」这条语句前置来代替
    // if(s[n] % p == 0)
    //     return 0;
    unordered_map<int, int> mp; // 记录前缀和值的最后一次出现位置
    int ans = n;
    for(int i=0; i<=n; i++){
        mp[s[i]] = i;           // 这句话前置, 可以顺便考虑不删除子数组的情况
        int left = (s[i] - s[n] + p) % p; // left: 使剩余元素和可以整除p的前缀和值, mp[left]为这个前缀和值出现的最后位置
        if(mp.find(left) != mp.end()){
            ans = min(ans, i-mp[left]);
        }
    }
    return (ans<n) ? ans : -1;
}
// @lc code=end

