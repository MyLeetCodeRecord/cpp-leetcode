#### Weekly 354
> 这周感觉想问题还挺快...第四题感觉会但是却没静下心写出来...

##### 1. [特殊元素平方和](https://leetcode.cn/problems/sum-of-squares-of-special-elements/)
> 认真读题就行了, 这类题目再注意一下数据范围和溢出问题就行了

```CPP
int sumOfSquares(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for(int i=1; i<=n; i++){
        if(n % i==0){
            ans += nums[i-1]*nums[i-1];
        }
    }
    return ans;
}
```

##### 2. [数组的最大美丽值](https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/): `sort` `滑动窗口` `二分查找`
> 子序列, 说明相对位置不重要 ➡️ 可以「排序」(只是一种可行性, 倒不是子序列必须排序)
>
> 问题转化为找「连续子数组」, 满足`max-min<=2*k`条件 ➡️ `滑动窗口`

```CPP
int maximumBeauty(vector<int>& nums, int gap) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    int cnt = 0;
    for(int l=0, r=0; r<n; r++){
        // left始终是最小值, right始终是最大值
        while(l<r && nums[r]-nums[l] > 2*gap){
            l++;
        }
        ans = max(ans, r-l+1);
    }
    return ans;
}
```

> 排序 & 转化为找连续子数组后, 又可以用「二分查找」了, 让每个`nums[i]`作为最小值, 二分查找满足`nums[k]<=nums[i]+2*k`的边界
> 
> ⚠️ 注意这里应该让`nums[i]`作为一个最值, 而不是两边分别找`+k`和`-k`

```CPP
int bs_right(vector<int> &nums, int target){
    int l = 0, r = nums.size()-1;
    while(l < r){
        int mid = (l+r+1)/2;
        if(nums[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }
    return r;
}
int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        ans = max(ans, bs_right(nums, nums[i]+2*k) - i + 1);
    }
    return ans;
}
```

##### 3. [合法分割的最小下标](https://leetcode.cn/problems/minimum-index-of-a-valid-split/): `map` `math` `众数`
> 支配元素 = 众数(不考虑两个最高频元素freq相等的情况)
>
> 如果前/后两个数组「有相同支配元素」的话, 那么应该是与完整数组的支配元素是同一个 (也可能一方/两方都不存在支配元素)
>
> 证明: `f(y)*2 > size1` & `g(y)*2 > size2` => `(f(y)+g(y))*2 > n` => `y`是整体数组的支配元素
>
> 分割后的两个数组
> 
> - 第一个数组`size=i+1`, 第二个数组`size=n-i+1`
>
> - 用`cnt`记录`[0, i]`中`most`累计出现次数 ➡️ 第一个数组中`most`出现次数为`cnt`, 第二个数组中`most`出现次数为`mp[most]-cnt`
>
> 需要满足的条件
>
> - 第一个数组`cnt*2 > i+1`
> 
> - 第二个数组`(mp[most]-cnt)*2 > n-i+1`
>
> p.s. 这题的条件 (存在严格大于n/2的元素) 很适合[摩尔投票](/markdown/%E4%B8%93%E9%A2%98%20-%20%E6%91%A9%E5%B0%94%E6%8A%95%E7%A5%A8.md)

```CPP
int minimumIndex(vector<int>& nums) {
    int n = nums.size();
    int most = -1;
    unordered_map<int, int> mp;
    for(int x: nums){
        mp[x]++;
        if(mp[x]*2 >= n){
            most = x;
        }
    }
    if(mp[most]*2==n)
        return -1;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i]==most){
            cnt++;
            if(cnt*2>i+1 && (mp[most]-cnt)*2>n-i-1)
                return i;
        }
    }
    return -1;
}
```

##### 4. [最长合法子字符串的长度](https://leetcode.cn/problems/length-of-the-longest-valid-substring/): `滑动窗口`

> tips: 一个经验, 对于这种长度很小的匹配, 可以考虑把字符串hash成一个数字作为哈希值
>
> 其实这题咋做都行, 只不过直接就写了个`Trie`, 又不知道应该按**后缀**匹配, 真傻...直接`O(10*10^5)`次`mp.find(substr)`都能过
>
> 说到底, 不管是`Trie`还是`hash`或者`st.find()`, 都要考虑到是找「后缀子串」
>
> 🔗[TsReaper佬的题解](https://leetcode.cn/problems/length-of-the-longest-valid-substring/solution/shuang-zhi-zhen-by-tsreaper-rag8/)

```CPP
int longestValidSubstring(string s, vector<string>& forbidden) {
    int maxLen = 0;
    unordered_set<string> st;
    for(string &word: forbidden){
        reverse(word.begin(), word.end());
        st.insert(word);
        maxLen = max(maxLen, (int)word.size());
    }
    int n = s.size();
    int ans = 0;
    for(int l=0, r=0; r<n; r++){
        string window = "";
        for(int len=1; r-len+1>=l && len<=maxLen; len++){
            // 向前逐位查, 直到检查了[1,maxLen]所有长度的子串(这里是倒序, 所以插入st也先对word倒序)
            window.push_back(s[r-len+1]);
            if(st.find(window) != st.end()){
                l = (r - len + 1) + 1;
                break;
            }
        }
        // 通过所有末尾子串检查, 可以用来更新答案
        ans = max(ans, r - l + 1);
    }
    return ans;
}
```
