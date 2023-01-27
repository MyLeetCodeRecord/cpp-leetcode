/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start
class Solution {
public:
    // DFS到当前节点时, 需要用到前面的信息, 因此需要作为参数传进来
    int DFS(TreeNode* root, int preSum){
        if(root==NULL)
            return 0;
        int sum = preSum*10 + root->val;
        if(root->left==NULL && root->right==NULL)
            return sum;
        return DFS(root->left, sum) + DFS(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
};
// @lc code=end

