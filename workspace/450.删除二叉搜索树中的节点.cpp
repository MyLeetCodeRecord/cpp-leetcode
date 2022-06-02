/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        if(root==NULL)
            return NULL;
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. 不存在
        if(root==NULL)
            return NULL;
        if(root->val == key){
            // 2. 叶子结点
            if(root->left==NULL && root->right==NULL){
                root = NULL;
            }
            // 3. 只有一个child
            else if(root->left!=NULL && root->right==NULL){
                root = root->left;
            }
            else if(root->left==NULL && root->right!=NULL){
                root = root->right;
            }
            // 4. 有两个children
            else{
                TreeNode* min = findMin(root->right);
                root->right = deleteNode(root->right, min->val);
                root->val = min->val;
            }
        }
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

// @lc code=end

