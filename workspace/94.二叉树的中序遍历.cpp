/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> sk;
        TreeNode* cur = root;
        while(cur!=NULL || !sk.empty()){
            if(cur != NULL){
                sk.push(cur);
                cur = cur->left;
            }
            else{
                cur = sk.top();
                ans.push_back(cur->val);
                sk.pop();
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

