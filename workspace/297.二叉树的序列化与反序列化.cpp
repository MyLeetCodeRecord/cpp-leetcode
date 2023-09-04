/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;
        while(getline(ss, item, ',')) 
            q.push(item);
        return helper(q);
    }
    TreeNode* helper(queue<string>& q) {
        string val = q.front();
        q.pop();
        if(val == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = helper(q);
        root->right = helper(q);
        return root;
    }
};
// @lc code=end

