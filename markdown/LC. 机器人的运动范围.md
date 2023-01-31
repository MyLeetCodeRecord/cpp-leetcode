#### 机器人的运动范围: `DFS` ➕ `找规律`

> 题目描述: https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
>
> 并且根据下图发现, 只向右&向下两个方向DFS即可
> 
> ![机器人的运动范围](/appendix/%E6%9C%BA%E5%99%A8%E4%BA%BA%E7%9A%84%E8%BF%90%E5%8A%A8%E8%8C%83%E5%9B%B4.png)
>
> 同时, 通过上图可以发现, 只看「数位和<=k」这一条件, 每次DFS的左上端点应该都是「进位」位置上取到的
> 
> 如果不要求从`(0,0)`出发, 只关注「数位和<=k」这个性质, 是可以利用「进位」这个特点的
>
> 但这个题中, 黄色区域是不满足条件的, 只需要`DFS(0,0)`就可以了

```CPP
    int mm, nn;
    int getBitSum(int x){
        int ans = 0;
        while(x != 0){
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int DFS(vector<vector<bool>> &visited, int r, int c, int k){
        if(r<0 || r>=mm || c<0 || c>=nn || visited[r][c]==true || getBitSum(r) + getBitSum(c)>k)
            return 0;
        visited[r][c] = true;
        int cnt = 1;
        cnt += DFS(visited, r+1, c, k);
        cnt += DFS(visited, r, c+1, k);
        return cnt;
    }
    int movingCount(int m, int n, int k) {
        mm = m;
        nn = n;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 必须从(0,0)开始移动
        return DFS(visited, 0, 0, k);
    }
```

https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/