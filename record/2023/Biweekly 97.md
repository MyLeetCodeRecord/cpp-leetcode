#### Biweekly 97

##### 1. [分割数组中数字的数位](https://leetcode.cn/problems/separate-the-digits-in-an-array/): `十进制数`

```CPP
vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
    for(int i=nums.size()-1; i>=0; i--){
        int x = nums[i];
        while(x != 0){
            ans.push_back(x % 10);
            x /= 10;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```


##### 2. [从一个范围内选择最多整数I](https://leetcode.cn/problems/maximum-number-of-integers-to-choose-from-a-range-i/): `hash`

```CPP
int maxCount(vector<int>& banned, int n, int maxSum) {
    vector<bool> ban(n+1, false);
    for(int b: banned){
        if(b <= n)
            ban[b] = true;
    }
    int ans = 0;
    long long sum = 0;
    for(int i=1; i<=n; i++){
        if(ban[i] == true)
            continue;
        if((long long)sum + i <= maxSum){
            sum += i;
            ans ++;
        }
        else
            break;
    }
    return ans;
}
```


##### 3. [两个线段获得的最多奖品](https://leetcode.cn/problems/maximize-win-from-two-segments/): `滑动窗口`(`同向双指针`) `前后缀数组`

```CPP
int maximizeWin(vector<int>& Pos, int k) {
    int n = Pos.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    // 两个子问题都是: max-min(有序数组的首尾差)<=k的子数组的最大长度  ->  滑动窗口
    int cnt = 0;
    for(int i=0, j=0; i<n; i++){
        cnt++;
        while(j<=i && Pos[i]-Pos[j]>k){
            j++;
            cnt--;
        }
        if(i > 0)
            left[i] = max(left[i-1], cnt);
        else
            left[i] = cnt;
    }
    cnt = 0;
    for(int i=n-1, j=n-1; i>=0; i--){
        cnt++;
        while(j>=i && Pos[j]-Pos[i]>k){
            j--;
            cnt--;
        }
        if(i != n-1)
            right[i] = max(right[i+1], cnt);
        else
            right[i] = cnt;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        // 注意不要让边界点重合
        ans = max(ans, ((i==0) ? 0 : left[i-1]) + right[i]);
    }
    return ans;
}
```


##### 4. [二进制矩阵中翻转最多一次使路径不连通](https://leetcode.cn/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/): `思维题` `DFS`

> 基本思路: 两次`DFS`找到上轮廓和下轮廓, 两者如果相交则返回true, 否则返回`false`
>
> - 第一次**下轮廓`DFS`**, 并将路径标记为不可达`-1`, 如果不可达直接返回`true`
> - 第二次**任意`DFS`**(不需要上轮廓`DFS`), 如果不可达说明两条路径有交集, 返回`true`

```CPP
int m, n;
bool DFS(vector<vector<int>> &g, int x, int y){
    if(x==m-1 && y==n-1)
        return true;
    g[x][y] = 0;
    if(x+1<m && g[x+1][y]==1 && DFS(g, x+1, y))
        return true;
    if(y+1<n && g[x][y+1]==1 && DFS(g, x, y+1))
        return true;
    return false;
}
bool isPossibleToCutPath(vector<vector<int>>& g) {
    m = g.size();
    n = g[0].size();
    return (!DFS(g, 0, 0)) || (!DFS(g, 0, 0));
}
```