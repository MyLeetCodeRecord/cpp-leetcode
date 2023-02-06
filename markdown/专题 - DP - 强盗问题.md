#### 强盗问题

##### [LC198. 打家劫舍](/workspace/198.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D.cpp)
> `dp[i]`表示第 i 家为止, 能获得的最大金额
> 
> 对于`dp[i]`有抢or不抢`nums[i]`两种情况
> 
> `dp[i] = max(dp[i-1], dp[i-2]+nums[i])`

##### [LC213. 打家劫舍II](/workspace/213.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D-ii.cpp)
> ![LC213](/appendix/LC213.png)


##### [LC337. 打家劫舍III](/workspace/337.%E6%89%93%E5%AE%B6%E5%8A%AB%E8%88%8D-iii.cpp)
> 第一想法用递归DFS, 发现超时

```CPP
// 暴力 DFS - 超时
int rob(TreeNode* root) {
    if(root==NULL)
        return 0;
    int rob_root = root->val;
    if(root->left!=NULL)
        rob_root += rob(root->left->left) + rob(root->left->right);
    if(root->right!=NULL)
        rob_root += rob(root->right->left) + rob(root->right->right);
    int not_rob_root = rob(root->left) + rob(root->right);
    return max(rob_root, not_rob_root);
}
```

> 时间开销主要来源与重复DFS子问题, 因此应该用`记忆化搜索`记住子问题, 减少重复计算
> 
> dp数组的key应该是`TreeNode*`本身, value是从root到该节点能够获得的最大金额

```CPP
// 动态规划 - 记忆化搜索
unordered_map<TreeNode*, int> dp;
int rob(TreeNode* root){
    if(root==NULL)
        return 0;
    if(dp.find(root)!=dp.end()) // 记忆化搜索
        return dp[root];
    // 1. rob root
    int rob_root = root->val;
    if(root->left!=NULL){
        rob_root += rob(root->left->left) + rob(root->left->right);
    }
    if(root->right!=NULL){
        rob_root += rob(root->right->left) + rob(root->right->right);
    }
    // 2. Not rob root
    int not_rob_root = rob(root->left) + rob(root->right);
    
    dp[root] = max(rob_root, not_rob_root);
    return dp[root];
}
```