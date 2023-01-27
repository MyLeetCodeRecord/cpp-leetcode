/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR){
        if(preL>=preR || inL>=inR)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preL]);
        int leftLen = 0;
        while(inorder[inL+leftLen] != preorder[preL]){
            leftLen++;
        }
        root->left = build(preorder, inorder, preL+1, preL+leftLen+1, inL, inL+leftLen);
        root->right = build(preorder, inorder, preL+leftLen+1, preR, inL+leftLen+1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n, 0, n);
    }
};
// @lc code=end

