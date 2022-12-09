/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

// @lc code=start
class CBTInserter {
public:
    vector<TreeNode*> ct;
    int idx = 0;

    CBTInserter(TreeNode* root) {
        ct.resize(11010);
        BFS(root);
    }
    void BFS(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int layer_size = q.size();
            for(int i=0; i<layer_size; i++){
                TreeNode* cur = q.front();
                ct[++idx] = cur;
                q.pop();
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
        }
    }
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        ct[++idx] = node;
        if(idx & 1)
            ct[idx/2]->right = node;
        else
            ct[idx/2]->left = node;
        return ct[idx/2]->val;
    }
    TreeNode* get_root() {
        return ct[1];
    }
};
// @lc code=end

