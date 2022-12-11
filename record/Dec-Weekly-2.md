#### Weekly 4
> 其实做完了三题, 提前出去吃烤鱼导致掉分, 而且做题好慢, 前两题就做了二十多分钟...但烤鱼还是很香的
> 
> 虽然掉分, 但好像遇到了好多新知识🐳

##### 1. [删除每行中的最大值](https://leetcode.cn/problems/delete-greatest-value-in-each-row/): `冒泡(模拟)` or `排序`

> **纯模拟➡️三层循环**: 考场上用「模拟」做的, 每次「交换当前行最大值和末尾元素(冒泡)」来标记哪些值已经从数组中删除了, 指针的控制稍微有点麻烦
> 
> **先排序再找列最大值**: 但其实更好的做法是, 先对行数组进行排序, 然后每步最大值的列指针就对齐了, 直接找到列最大值加到`ans`即可

```CPP
// 纯模拟
int deleteGreatestValue(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for(int a=n; a>0; a--){
        int time_max = grid[0][0];
        for(int i=0; i<m; i++){
            int line_max = grid[i][0];
            int max_pos = 0;
            for(int j=0; j<a; j++){
                if(grid[i][j]>line_max){
                    max_pos = j;
                    line_max = grid[i][max_pos];
                }
            }
            time_max = max(time_max, grid[i][max_pos]);
            swap(grid[i][a-1], grid[i][max_pos]);
        }
        ans += time_max;
    }
    return ans;
}
```

```CPP
// 排序做法
int deleteGreatestValue(vector<vector<int>>& grid) {
    // 没加引用&是无法对原数组排序的!!!
    for(vector<int>& line: grid){
        sort(line.begin(), line.end());
    }
    int ans = 0;
    for(int j=0; j<grid[0].size(); j++){
        int max_in_col = grid[0][j];
        for(int i=0; i<grid.size(); i++){
            max_in_col = max(max_in_col, grid[i][j]);
        }
        ans += max_in_col;
    }
    return ans;
}
```


##### 2. [数组中最长的方波](https://leetcode.cn/problems/longest-square-streak-in-an-array/): 
> 不考虑位置(因为可以排序), 
```CPP
int longestSquareStreak(vector<int>& nums) {
    // 子序列且可以排序 => 判断是否出现过即可
    unordered_map<long, int> mp;
    for(int n:nums){
        mp[n]++;
    }
    int ans = 1;
    // 遍历「基数」比遍历「数组元素」更快, 重复更少
    for(int i=2; i<=sqrt(100010); i++){
        int cnt = 0;
        long long x = i;
        while(mp.find(x) != mp.end()){
            x *= x;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    return ans>1 ? ans : -1;
}
```

##### 3. [设计内存分配器](https://leetcode.cn/problems/design-memory-allocator/)
> 第三题一直没移指针(`i = j`), 导致做了半天没弄清楚为什么超时, 还写的是费时的`map`记录`intervals(PII)`的实现方式
> 
> 其实如果不考虑运行时间, 这道题的数据范围使用纯暴力就可以解决, 如果再大一些, 用`map`来记录`mID`对应的所有`PII interval`, 会更省时间一些
> 
> 另外, `vector`可以使用`fill(vi.begin()+start, vi.begin()+end, default_value)`来用默认值填充数组某一段
> 
> ![](/appendix/LC6259.png)

```CPP
typedef pair<int, int> PII;
vector<int> vi;
int _size = 0;
unordered_map<int, vector<PII>> mp; // map记录mID对应的所有intervals

Allocator(int n) {
    vi.resize(n);
    _size = n;
    fill(vi.begin(), vi.end(), 0);  // 0: idle
}
int allocate(int size, int mID) {
    if(size > _size)
        return -1;
    int ans = -1;
    for(int i=0; i<_size; i++){
        if(vi[i]!=0)
            continue;
        // 双指针, 找一段连续idle空间
        int j = i;
        while(j<_size && vi[j]==0){
            j++;
            if(j-i == size){
                ans = i;
                fill(vi.begin()+i, vi.begin()+j, mID);
                mp[mID].push_back({i, j});
                return ans;
            }
        }
        i = j;  // 忘了这句才一直超时...
    }
    return ans;
}
int free(int mID) {
    if(mp.find(mID)==mp.end())
        return 0;
    int ans = 0;
    for(PII interval: mp[mID]){
        int i=interval.first;
        int j=interval.second;
        fill(vi.begin()+i, vi.begin()+j, 0);
        ans += (j-i);
    }
    mp.erase(mID);
    return ans;
}
```