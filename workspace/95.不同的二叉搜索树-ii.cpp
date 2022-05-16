/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
class Solution {
public:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> ans;
        // 分治(递归)终点
        // 如果是叶子节点, 则rightTrees和leftTrees可能为空, 导致不能收录degree=1的节点
        if(start>end){
            return {NULL};
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftTrees = generate(start, i-1);
            vector<TreeNode*> rightTrees = generate(i+1, end);
            for(TreeNode* l : leftTrees){
                for(TreeNode* r: rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
// @lc code=end

