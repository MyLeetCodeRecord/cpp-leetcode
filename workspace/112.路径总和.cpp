/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

// @lc code=start
class Solution {
public:
    bool ans = false;
    int sum = 0;
    void backtrack(TreeNode* root, int targetSum){
        // 可能有负数, 不要用sum来做剪枝或者作为return条件
        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum){
                ans = true;
            }
            return ;
        }
        if(root->left!=NULL){
            sum += root->left->val;
            backtracking(root->left, targetSum);
            sum -= root->left->val;
        }
        if(root->right!=NULL){
            sum += root->right->val;
            backtracking(root->right, targetSum);
            sum -= root->right->val;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        sum += root->val;
        backtrack(root, targetSum);
        return ans;
    }
};
// @lc code=end

