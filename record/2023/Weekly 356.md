#### Weekly 356

##### 1. [满足目标工作时长的员工数目](https://leetcode.cn/problems/number-of-employees-who-met-the-target/): `遍历`

```CPP
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int ans = 0;
    for(int x : hours)
        if (x >= target)
            ans++;
    return ans;
}
```

##### 2. [统计完全子数组的数目](https://leetcode.cn/problems/count-complete-subarrays-in-an-array/): `滑动窗口`
> 滑动窗口规则: 保证窗口内的「字符类型数」=「全局字符类型数」

```CPP
int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> st;
    for(int x : nums){
        st.insert(x);
    }
    int ans = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mp;
    while(r < n){
        mp[nums[r++]]++;
        while(mp.size()==st.size()){
            mp[nums[l]]--;
            if(mp[nums[l]]==0)
                mp.erase(nums[l]);
            l++;
        }
        ans += l;
    }
    return ans;
}
```

##### 3. [包含三个字符串的最短字符串](https://leetcode.cn/problems/shortest-string-that-contains-three-strings/): `全排列`(`next_permutation`)

> 回想一下心路历程, 以及反思一下为啥比赛结束才写出来
>
> 一开始就想到了一共abc, acb, bac, bca, cab, cba, 并且a, b, c的长度也不长
>
> 但是做着做着就开始失去全局观, 开始瞎写

> 任意一个全排列的处理是相同的, 所以不要去改变每一次combine中`{a, b, c}`的相对位置
>
> - 将`str`初始化为`a`
> - 加入`b`时, 
>   - 如果`a`包含`b`, 就忽略这次拼接
>   - 如果`a`不包含`b`, 比较`str[str.size()-i: ]`和`b[0: i]`, 使它们相等的最大的`i`就是拼接中可以省略的长度
> - 插入`c`类似, 注意是在`str`后面拼接, 而不是`b`

```CPP
string combine(string a, string b, string c){
    string str = a;
    // 加入b
    // cab, a, b => cab, 包含就不需要拼接
    if(str.find(b) == string::npos){
        int len_b = 0;
        for(int i=1; i<=str.size() && i<=b.size(); i++){
            if(str.substr(str.size()-i, i) == b.substr(0, i)){
                len_b = max(len_b, i);
            }
        }
        str += b.substr(len_b);
    }
    // 加入c
    if(str.find(c) == string::npos){
        int len_c = 0;
        for(int i=1; i<=str.size() && i<=c.size(); i++){
            if(str.substr(str.size()-i, i) == c.substr(0, i)){
                len_c = max(len_c, i);
            }
        }
        str += c.substr(len_c);
    }
    return str;
}
// 全排列一共abc, acb, bac, bca, cab, cba这六种情况
string minimumString(string a, string b, string c) {
    string ans = a + b + c;
    vector<string> list = {a, b, c};
    for(int i=0; i<6; i++){
        string tmp = combine(list[0], list[1], list[2]);
        next_permutation(list.begin(), list.end());
        if(tmp.size()<ans.size() || (tmp.size()==ans.size() && tmp<ans))
            ans = tmp;
    }
    return ans;
}
```