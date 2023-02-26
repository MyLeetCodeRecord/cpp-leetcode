#### Weekly 334

> 写的好差的一周...

##### 1. [左右元素和的差值](https://leetcode.cn/problems/left-and-right-sum-differences/): `前缀和`

```CPP
vector<int> leftRigthDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for(int i=1; i<n; i++){
        left[i] = left[i-1] + nums[i-1];
    }
    for(int i=n-2; i>=0; i--){
        right[i] = right[i+1] + nums[i+1];
    }
    for(int i=0; i<n; i++){
        left[i] = abs(left[i]-right[i]);
    }
    return left;
}
```


##### 2. [找出字符串的可整除数组](https://leetcode.cn/problems/find-the-divisibility-array-of-a-string/): `大整数运算` `大整数除法`
> 周赛第二题, 与大整数除法的运算顺序一致, 可以省略除法结果的维护
> 
> 要检查每移动一位, 当前的余数`r`是否为`0`, 如果为`0`说明当前前缀可以整除`b`

```CPP
vector<int> divisibilityArray(string word, int b) {
    int n = word.size();
    vector<int> ans(n, 0);
    long long r = 0;
    for(int i=0; i<n; i++){
        r = r * 10 + (word[i]-'0');
        r %= b;
        if(r == 0)
            ans[i] = 1;
    }
    return ans;
}
```


##### 3. [求出最多标记下标](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/)
> ❌ 周赛时感觉像是贪心, 就先排序然后从大到小遍历`nums[i]`, 找到未标记元素中最大的满足`nums[j]*2<=nums[i]`的`j`进行标记, 但其实得到的并不是最优解

###### `二分`(➕`贪心`➕`双指针`)
>
> - 单调性: 如果`nums[i]`不能匹配, 比`nums[i]`大的后序数组一定不能匹配
>
> - `check(k)`: 如果能标记`mid`对, 那么最小的`k`个数和最大的`k`个数字一定会被选中

```CPP
bool check(vector<int>& nums, int k){
    int n = nums.size();
    for(int i=0; i<nums.size(); i++){
        int j = n-k-1+i;
        if(nums[i]*2 > nums[j])
            return false;
    }
    return true;
}
int maxNumOfMarkedIndices(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 右端点模板
    int l = 0, r = n/2;
    while(l < r){
        int mid = (l+r+1)/2;
        if(check(mid) == true)
            l = mid;
        else
            r = mid-1;
    }
    return r;
}
```

###### 贪心 ➕ 双指针
> 进一步简化, 把`二分`省略, `nums[j]`从`0`开始, `nums[i]`从`(n+1)/2`开始枚举

```CPP
int maxNumOfMarkedIndices(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 双指针, i从最左, j从中间, 同向移动
    int i=0, j=(n+1)/2;
    while(i<n/2 && j<n){
        if(2*nums[i]<=nums[j]){
            i++;
            j++;
        }
        else
            j++;
    }
    return i*2;
}
```