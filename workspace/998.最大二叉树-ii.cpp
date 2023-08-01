/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
 */

// @lc code=start
class Solution {
public:
    // 简单想法: 恢复中序序列, 末尾加上val后重新build
    // 但是题目已经要求加在末尾了, 可以直接分类讨论插在哪里
    // 1. root->val < insertVal, 说明是新节点
    // 2. 由于insertVal在数组末尾, 所以应该插入右子树
    //   (1) 如果右子树为空, 直接插入
    //   (2) 如果右子树不为空, 递归插入
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(val > root->val){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if(root->right == NULL){
            root->right = new TreeNode(val);
        }
        else{
            root->right = insertIntoMaxTree(root->right, val);
        }
        return root;
    }
};
// @lc code=end

