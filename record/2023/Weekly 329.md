#### Weekly 326

##### 1. [交替数字和](https://leetcode.cn/problems/alternating-digit-sum/): `十进制数` ➡️ `string`

```CPP
int alternateDigitSum(int n) {
    string str = to_string(n);
    int res = 0;
    int ss = 1;
    for(int i=0; i<str.size(); i++){
        res += ss*(str[i]-'0');
        ss *= -1;
    }
    return res;
}
```


##### 2. [根据第K场考试的分数排序](https://leetcode.cn/problems/sort-the-students-by-their-kth-score/): `sort`

> 自定义`sort`规则, 如果写成`static bool cmp(...)`的话, 没办法使用非静态变量
>
> 参数列表要➕`const`➕`&`

```CPP
vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    int n = score.size();
    sort(score.begin(), score.end(), [&](const vector<int> &l, const vector<int> &r){
        return l[k] > r[k];
    });
    return score;
}
```


##### 3. [执行逐位运算使字符串相等](https://leetcode.cn/problems/apply-bitwise-operations-to-make-strings-equal/): `位运算` `分类讨论` ➡️ `找规律`

> 周赛的思考过程: 考虑`<i, j>`的四种情况
> 
> ![LC2546](/appendix/LC2546.png)
>
> 只考虑是否存在方案, 所以逐位置进行`0->1`和`1->0`的转换即可, 也就是保证每次转换前`s`中都「另外有至少一个`1`」(不包括当前位置的`1`)
> 
> ⚠️ `WA`了一次, 因为应该「先令`1`增多」, 才「更可能」找到合法方案

```CPP
bool makeStringsEqual(string s, string target) {
    int n = s.size();
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        cnt1 += (s[i]=='1');
    }
    for(int i=0; i<n; i++){
        if(s[i]=='0' && target[i]=='1'){
            if(cnt1 >= 1)
                cnt1++;
            else
                return false;
        }
    }
    for(int i=0; i<n; i++){
        if(s[i]=='1' && target[i]=='0'){
            if(cnt1 > 1)
                cnt1--;
            else
                return false;
        }
    }
    return true;
}
```


##### 4. [拆分数组的最小代价](https://leetcode.cn/problems/minimum-cost-to-split-an-array/): `dp` `双指针`

> 整体的dp思路很容易想到: `dp[i] = min(dp[i], dp[j]+trimVal(j, i)+k)`, `dp[x]`下标从`1`开始
> 
> 难点在于压缩「求所有trimVal(j, i)」这部分的计算复杂度
>
> - ❌ 如果对于每个区间`(j, i)`都遍历一遍保存到`cnt`(用`map`或者`vector`)中, 再统计出现次数为`1`的个数计算`trimVal`, 这样整体复杂度为`O(n^3)=O(1e9)` ➡️ 超时
>
> - ✅ 从左到右枚举右端点`i`, 对于每个右端点`i`, 向左扩大左端点`j`, 由于区间只会向左扩张不会缩小, 所以计数的`cnt[]`数组可以继续使用, 只需要对新加入的左端点`j`进行判断即可
>   - `cnt[nums[j]] == 1` => 忽略
>   - `cnt[nums[j]] == 2` => `trimVal += 2`
>   - `cnt[nums[j]] > 2` => `trimVal += 1`

```CPP
int minCost(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> dp(n+1, 1e18);
    dp[0] = 0;
    // 枚举右端点, 然后左移左端点, 可以不进行重复计算 => 一趟的复杂度为O(n)
    for(int i=1; i<=n; i++){
        vector<int> cnt(n+1, 0);   // 起到map的作用
        int trimVal = 0;
        // 外层 i 枚举的是右端点, 目的是不需要每次对 j～i 整体计算cnt[]
        // 因此左端点 j 应该是从最贴近 i 的位置出发向右扩大区间
        // 并对对新加入区间的元素计数即可, 不需要遍历整个 j～i 重求一遍cnt[]
        for(int j=i-1; j>=0; j--){
            cnt[nums[j]]++;
            // 计算trimVal的策略: 忽略cnt[x]=1, 对cnt[x]=2计数两次, 对于cnt[x]>2加一
            // 由于遍历顺序是不涉及收缩区间的, 所以不用考虑cnt[x]的发生
            if(cnt[nums[j]]==2)
                trimVal += 2;
            else if(cnt[nums[j]]>2)
                trimVal += 1;
            dp[i] = min(dp[i], dp[j] + trimVal + k);
        }
    }
    return dp[n];
}
```