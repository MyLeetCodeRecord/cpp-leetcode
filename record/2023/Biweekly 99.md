#### Biweekly 99

##### 1. [最小和分割](https://leetcode.cn/problems/split-with-minimum-sum/): `贪心`

> 将每个位置数字从小到大排序, 然后给两个人"发牌", 前导0不影响结果

```CPP
int splitNum(int num) {
    string str = to_string(num);
    sort(str.begin(), str.end());
    string n1 = "";
    string n2 = "";
    for(int i=0; i<str.size(); i++){
        if(i%2==0){
            n1 += str[i];
        }
        else{
            n2 += str[i];
        }
    }
    return stoi(n1) + stoi(n2);
}
```


##### 2. [统计染色格子数](https://leetcode.cn/problems/count-total-number-of-colored-cells/): `找规律`

> 小心溢出就可以了, 骗罚时的题罢了🤡

```CPP
long long coloredCells(int n) {
    long long x = n;
    return x * x + (x-1) * (x-1);
}
```


##### 3. [统计将重叠区间合并成组的方案数](https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/): `区间合并`

> 复习一下[区间合并](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%8C%BA%E9%97%B4.md)和[快速幂](/acwing/Section%204/Acwing%20-%20%E5%BF%AB%E9%80%9F%E5%B9%82.md)
>
> 区间合并后得到区间数量`len`, 答案为`

```CPP
int quickPow(int a, int n, int MOD){
    long long ans = 1;
    while(n != 0){
        if(n & 1)
            ans = (ans * a) % MOD;
        a = (long long)a * a % MOD;
        n >>= 1;
    }
    return ans % MOD;
}
int merge(vector<pair<int,int>> &intervals){
    // vector<pair<int,int>> res;
    int cnt = 0;
    sort(intervals.begin(), intervals.end());
    pair<int,int> curInt = intervals[0];
    for(int i=0; i<intervals.size(); i++){
        if(curInt.second < intervals[i].first){
            // res.push_back(curInt);
            cnt++;
            curInt = intervals[i];
        }
        else
            curInt.second = max(curInt.second, intervals[i].second);
    }
    // res.push_back(curInt);
    // return res.size();
    cnt++;
    return cnt;
}
int countWays(vector<vector<int>>& ranges) {
    int n = ranges.size();
    vector<pair<int,int>> ints(n);
    for(int i=0; i<n; i++){
        ints[i] = {ranges[i][0], ranges[i][1]};
    }
    int cnt = merge(ints);
    return quickPow(2, cnt, 1000000007);
}
```


##### 4. [统计可能的树根数目6](https://leetcode.cn/problems/count-number-of-possible-root-nodes/): `换根dp`

todo