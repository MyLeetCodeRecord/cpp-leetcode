/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
 */

// @lc code=start
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->val==0 || root->val==1)
            return root->val;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        if(root->val == 2)
            return l | r;
        if(root->val == 3)
            return l & r;
        return true;
    }
};
// @lc code=end

