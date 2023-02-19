#### Biweekly 98

##### 1. [替换一个数字后的最大差值](https://leetcode.cn/contest/biweekly-contest-98/problems/maximum-difference-by-remapping-a-digit/): `模拟` `min/max`

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


##### 2. [修改两个元素的最小分数](https://leetcode.cn/contest/biweekly-contest-98/problems/minimum-score-by-changing-two-elements/): `思维题` `min/max`

> 写了好久找最大最小、次大次小, 但是`3 <= nums.length <= 10^5`, 可以直接排序

```CPP
int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n-2] - nums[1];
        ans = min(ans, nums[n-1]-nums[2]);
        ans = min(ans, nums[n-3]-nums[0]);
        return ans;
    }
```


##### 3. [最小无法得到的或值](https://leetcode.cn/contest/biweekly-contest-98/problems/minimum-impossible-or/): `贪心` `思维题`

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