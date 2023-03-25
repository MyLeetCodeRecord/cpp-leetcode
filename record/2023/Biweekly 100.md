#### Biweekly 100

> 记录第一次没被rej的水题ak

##### 1. [将钱分给最多的儿童](https://leetcode.cn/problems/distribute-money-to-maximum-children/): `逻辑思维` `分类讨论`
> 听取wa声一片, 喜8忌4
>
> - 条件一: 每名儿童至少获得 1 块钱 ➡️ 预先分配给每人 1 块钱, 变成喜7忌3的问题
> - 条件二: 令最多的儿童获得恰好 8 块钱 ➡️ `eight = money / 7`
> - 条件三: 没有人获得 4 块钱 ➡️ 只在「剩余 3 块钱 && 只剩下一个孩子」的情况下, 返回`eight-1`

```CPP
int distMoney(int money, int children) {
    if(money < children)
        return -1;
    if(money > 8*children)
        return children-1;
    // 每个人预先分配1美元
    money -= children;
    // 恰好分配8美元的儿童个数
    int eight = money / 7;
    // 剩余金额 => 忌4
    int rest = money % 7;
    if(rest == 3 && children==eight+1)
        return eight-1;
    return eight;
}
```


##### 2. [最大化数组的伟大值](https://leetcode.cn/problems/maximize-greatness-of-an-array/): `贪心` `双指针`
> `O(nlogn)`做法: 直觉`排序`, 然后用`双指针`找到多少个小值能够有更大值匹配
>
> `O(n)`做法: 周赛时直接找出现次数最多的数字频次, 然后返回`n-maxLen`即可 (不需要排序, 用`cnt[]`计数即可)

```CPP
int maximizeGreatness(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 双指针
    int l = 0;
    for(int r=0; r<n; r++){
        if(nums[r] > nums[l])
            l++;
    }
    return l;
}
```


##### 3. [标记所有元素后数组的分数](https://leetcode.cn/problems/find-score-of-an-array-after-marking-all-elements/): `priority_queue` `模拟`

```CPP
typedef pair<int, int> PII;
long long findScore(vector<int>& nums) {
    int n = nums.size();
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<bool> st(100010, false);
    for(int i=0; i<n; i++){
        pq.push({nums[i], i});
    }
    long long ans = 0;
    while(pq.empty()==false){
        PII t = pq.top();
        int cur = t.second;
        pq.pop();
        if(st[cur]==false){
            // 标记 left, cur, right
            st[cur] = true;
            ans += t.first;
            if(cur-1 >= 0)
                st[cur-1] = true;
            if(cur+1 < n)
                st[cur+1] = true;
        }
    }
    return ans;
}
```


##### 4. [修车的最少时间](https://leetcode.cn/problems/minimum-time-to-repair-cars/): `二分`

```CPP
bool check(vector<int>& ranks, long long mid, int cars){
    long long ans = 0;
    for(int rank: ranks)
        // 向下取整用int()也可以
        ans += floor(sqrt(mid / rank));
    return ans >= cars;
}
long long repairCars(vector<int>& ranks, int cars) {
    long long l = 1, r = 1e15;
    while(l < r){
        long long mid = (l + r) / 2;
        if(check(ranks, mid, cars)==false)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```