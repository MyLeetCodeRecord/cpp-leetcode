#### Biweekly 96

> 除夕补卡

##### 1. [最小公共值](https://leetcode.cn/problems/minimum-common-value/): `双指针`

```CPP
int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int i=0, j=0;
    while(i<m && j<n){
        if(nums1[i]==nums2[j])
            return nums1[i];
        else if(nums1[i]<nums2[j])
            i++;
        else
            j++;
    }
    return -1;
}
```

##### 2. [使数组中所有元素相等的最小操作数II](https://leetcode.cn/problems/minimum-operations-to-make-array-equal-ii/): `找规律`

> 这类问题可以找到一个`不变量`, 也就是`+k`和`-k`成对出现, 元素和不变
>
> 每次变换的单位必须是`k`的倍数, 并且增加和减少的次数应该相等, 总操作次数=(增加k次数 ➕ 减少k次数) / 2
> 
> 也可以在一个数组上进行计算, 由于目标是将`nums1 -> nums2`, 可以转化为一个数组`diff = nums1 - nums2`, 问题变成在`diff`数组上是否和为`0`, 并且每一项为`k`的倍数

```CPP
long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    long long cnt = 0;
    long long ans = 0;
    for(int i=0; i<n; i++){
        if(k==0){
            if(nums1[i] != nums2[i])
                return -1;
            else
                continue;
        }
        if((nums1[i]-nums2[i]) % k != 0)
            return -1;
        cnt += (nums1[i]-nums2[i]) / k;
        ans += abs(nums1[i]-nums2[i]) / k;
    }
    return (cnt==0 && ans%2==0) ? ans/2 : -1;
}
```


##### 3. [最大子序列的分数](https://leetcode.cn/problems/maximum-subsequence-score/): `子序列` `sort` `priority_queue`

> 思路: 
> 
> - `10^5`说明回溯一定不行, `子序列`说明可以排序再处理, 再结合`min`, 确定应该按`nums2`排序 ➡️ `sort`
>
> - 按`nums2`排序后, 可以从大到小枚举`min`值, `min(...)`这一部分是确定的, 只需要找前面的`pairs`中`nums1`尽可能大的`k-1`个, 就可以得到固定最小值下, `(nums1[i0]+...+nums1[ik - 1]) * min(nums2[i0],...,nums2[ik - 1])`的最大值 ➡️ `priority_queue`

```CPP
typedef pair<int, int> PII;
long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<PII> vi;
    for(int i=0; i<n; i++){
        vi.push_back({nums1[i], nums2[i]});
    }
    sort(vi.begin(), vi.end(), [&](const PII &l, const PII &r){
        return l.second > r.second;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;  // 维护大小为k的堆中的sum
    for(int i=0; i<k; i++){
        pq.push(vi[i].first);
        sum += vi[i].first;
    }
    long long ans = sum * vi[k-1].second;
    for(int i=k; i<n; i++){
        pq.push(vi[i].first);
        sum += vi[i].first;
        sum -= pq.top();    // 堆顶是后面一定不会用到的nums1较小的元素
        pq.pop();
        ans = max(ans, sum * vi[i].second);
    }
    return ans;
}
```


##### 4. []()
