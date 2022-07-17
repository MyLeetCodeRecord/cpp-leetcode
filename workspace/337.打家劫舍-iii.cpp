/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
class Solution {
public:
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
        // 2. don't rob root
        int not_rob_root = rob(root->left) + rob(root->right);
        dp[root] = max(rob_root, not_rob_root);
        return dp[root];
    }
};
// @lc code=end

