#### DP - 双序列

> 此类问题是指, 给定**两个序列(数组/字符串)**, 求
> - 最长公共子序列
> - 最短公共超级序列(Supersequence)
> - 编辑距离...
> 
> 解题思路:
> 
> `dp[i][j]`表示s[:i]和t[:j]子问题的最优解
> 
> `dp[i][j]`往往是从`dp[i-1][j]`、`dp[i][j-1]`、`dp[i-1][j-1]`转移而来
> 
> 最终结果往往为`dp[m][n]`

##### [LC1143. 最长公共子序列](https://leetcode.cn/problems/uncrossed-lines)

> 题目描述: https://leetcode.cn/problems/longest-common-subsequence/
>
> `dp[i][j]`不要求严格以`text1[i-1]`和`text2[j-1]`结尾
>
> 相同的题目有[LC1035. 不相交的线](/workspace/1035.%E4%B8%8D%E7%9B%B8%E4%BA%A4%E7%9A%84%E7%BA%BF.cpp)

```CPP
vector<vector<int> > dp(m+1, vector<int>(n+1, 0)); // 注意错开一位
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        if(text1[i-1] == text2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
return dp[m][n];
```

##### [LC1092. 最短公共超序列](/workspace/1092.%E6%9C%80%E7%9F%AD%E5%85%AC%E5%85%B1%E8%B6%85%E5%BA%8F%E5%88%97.cpp)

> 题目描述: https://leetcode.cn/problems/shortest-common-supersequence/

> 直接思路(超时⌚)
> 
> `dp[i][j]`表示`s[:i]`和`t[:j]`的最短公共超序列长度
> 
> 如果`s[i]==s[j]` => 这个字符一定在最短公共超序列中 => `dp[i][j]=dp[i-1][j-1]+1`
> 
> 如果`s[i]!=s[j]` => 两个字符都应该加入最短公共超序列 => `dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + 1`
> 
> 同时要使用二维`vector<vector<string> > ans`来记录超序列内容
> 
> 然后发现记录长度的`dp[i][j]`数组并没有意义, 只使用`ans[i][j]`即可

```CPP
string shortestCommonSupersequence(string str1, string str2) {
    vector<vector<string>> ans(str1.size()+1, vector<string>(str2.size()+1, ""));
    ans[0][0] = "";
    for(int j=1; j<=str2.size(); j++){
        ans[0][j] += str2.substr(0, j);
    }
    for(int i=1; i<=str1.size(); i++){
        ans[i][0] += str1.substr(0, i);
    }
    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1]==str2[j-1]){
                ans[i][j] = ans[i-1][j-1] + str1[i-1];
            }
            else{
                if(ans[i-1][j].size() < ans[i][j-1].size())
                    ans[i][j] = ans[i-1][j] + str1[i-1];
                else
                    ans[i][j] = ans[i][j-1] + str2[j-1];
            }
        }
    }
    return ans[str1.size()][str2.size()];
}
```

> 正确的解法是先构建`LCS`(最短公共子序列), 再借助`LCS`构建超序列

```CPP
string shortestCommonSupersequence(string str1, string str2) {
    // 省略求LCS的代码
    string lcs = getLCS(str1, str2);
    // 构建目的字符串
    string ans = "";
    int i=0, j=0;
    // 按照同一个字符串内的字符相对于LCS的顺序构建目的字符串
    for(char commonChar: lcs){
        // 加入不在LCS中的字符
        while(i<str1.size() && str1[i]!=commonChar)
            ans += str1[i++];
        while(j<str2.size() && str2[j]!=commonChar)
            ans += str2[j++];
        // 加入LCS中的(公共)字符
        ans += commonChar;
        i++;
        j++;
    }
    // 加上剩余字符串
    return ans + str1.substr(i) + str2.substr(j);
}
```


##### [LC72. 编辑距离](/workspace/72.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.cpp)

> 题目描述: https://leetcode.cn/problems/edit-distance
> 相等 => `dp[i][j] = dp[i-1][j-1]`
> 
> 不相等 => 修改/添加/删除 => `dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))`

```CPP
vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
for(int j=1; j<=n; j++)
    dp[0][j] = j;
for(int i=1; i<=m; i++)
    dp[i][0] = i;
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++)
        if(word1[i-1]==word2[j-1])
            dp[i][j] = dp[i-1][j-1];
        else
            // 替换 => dp[i-1][j-1]+1
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
    }
}
return dp[m][n];
```


##### [LC97. 交错字符串](/workspace/97.%E4%BA%A4%E9%94%99%E5%AD%97%E7%AC%A6%E4%B8%B2.cpp)

> 题目描述: https://leetcode.cn/problems/interleaving-string
> 
> `dp[i][j]`表示`s1[:i]`和`s2[:j]`能够组成`s3[:i+j+1]`
> 
> 事实上要证明**存在性**, **交叠**并不重要, 只是结尾字符比较问题

