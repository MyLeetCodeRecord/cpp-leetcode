/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    TreeNode* build(vector<PII> &nodes, int l, int r){
        if(l > r)
            return NULL;
        TreeNode* root = new TreeNode(nodes[l].first);
        // 两个child如果存在, 应该刚好位于layer+1层
        int curLayer = nodes[l].second;
        int l1 = -1;
        if(l+1 <= r && nodes[l+1].second == curLayer+1){
            l1 = l+1;
        }
        int l2 = -1;
        for(int i=l+2; i<=r; i++){
            if(nodes[i].second == curLayer+1){
                l2 = i;
                break;
            }
        }
        if(l1 != -1){
            int r1 = (l2==-1) ? r : l2-1;
            root->left = build(nodes, l1, r1);
        }
        if(l2 != -1)
            root->right = build(nodes, l2, r);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        vector<PII> nodes;
        int cnt = 0;
        for(int i=0; i<traversal.size(); i++){
            if(traversal[i]=='-')
                cnt++;
            else{
                int num = 0;
                int j = i;
                while(traversal[j]>='0' && traversal[j]<='9'){
                    num = num*10 + (traversal[j]-'0');
                    j++;
                }
                nodes.push_back({num, cnt});
                cnt = 0;
                i = j-1;
            }
        }
        return build(nodes, 0, nodes.size()-1);
    }
};
// @lc code=end

