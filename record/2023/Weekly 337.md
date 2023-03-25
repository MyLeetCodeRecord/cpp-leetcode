#### Weekly 337

##### 1. [奇偶位数](https://leetcode.cn/problems/number-of-even-and-odd-bits/): `bit`

```CPP
vector<int> evenOddBit(int n) {
    vector<int> cnt(2, 0);
    int bit = 0;
    while(n != 0){
        if(n % 2 == 1)   
            cnt[bit % 2]++;
        bit++;
        n >>= 1;
    }
    return cnt;
}
```


##### 2. [检查骑士巡视方案](https://leetcode.cn/problems/check-knight-tour-configuration/): `DFS`

###### 方法一: `DFS`
> 八个方向的`DFS`, 只需要向`cur+1`递归, 
>
> 💣: 左上角出发, `A[0][0]`必须是`0`

```CPP
int dirs[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},
                  {2,1},{2,-1},{-2,1},{-2,-1}};
bool DFS(vector<vector<int>> &A, int x, int y, int cur){
    int n = A.size();
    if(cur+1 == n * n)
        return true;
    for(int i=0; i<8; i++){
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(A[nx][ny] == cur+1)
                return DFS(A, nx, ny, cur+1);
        }
    }
    return false;
}
bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    if(grid[0][0] != 0)
        return false;
    return DFS(grid, 0, 0, 0);
}
```

###### 方法二: `预处理`
> 预处理每个step对应的pos, 然后顺序检查相邻步骤是否满足knight的行进规则
>
> 行进规则判断: `分开判断` or `dx * dy == 2` or `dx^2 + dy^2 == 5`

```CPP
bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int,int>> pos(n*n+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            pos[grid[i][j]] = {i, j};
        }
    }
    if(pos[0].first!=0 || pos[0].second!=0)
        return false;
    for(int i=1; i<n*n; i++){
        int deltaX = abs(pos[i].first-pos[i-1].first);
        int deltaY = abs(pos[i].second-pos[i-1].second);
        if(deltaX * deltaY != 2)
            return false;
    }
    return true;
}
```


##### 3. [美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets/): `回溯`
> [子集型回溯](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%9B%9E%E6%BA%AF%E6%B3%95.md#4-%E5%AD%90%E9%9B%86%E9%97%AE%E9%A2%98), 周赛的时候过分纠结空集了, 其实最后减掉 1 就可以了

```CPP
int path[2010];
int ans = 0;
void backtrack(vector<int>& nums, int cur, int k){
    ans++;
    if(cur==nums.size())
        return ;
    for(int i=cur; i<nums.size(); i++){
        if(path[nums[i]+k]==0 && (nums[i]-k<0 || path[nums[i]-k]==0)){
            path[nums[i]]++;
            backtrack(nums, i+1, k);
            path[nums[i]]--;
        }
    }
}
int beautifulSubsets(vector<int>& nums, int k) {
    backtrack(nums, 0, k);
    return ans - 1;
}
```


##### 4. [执行操作后的最大MEX](https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/): `math` `同余分组`

> 每个数能操作任意次数, 直觉 => 取余到`[0, k-1]`
>
> 对每个余数计数, 看正好能分多少组`group = min{cnt[i]}`
>
> 找`group`的过程中, 每次更新`group`的余数`i`就是「短板`minIdx`」
>
> 返回`group * k + minIdx`

```CPP
int findSmallestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> cnt(k, 0);
    for(int i=0; i<n; i++){
        cnt[(nums[i] % k + k) % k]++;
    }
    int group = cnt[0];
    int minIdx = 0;
    for(int i=0; i<k; i++){
        if(cnt[i] < group){
            group = min(group, cnt[i]);
            minIdx = i;
        }
    }
    return group*k + minIdx;
}
```