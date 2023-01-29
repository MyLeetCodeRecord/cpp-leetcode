#### Weekly 327

##### 1. [正整数和负整数的最大计数](https://leetcode.cn/problems/maximum-count-of-positive-integer-and-negative-integer/): `二分查找`

> 思路一: 遍历统计正负数, 考试的时候遍历一遍就可以了
> 
> 思路二: 二分查找`a[i]>=0`的第一个位置

```CPP
int maximumCount(vector<int>& nums) {
    int neg=0, pos=0;
    for(int x: nums){
        if(x > 0)
            pos++;
        if(x < 0)
            neg++;
    }
    return max(pos, neg);
}
```


##### 2. [执行K次操作后的最大分数](https://leetcode.cn/problems/maximal-score-after-applying-k-operations/): `priority_queue` `贪心`

```CPP
long long maxKelements(vector<int>& nums, int k) {
    priority_queue<int> heap;   // 贪心, 每次选择最大的nums[i]进行操作
    for(int x: nums){
        heap.push(x);
    }
    long long sum = 0;
    for(int i=0; i<k; i++){     // k次操作
        double t = heap.top();  // 注意使用浮点数, 防止nums[i]/3出错
        sum += t;
        heap.pop();
        heap.push(ceil(t / 3.0));   // 向上取整
    }
    return sum;
}
```


##### 3. [](): `hash` `暴力`

```CPP
int mp1[26] = {0};
int mp2[26] = {0};
// 比较一次交换后是否两个字符串不同字符数目是否相等
bool helper(){
    int a1 = 0, a2 = 0;
    for(int i=0; i<26; i++)
        a1 += (mp1[i]!=0);
    for(int i=0; i<26; i++)
        a2 += (mp2[i]!=0);
    return a1==a2;
}
bool isItPossible(string word1, string word2) {
    int all1 = 0, all2 = 0;
    for(char ch: word1){
        mp1[ch-'a']++;
        if(mp1[ch-'a']==1)
            all1++;
    }
    for(char ch: word2){
        mp2[ch-'a']++;
        if(mp2[ch-'a']==1)
            all2++;
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            if(mp1[i]==0 || mp2[j]==0)
                continue;
            // 尝试交换
            mp1[i]--, mp1[j]++;
            mp2[j]--, mp2[i]++;
            if(helper())
                return true;
            // 恢复到交换前
            mp1[i]++, mp1[j]--;
            mp2[j]++, mp2[i]--;
        }
    }
    // 不能恰好一次 => return false;
    return false;
}
```