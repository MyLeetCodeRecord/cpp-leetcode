/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
 */

// @lc code=start
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preL, int preR){
        if(preL>=preR)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preL]);
        // left模板
        int l = preL+1, r = preR;
        while(l < r){
            int mid = (l+r)/2;
            if(preorder[mid] < root->val)
                l = mid+1;
            else
                r = mid;
        }
        root->left = build(preorder, preL+1, l);
        root->right = build(preorder, l, preR);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return build(preorder, 0, n);
    }
};
// @lc code=end

