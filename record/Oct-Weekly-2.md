#### Weekly 1

##### [1. 处理用时最长的那个任务的员工](https://leetcode.cn/problems/the-employee-that-worked-on-the-longest-task/): `差分 `
```CPP
int hardestWorker(int n, vector<vector<int>>& logs) {
    int ans = logs[0][0];
    int longest = logs[0][1];
    for(int i=1; i<logs.size(); i++){
        int time = logs[i][1] - logs[i-1][1];
        if(time > longest || (time==longest && logs[i][0] < ans)){
            ans = logs[i][0];
            longest = time;
        }
    }
    return ans;
}
```


##### [2. 找出前缀异或的原始数组](https://leetcode.cn/problems/find-the-original-array-of-prefix-xor/): `前缀和` `bit`
```CPP
vector<int> findArray(vector<int> & pref){
    vector<int> ans(pref.size(), 0);
    ans[0] = pref[0];
    for(int i=1; i<pref.size(); i++){
        ans[i] = pref[i] ^ pref[i-1];   // 前缀和
    }
    return ans;
}
```


##### [3. 使用机器人打印字典序最小的字符串](https://leetcode.cn/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)
> ![LC6202](/appendix/LC6202.png)
> 
> 字符串`t`相当于一个`栈stack`
> 
> 问题转换为: 借助一个`stack`, 能够获得的最小字典序的字符串
> 
> 想让字典序最小, 让所有a->所有**符合规则的**b->···->所有**符合规则的**的z
> 
> 以'b'为例, 当处理完'a'之后, 不只s中有b, t(stack)中也可能有b
> 
> - 先输出`t(stack)`中所有的'b'(重复出栈操作)  ❗️ 但不代表t中就没有b了 比如t="... b b c b", 前面两个b无法被输出, 这是对a贪心、不可避免的consequence
> 
> - 再处理所有字符串s中的'b'
> 
> 以上述方案依次处理26个字母即可
> 
> 最后当s为空, 按序弹出`t(stack)`中所有元素即可

```CPP
string robotWithString(string s) {
    string ans = "";    // output
    string t = "";      // t (stack)
    vector<int> pos(26, -1);    // 每个字符最后一次出现的位置
    for(int i=0; i<s.size(); i++){
        pos[s[i]-'a'] = i;
    }
    int k = 0;          // s上的指针, 因为s是从左向右、不回头行进的
    for(int i=0; i<26; i++){    // 依次处理26个字母
        char ch = 'a'+i;
        while(t.size() > 0 && t.back() <= ch){
            ans += t.back();
            t.pop_back();
        }
        while(k<=pos[i]){       // 表示字符串里还有ch存在
            if(s[k]==ch)
                ans += ch;
            else
                t += s[k];
            k++;
            // 这里可以直接输出当前ch, 或者放到t(stack)中等下一轮输出
        }
    }
    reverse(t.begin(), t.end());
    return ans + t;
}
```


##### [4. 矩阵中和能被 K 整除的路径](https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/)
> 首先要用dp, 路径条数可以用二维`dp[i][j]`表示到`(i,j)`的路径条数
> 
> [路径问题](/markdown/%E4%B8%93%E9%A2%98%20-%20DP%20-%20%E8%B7%AF%E5%BE%84%E9%97%AE%E9%A2%98.md)
> 
> 题目多加了一层限制 - 路径长度能整除 k => dp多加一维表示路径长度对k的余数(0～k-1),  即`dp[m][n][k]`
> 
> 复杂度`O(m * n * k)` <= 5*10^4*50 < `10^6`

```CPP
int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int dp[m][n][k];
    memset(dp, 0, sizeof dp);

    // 好奇怪的初始化, 细品...
    dp[0][0][grid[0][0] % k] = 1;
    for(int i=1; i<m; i++){
        for(int a=0; a<k; a++){
            if(dp[i-1][0][a] == 1){
                dp[i][0][(a+grid[i][0])%k] = 1;
            }
        }
    }
    for(int j=1; j<n; j++){
        for(int a=0; a<k; a++){
            if(dp[0][j-1][a] == 1){
                dp[0][j][(a+grid[0][j])%k] = 1;
            }
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            for(int a=0; a<k; a++){
                int third;
                // 上->下
                third = (a + grid[i][j]) % k;
                dp[i][j][third] += dp[i-1][j][a];
                // 左->右
                third = (a + grid[i][j]) % k;
                dp[i][j][third] += dp[i][j-1][a];
                dp[i][j][third] %= 1000000007;
            }
        }
    }
    return dp[m-1][n-1][0] % 1000000007;    // dp[m][n] & 余数为 0 的维度
}
```