/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 */

// @lc code=start
class Solution {
public:
    // 分别InOrder获得有序序列, 然后归并
    void InOrder(TreeNode* root, vector<int>& vi){
        if(root==NULL)
            return ;
        InOrder(root->left, vi);
        vi.push_back(root->val);
        InOrder(root->right, vi);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> in1, in2, ans;
        InOrder(root1, in1);
        InOrder(root2, in2);
        int index1 = 0;
        int index2 = 0;
        while(index1<in1.size() && index2<in2.size()){
            if(in1[index1] <= in2[index2]){
                ans.push_back(in1[index1++]);
            }
            else{
                ans.push_back(in2[index2++]);
            }
        }
        if(index1 != in1.size()){
            for(int i=index1; i<in1.size(); i++){
                ans.push_back(in1[index1++]);
            }
        }
        if(index2 != in2.size()){
            for(int i=index2; i<in2.size(); i++){
                ans.push_back(in2[index2++]);
            }
        }
        return ans;
    }
};
// @lc code=end

