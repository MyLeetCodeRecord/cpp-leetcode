/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

// @lc code=start
class Solution {
public:
    // 先右后左的中序遍历
    int sum = 0;
    void inOrder(TreeNode* root){
        if(root==NULL)
            return ;
        else{
            inOrder(root->right);
            root->val += sum;
            sum = root->val;
            inOrder(root->left);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        inOrder(root);
        return root;
    }
};
// @lc code=end

