/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    int sum = 0;
    void backtracking(TreeNode* root, int targetSum){
        // 到达叶子结点
        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum){
                ans.push_back(path);
            }
            return ;
        }
        // 可能有负数, 不要用sum<=targetSum剪枝
        if(root->left!=NULL){
            sum += root->left->val;
            path.push_back(root->left->val);
            backtracking(root->left, targetSum);
            path.pop_back();
            sum -= root->left->val;
        }
        if(root->right!=NULL){
            sum += root->right->val;
            path.push_back(root->right->val);
            backtracking(root->right, targetSum);
            path.pop_back();
            sum -= root->right->val;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return ans;
        // root需要提前加入path和sum中
        path.push_back(root->val);
        sum += root->val;
        backtracking(root, targetSum);
        return ans;
    }
};
// @lc code=end

