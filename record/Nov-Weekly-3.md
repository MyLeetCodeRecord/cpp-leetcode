#### Weekly 3

##### 1. [数组中不等三元组的数目](https://leetcode.cn/problems/number-of-unequal-triplets-in-array/): `暴力` `双指针`
> 排序后, 找到每段的重复次数
```CPP
int unequalTriplets(vector<int>& nums) {
    vector<int> vi;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        int j = i;
        int cnt = 0;
        while(j<nums.size() && nums[i]==nums[j]){
            j++;
            cnt++;
        }
        vi.push_back(cnt);
        i = j-1;
    }
    if(vi.size() <= 2)  return 0;
    int n=vi.size();
    int res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                res += vi[i] * vi[j] * vi[k];
            }
        }
    }
    return res;
}
```

##### 2. [二叉搜索树最近节点查询](https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/)
> 思路就是先`中序遍历`求得有序数组`inorder[]`
> 
> 然后在`inorder`上进行二分查找 ➡️ `binary_search_left` & `binary_search_right`两个模板
> 
> 注意查找不到的情况要交换两个结果, 并且边界要置`-1`
> 
> 其实是这两题的融合 ➡️ [LC94. 二叉树的中序遍历💚](https://leetcode.cn/problems/binary-tree-inorder-traversal/) ➕ [LC34. 在排序数组中查找元素的第一个和最后一个位置🧡](/workspace/34.%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.cpp)

```CPP
void dfs(TreeNode* root, vector<int>& ans){
    if(root==NULL)
        return ;
    dfs(root->left, ans);
    ans.push_back(root->val);
    dfs(root->right, ans);
}
int binary_search_left(vector<int>& a, int l, int r, int target){
    while(l<r){
        int mid = (l+r)/2;
        if(a[mid]<target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
int binary_search_right(vector<int>& a, int l, int r, int target){
    while(l<r){
        int mid = (l+r+1)/2;
        if(a[mid]>target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<int> vi;
    dfs(root, vi);
    vector<vector<int>> res;
    for(int q: queries){
        int i = vi[binary_search_left(vi, 0, vi.size()-1, q)];
        int j = vi[binary_search_right(vi, 0, vi.size()-1, q)];
        if(i==q){
            res.push_back({i,j});                
        }
        else{
            if(q<vi[0])
                j = -1;
            if(q>vi.back())
                i = -1;
            res.push_back({j,i});
        }
    }
    return res;
}
```

##### 3. [到达首都的最少油耗](https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/)
> `DFS`的思路先想明白...
> 
> 思路: 到每个点都重新租车, 发车辆 = (汇集到该节点的人数 + seats - 1) / seats (向上取整)

```CPP
long long cost = 0;
// 返回值为以u为根节点的子树size
long long DFS(vector<vector<int>> &graph, int u, int fa, int seats){
    long long _size = 1;
    // 递归获得子树size
    for(int v: graph[u]){
        if(v != fa){    // 树中可以用father代替visit[]数组
            _size += DFS(graph, v, u, seats);
        }
    }
    // 除非是(0, -1)这条边, 其它边都要统计入cost
    if(u != 0){
        cost += (_size + seats - 1) / seats;    // 向上取整
    }
    return _size;
}
long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    int n = roads.size()+1;
    vector<vector<int>> graph(n, vector<int>());
    for(vector<int> r: roads){
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    DFS(graph, 0, -1, seats);
    return cost;
}
```