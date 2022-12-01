#### Biweek 2

##### 1. [分割圆的最少切割次数](https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/)
> - 奇数份: 没有一条直径, n条
> - 偶数份: n/2条直径
> - 特判`1`: 一条半径是无意义的

```CPP
int numberOfCuts(int n) {
    if(n==1)
        return 0;
    if(n%2==0)
        return n/2;
    else
        return n;
}
```

##### 2. [行列式中一和零的差值](https://leetcode.cn/problems/difference-between-ones-and-zeros-in-row-and-column/)

> 双周赛的时候用`前缀和`求的, 太多此一举了...

```CPP
int prefixSumOp(vector<vector<int>> &ps, int x1, int y1, int x2, int y2){
    return ps[x2][y2]-ps[x1-1][y2]-ps[x2][y1-1]+ps[x1-1][y1-1];
}
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> prefixSum(n+1, vector<int>(m+1, 0));
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            prefixSum[i][j] = grid[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    for (int i=1; i<=n; i++)
        rows[i-1] = prefixSumOp(prefixSum, i, 1, i, m);
    for (int j=1; j<=m; j++)
        cols[j-1] = prefixSumOp(prefixSum, 1, j, n, j);
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            ans[i][j] = rows[i] - (m-rows[i]) + cols[j] - (n-cols[j]);
        }
    }
    return ans;
}
```

> 直接统计`rows`, `cows`就可以了, 遇到`1`则`+1`, 遇到`0`则`-1`

```CPP
// oneRow[i] + oneCol[j]     -  zeroRow[i] - zeroCol[j]
// (oneRow[i] - zeroRow[i])  +  (oneCol[j] - zeroCol[j])
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> rows(m, 0);
    vector<int> cols(n, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            rows[i] += (grid[i][j]==1) ? 1 : -1;
            cols[j] += (grid[i][j]==1) ? 1 : -1;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = rows[i] + cols[j];
        }
    }
    return grid;
}
```

##### 3. [商店的最小代价](https://leetcode.cn/problems/minimum-penalty-for-a-shop/)
> **方法一: `计数前缀和`**
> 
> 统计截止到每个位置, 'N'的个数

```CPP
int bestClosingTime(string customers) {
    // nCnt[i]: 统计 0~i 中'N'的个数
    int n = customers.size();
    vector<int> nCnt(n+1);
    nCnt[0] = 0;
    for(int i=1; i<=n; i++){
        nCnt[i] = nCnt[i-1] + (customers[i-1]=='N');
    }
    int ans = 0;
    int minv = 0x3f3f3f3f;
    for(int i=0; i<=n; i++){
        // cost: 从 i 位置截断(注意nCnt[]是从下标1开始存储的)
        //   - 前面'N'的个数 => nCnt[N]
        //   - 后面'Y'的个数 => n-i-(nCnt[n]-nCnt[i])   // 括号里的部分(nCnt[n]-nCnt[i]), 前缀和的思想
        int cost = nCnt[i] + (n - i - nCnt[n] +nCnt[i]);
        if(cost < minv){
            ans = i;
            minv = cost;
        }
    }
    return ans;
}
```

> **方法二: `前后缀匹配`**
> 
> 用`cost`维护指针走到`i`位置的`cost`值, 即`前半段的N + 后半段的Y`
> 
> 指针`i`从`0`移动到`n-1`
> - 如果一个`'Y'`移动进来 ➡️ 前半段不变, 后半段`cost -= 1`
> - 如果一个`'N'`移动进来 ➡️ 前半段`cost += 1`, 后半段不变

```CPP
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        // cost维护指针走到i位置的cost值, 前半段的N + 后半段的Y
        int cost = 0;
        for(char ch : customers){
            cost += (ch=='Y');
        }
        int minCost = cost;
        int ans = 0;
        // 指针后移一位, customers[i]是被移动进来的
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y')
                cost -= 1;
            else
                cost += 1;
            if(cost < minCost){  // 不带等号, 相同cost越早关门越好
                minCost = cost;
                ans = i+1;
            }
        }
        return ans;
    }
};
```

##### 4. [统计回文子序列数目](https://leetcode.cn/problems/count-palindromic-subsequences/)
> 相关题目: [LC1930. 长度为3的不同回文子序列](/workspace/1930.%E9%95%BF%E5%BA%A6%E4%B8%BA-3-%E7%9A%84%E4%B8%8D%E5%90%8C%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.cpp)
> 
> 枚举每个字符的`firstOccur`和`secondOccur`, 然后中间点的取值在`(firstOccur, second)`中间(开区间), 并**用`set`去重**

> 思路: 本题中要求回文子串长度为`5`, 说明只需要考虑长度为`2`的前后缀, 另外本题不要求去重计数
> 
> - `s[i,x,y]`表示正序中, 字符串`1~i`中前缀`<x, y>`出现的次数
> 
> - `r[i,y,x]`表示逆序中, 字符串`i~n`中后缀`<y, x>`出现的次数
> 
> 两个三维数组的求解可以借助一个`cnt[0~9]`, 表示截止到`i-1`, `<x, y>`中`x`的个数, 注意先更新`s, r`再更新`cnt[y]`
> 
> 最后遍历每个元素`s[i]`作为中心元素, 枚举每个前缀`<x,y>`(对应后缀为`<y,x>`)的个数
> 
> 按乘法原理获得以`s[i]`为中心的回文子串个数, 加到`ans`

> 题解: [y总](https://www.bilibili.com/video/BV1t14y1n7Qk/), [灵神](https://www.bilibili.com/video/BV1uG4y157Rc/)

```CPP
typedef long long LL;
const int N = 10010, MOD = 1e9+7;

class Solution {
    int s[N][10][10];   // left -> right
    int r[N][10][10];   // right -> left
    int cnt[10];        // 前面/后面 i 的个数
public:
    int countPalindromes(string str) {
        int n = str.size();
        // 计算 s[i][j][k]
        for(int i=1; i<=n; i++){
            for(int j=0; j<10; j++){
                for(int k=0; k<10; k++){
                    s[i][j][k] = s[i-1][j][k];
                }
            }
            int y = str[i-1] - '0';  // s数组第一维是从1开始的, 错开一位
            for(int j=0; j<10; j++){
                s[i][j][y] += cnt[j];
            }
            cnt[y]++;   // 上面的计算不应考虑当前位, cnt[y]++需要后置
        }
        // 计算 r[i][j][k]
        memset(cnt, 0, sizeof cnt);
        for(int i=n; i>=1; i--){
            for(int j=0; j<10; j++){
                for(int k=0; k<10; k++){
                    r[i][j][k] = r[i+1][j][k];
                }
            }
            int y = str[i-1] - '0';
            for(int j=0; j<10; j++){
                r[i][y][j] += cnt[j];
            }
            cnt[y]++;
        }
        LL ans = 0;
        for(int i=3; i<=n-2; i++){
            for(int j=0; j<10; j++){
                for(int k=0; k<10; k++){
                    ans = (ans + (LL)s[i-1][j][k] * r[i+1][k][j]) % MOD;
                }
            }
        }
        return ans;
    }
};
```