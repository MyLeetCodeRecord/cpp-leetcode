#### Biweekly 98

##### 1. [替换一个数字后的最大差值](https://leetcode.cn/problems/maximum-difference-by-remapping-a-digit/): `模拟` `min/max`

> 将第一个不是`9`的数换成`9` => `max`
>
> 将第一个不是`0`的数换成`0` => `min`

```CPP
int getMax(string s){
    char change = s[0];
    for(int i=0; i<s.size(); i++){
        if(s[i] != '9'){
            change = s[i];
            break;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == change)
            s[i] = '9';
    }
    return stoi(s);
}
int getMin(string s){
    char change = s[0];
    for(int i=0; i<s.size(); i++){
        if(s[i] != '0'){
            change = s[i];
            break;
        }
    }
    for(int i=0; i<s.size(); i++){
        if(s[i] == change)
            s[i] = '0';
    }
    return stoi(s);
}
int minMaxDifference(int num) {
    return getMax(to_string(num)) - getMin(to_string(num));
}
```


##### 2. [修改两个元素的最小分数](https://leetcode.cn/problems/minimum-score-by-changing-two-elements/): `思维题` `min/max`

> 修改两个数使最大间距 ➕ 最小间距
> - 容易想到将其中一个修改次数修改为其它已经存在的值, 就可以消除最小间距部分
>
> - 最大间距部分, 目标是缩小最大值和最小值, 有三种可能的执行方案: 
>   - 最大值和最小值都向中间靠拢, 最大值变为次大值, 最小值变为次小值
>   - 最大值和次大值向中间靠拢, 比如变为第三大的数
>   - 最小值和次小值向中间靠拢, 比如变为第三小的数
> 
> 写了好久找最大最小、次大次小, 但是`3 <= nums.length <= 10^5`, 可以直接排序

```CPP
int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 最大值和最小值都向中间靠拢
        int ans = nums[n-2] - nums[1];
        // 最大值和次大值 / 最小值和次小值向中间靠拢
        ans = min(ans, min(nums[n-1]-nums[2], nums[n-3]-nums[0]));
        return ans;
    }
```


##### 3. [最小无法得到的或值](https://leetcode.cn/problems/minimum-impossible-or/): `贪心` `思维题`

> **方法一: 贪心**
> 一周前的每日一题[📌1798. 你能构造出连续值的最大数目🧡](/workspace/1798.%E4%BD%A0%E8%83%BD%E6%9E%84%E9%80%A0%E5%87%BA%E8%BF%9E%E7%BB%AD%E5%80%BC%E7%9A%84%E6%9C%80%E5%A4%A7%E6%95%B0%E7%9B%AE.cpp)原题, **连续构造**直到何时停止
>
> 灵神题解: https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/solution/mei-xiang-ming-bai-yi-zhang-tu-miao-dong-7xlx/

```CPP
int minImpossibleOR(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int x : nums){
        if(x > ans + 1)
            return ans+1;
        ans |= x;
    }
    return ans+1;
}
```

> **方法二: 2的幂次**
> - 2的幂次存在的必要性: 或运算一定是越或大, 如果一个数只有一个比特的话(即2的幂次), 那这个数一定要在数组中
> - 2的幂次存在的充分性: 如果2的幂次是连续的, 比如数组中包含`1, 2, 4`, 那么`1 ~ 8-1`之间的数都可以由这些2的幂次所表达
> 
> 问题就转化成 ➡️ 找到第一个「缺失的2的幂次」 ➡️ 转为二进制表示后在数组中查找或者下面的做法

```CPP
int minImpossibleOR(vector<int>& nums) {
    int mask = 0;
    for(int x : nums){
        if((x & (x-1))==0)
            mask |= x;
    }
    // 找最低位的0 => 取反后lowbit找最低位的1
    mask = ~mask;
    return mask & (-mask);
}
```