```CPP
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    if(m + n != s3.size())
        return false;
    vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
    dp[0][0] = true;
    for(int i=1; i<=m; i++){
        dp[i][0] = (dp[i-1][0] && s1[i-1]==s3[i-1]);
    }
    for(int j=1; j<=n; j++){
        dp[0][j] = (dp[0][j-1] && s2[j-1]==s3[j-1]);
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int k = i + j - 1;
            if(s1[i-1]==s3[k] && dp[i-1][j]==true)
                dp[i][j] = true;
            if(s2[j-1]==s3[k] && dp[i][j-1]==true)
                dp[i][j] = true;
        }
    }
    return dp[m][n];
}
```


##### [LC115. 不同的子序列](/workspace/115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97.cpp)

> 题目描述: https://leetcode.cn/problems/distinct-subsequences/
> 
> `dp[i][j]`表示`s[:i]`的子序列中等于`t[:j]`的个数
> - 如果`s[i-1]==t[j-1]`, `dp[i][j] = dp[i-1][j-1] + dp[i-1][j]`
> - 如果`s[i-1]!=t[j-1]`, `dp[i][j] = dp[i-1][j]`

```CPP
vector<vector<uint64_t> > dp(m+1, vector<uint64_t>(n+1, 0));
for(int i=0; i<=m; i++){
    dp[i][0] = 1;
}
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        if(s[i-1] == t[j-1])
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        else
            dp[i][j] = dp[i-1][j];
    }
}
return dp[m][n];
```


##### [LC727. 最小窗口子序列](https://leetcode.cn/problems/minimum-window-subsequence)

> 又是没有会员的一天呢, 题目就是找到字符串s中包含字符串t的最短Substring(连续)
> 
> `dp[i][j]`表示`s[:i]`包含`t[:j]`的最短Substring长度, 注意Substring需要**严格以s[i]结尾**

```CPP
vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
for(int i=0; i<=m; i++){
    dp[i][0] = 0;
}
int ans = INT_MAX;
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        if(s[i-1]==t[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = dp[i-1][j] + 1;
    }
    ans = min(ans, dp[i][n]);
}
return (ans==INT_MAX) ? "" : ans;
```


##### [LC583. 两个字符串的删除操作](/workspace/583.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%88%A0%E9%99%A4%E6%93%8D%E4%BD%9C.cpp)

> 题目描述: https://leetcode.cn/problems/delete-operation-for-two-strings
> 
> 简化的[编辑距离](/workspace/72.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.cpp)问题

```CPP
vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
for(int i=1; i<=m; i++)
    dp[i][0] = i;
for(int j=1; j<=n; j++)
    dp[0][j] = j;
for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
        if(word1[i-1] == word2[j-1])
            dp[i][j] = dp[i-1][j-1];
        else
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
    }
}
return dp[m][n];
```


##### [LC712. 两个字符串的最小ASCII删除和](/workspace/712.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%8Fascii%E5%88%A0%E9%99%A4%E5%92%8C.cpp)

> 题目描述: https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
> 
> "转换一下, 这个题目就是求公共子串, 要求这些公共子串的ASCII值最大"
> - 如果`s[i-1]==s[j-1]`, `dp[i][j] = dp[i-1][j-1]`
> (~~但我觉得也可以取自`min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1])+1`?~~)
> 
> - 如果`s[i-1]!=s[j-1]`, `dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1])`
```CPP
int minimumDeleteSum(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++)
        dp[i][0] += dp[i-1][0] + s1[i-1];
    for(int j=1; j<=n; j++)
        dp[0][j] += dp[0][j-1] + s2[j-1];
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
        }
    }
    return dp[m][n];
}
```


##### [1312. 让字符串变成回文串的最少插入次数](/workspace/1312.%E8%AE%A9%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%88%90%E4%B8%BA%E5%9B%9E%E6%96%87%E4%B8%B2%E7%9A%84%E6%9C%80%E5%B0%91%E6%8F%92%E5%85%A5%E6%AC%A1%E6%95%B0.cpp)

> 题目描述: https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
> 
> 这道题状态转移很容易想到, 难点在于dp数组如何构建(循环如何定义)
> 
> `dp[i][j]`表示让s[i:j]变成回文串的最少插入次数
> 
> 一个基本的要求是`dp[i][j]`一定由更小区间的`dp[i+x][j-y]`转移得到

```CPP
int minInsertions(string s) {
    int n = s.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            else{
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }
    return dp[0][n-1];
}
```

> 这道题也可以借助`LCS`, 求字符串s及逆序字符串t的最长公共子序列长度, 要删除的次数即为`n-LCS`

```CPP
int minInsertions(string s) {
    string t = s;
    reverse(s.begin(), s.end());
    int n = s.size();
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return n - dp[n][n];
}
```