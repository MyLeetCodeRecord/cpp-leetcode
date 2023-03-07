#### Weekly 335

##### 1. [递枕头](https://leetcode.cn/problems/pass-the-pillow/): `找规律` `math`

> 每个周期是`2*(n-1)`个取值, 又可以分为正向和反向两部分, 分别计算即可

```CPP
    int passThePillow(int n, int time) {
        int direction = time / (n-1);
        if(direction % 2 == 0)
            return 1 + time % (n-1);
        else
            return n - time % (n-1);
    }
```


##### 2. [二叉树中的第 K 大层和](https://leetcode.cn/problems/kth-largest-sum-in-a-binary-tree/): 每次遍历一层的`BFS`

```CPP
long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<long long> ans;
    queue<TreeNode*> q;
    q.push(root);
    int layer = 0;
    while(!q.empty()){
        layer++;
        int _sz = q.size();
        long long sum = 0;
        for(int i=0; i<_sz; i++){
            TreeNode* cur = q.front();
            sum += cur->val;
            q.pop();
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        ans.push_back(sum);
    }
    if(ans.size()<k)
        return -1;
    sort(ans.begin(), ans.end());
    return ans[ans.size()-k];
}
```

##### 3. [分割数组使乘积互质](https://leetcode.cn/problems/split-the-array-to-make-coprime-products/): 

> 麻...原来隐藏用例是`[1]`(长度为1的数组)
>
> 其实并不是因为需要特判, 问题出在最后的循环 `i<=nums.size()-2`这里, `nums.size()`是`unsigned`, 运算后变成负数的话好像是`MAX`
> 
> 换个角度, 但凡用`int len=nums.size()`存一下也不至于...

```CPP
// 周赛答案
int findValidSplit(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> primeMp;
    // 对每个nums[i]分解质因数
    for(int x=0; x<nums.size(); x++){
        int n = nums[x];
        for(int i=2; i<=n/i; i++){
            if(n % i==0){
                while(n % i==0)
                    n /= i;
                mp[x].push_back(i);
                primeMp[i] = x;
            }                
        }
        if(n > 1){
            mp[x].push_back(n);
            primeMp[n] = x;
        }
    }
    // 跳跃游戏
    int cover = 0;
    for(int i=0; i<=(int)nums.size()-2; i++){
        for(int p: mp[i])
            cover = max(cover, primeMp[p]);
        if(cover <= i)
            return i;
    }
    return -1;
}
```

> [灵神做法](https://www.bilibili.com/video/BV1SN411c7eD/?spm_id_from=333.337.search-card.all.click&vd_source=e60de8162f155cdd464b9f11c355e633): 记录每个`prime`最左/最右出现位置 => 区间列表 => [合并区间](https://leetcode.cn/problems/merge-intervals/) / [跳跃游戏](https://leetcode.cn/problems/jump-game/)
>
> - 两个数组
>   - `left`存左端点 (key为prime值)
>   - `right`存右端点 (key为left[i], 这个好离谱)
> 
> 于是区间表示为`<x, right[x]>`了, 然后可以按合并区间中开启下一个区间的条件 => `x > ed`, 即可找到一个分界点作为答案

```CPP
int findValidSplit(vector<int> &nums) {
    unordered_map<int, int> left; // left[p] 表示质数 p 首次出现的下标
    int n = nums.size(), right[n]; // right[i] 表示左端点为 i 的区间的右端点的最大值
    memset(right, 0, sizeof(right));
    auto f = [&](int p, int i) {
        auto it = left.find(p);
        if (it == left.end())
            left[p] = i; // 第一次遇到质数 p
        else
            right[it->second] = i; // 记录左端点 l 对应的右端点的最大值
    };

    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        for (int d = 2; d * d <= x; ++d) { // 分解质因数
            if (x % d == 0) {
                f(d, i);
                for (x /= d; x % d == 0; x /= d);
            }
        }
        if (x > 1) f(x, i);
    }

    for (int l = 0, max_r = 0; l < n; ++l) {
        if (l > max_r) // 最远可以遇到 max_r
            return max_r; // 也可以写 l-1
        max_r = max(max_r, right[l]);
    }
    return -1;
}
```


##### 4. [获得分数的方法数](https://leetcode.cn/problems/number-of-ways-to-earn-points/): `多重背包`

> 一道标准的多重背包问题, 最大价值换成方法数, 循环结构不变, 转移方程稍有变化
> 
> 明早写一下多重背包的二进制优化

```CPP
int waysToReachTarget(int C, vector<vector<int>>& types) {
    vector<long long> dp(C+1, 0);
    dp[0] = 1;
    for(int i=0; i<types.size(); i++){
        for(int j=C; j>=0; j--){
            for(int k=1; k<=types[i][0]; k++){
                if(j>=k*types[i][1])
                    dp[j] += dp[j-k*types[i][1]];
                    dp[j] %= 1000000007;
            }
        }
    }
    return dp[C];
}
```