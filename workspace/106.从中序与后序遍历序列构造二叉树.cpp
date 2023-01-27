/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

// @lc code=start
class Solution {
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inL, int inR, int postL, int postR){
        if(inL>=inR || postL>=postR)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postR-1]);
        int leftLen = 0;
        while(inorder[inL+leftLen] != postorder[postR-1]){
            leftLen++;
        }
        root->left = build(inorder, postorder, inL, inL+leftLen, postL, postL+leftLen);
        root->right = build(inorder, postorder, inL+leftLen+1, inR, postL+leftLen, postR-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder, 0, n, 0, n);
    }
};
// @lc code=end

