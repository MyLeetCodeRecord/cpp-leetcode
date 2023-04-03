#### Weekly 339

##### 1. [最长平衡子字符串](https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/)

> 暴力枚举 ➡️ 倒序枚举子串长度`len`(只考虑偶数`len+=2`)和起点`i`做的, 保证子串左1/2全部为`0`, 右1/2全部为`1`
>
> 灵神的做法 ➡️ 枚举「分界点」, ans = 2 * min(向左连续`0`的个数, 向右连续`0`的个数)

```CPP
int findTheLongestBalancedSubstring(string s) {
    int n = s.size();
    // 从长到短枚举所有子串, 如果有满足条件的直接返回
    for(int len=n; len>=0; len--){
        if(len % 2 == 1)
            continue;
        for(int i=0; i+len-1<n; i++){
            int j = i + len - 1;
            bool flag = true;
            // 前面全0
            for(int k=i; k<i+len/2; k++){
                if(s[k]!='0'){
                    flag = false;
                    break;
                }
            }
            // 后面全1
            for(int k=i+len/2; k<=j; k++){
                if(s[k]!='1'){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return len;
        }
    }
    return 0;
}
```

##### 2. [转换二维数组](https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/): `hash`

```CPP
vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<int> mp(201, 0);
    int maxFreq = 0;;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]] ++;
        maxFreq = max(maxFreq, mp[nums[i]]);
    }
    vector<vector<int>> ans(maxFreq);
    for(int i=1; i<=200; i++){
        for(int j=0; j<mp[i]; j++){
            ans[j].push_back(i);
        }
    }
    return ans;
}
```

##### 3. [老鼠和奶酪](https://leetcode.cn/problems/mice-and-cheese/): `diff贪心`

> 直觉就是先「求差」得到`diff`, 然后对`diff`排序, `diff`大的k个位置取`reward1`, 剩下的位置取`reward2`
>
> 证明: 选两个位置`<i, j>`, 并假设`diff[i] > diff[j]`
> - 根据`diff`的相对大小可知, `reward1[i] - reward2[i] > reward1[j] - reward2[j]`
> - 移项可得, `reward1[i] + reward2[j] > reward1[j] + reward2[i]`
> - 即先让`diff`大的取`reward1`, 能取得更大的收益

```CPP
typedef pair<int,int> PII;
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    int n = reward1.size();
    vector<PII> diff(n);
    for(int i=0; i<n; i++){
        diff[i] = {reward1[i] - reward2[i], i};
    }
    sort(diff.begin(), diff.end());
    int ans = 0;
    for(int i=n-1; i>=n-k; i--){
        ans += reward1[diff[i].second];
    }
    for(int i=n-k-1; i>=0; i--){
        ans += reward2[diff[i].second];
    }
    return ans;
}
```
