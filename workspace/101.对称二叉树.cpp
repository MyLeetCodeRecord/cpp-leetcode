/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
class Solution {
public:
    int getDepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if(l==-1 || r==-1 || abs(l-r) > 1)
            return -1;
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) != -1;
    }
};
// @lc code=end

