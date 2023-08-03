/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
class Solution {
public:
    string ans = "";
    void preOrder(TreeNode* root){
        ans += to_string(root->val);
        if(root->left==NULL && root->right==NULL)
            return ;
        if(root->left!=NULL){
            ans += "(";
            preOrder(root->left);
            ans += ")";
        }
        if(root->right!=NULL){
            if(root->left==NULL)
                ans += "()";
            ans += "(";
            preOrder(root->right);
            ans += ")";
        }
    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};
// @lc code=end

