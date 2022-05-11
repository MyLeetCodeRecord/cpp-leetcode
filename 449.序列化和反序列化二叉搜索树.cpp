/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
class Codec {
public:
    // 生成一个pre/post序列
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        // 写个迭代preOrder玩儿
        vector<int> pre;
        stack<TreeNode*> sk;
        sk.push(root);
        while(!sk.empty()){
            TreeNode* cur = sk.top();
            sk.pop();
            pre.push_back(cur->val);
            if(cur->right != NULL)
                sk.push(cur->right);
            if(cur->left != NULL)
                sk.push(cur->left);
        }
        string ans = "";
        for(int i=0; i<pre.size(); i++){
            ans += (to_string(pre[i])+",");
        }
        return ans;
    }
    // pre + in
    TreeNode* build(vector<int> pre, vector<int> in, int preL, int preR, int inL, int inR){
        if(preL >= preR)
            return NULL;
        TreeNode* root = new TreeNode(pre[preL]);
        int leftLen = inL;
        for(leftLen=inL; leftLen<inR; leftLen++){
            if(in[leftLen]==pre[preL])
                break;
        }
        leftLen -= inL;
        root->left = build(pre, in, preL+1, preL+leftLen+1, inL, inL+leftLen);
        root->right = build(pre, in, preL+leftLen+1, preR, inL+leftLen+1, inR);
        return root;
    }
    // BST中序有序, pre/post + in => 唯一一棵树
    TreeNode* deserialize(string data) {
        vector<int> pre;
        for(int preComma=0, i=0; i<data.size(); i++){
            if(data[i]==','){
                pre.push_back(stoi(data.substr(preComma, i-preComma)));
                preComma = i+1;
            }
        }
        vector<int> in = pre;
        sort(in.begin(), in.end());
        return build(pre, in, 0, pre.size(), 0, in.size());
    }
};

// @lc code=end

