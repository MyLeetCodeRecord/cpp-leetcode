/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// @lc code=start
class BSTIterator {
    TreeNode* cur;
    stack<TreeNode*> sk;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    int next() {
        while(cur!=NULL){
            sk.push(cur);
            cur = cur->left;
        }
        cur = sk.top();
        int ans = sk.top()->val;
        sk.pop();
        cur = cur->right;
        return ans;
    }
    bool hasNext() {
        return (cur!=NULL) || (!sk.empty());
    }
};
// @lc code=end

