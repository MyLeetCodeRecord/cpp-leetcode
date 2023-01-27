/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
 */

// @lc code=start
class Solution {
    typedef pair<int, int> PII;
public:
    TreeNode* build(vector<PII>& nodes, int l, int r){
        if(l >= r)
            return NULL;
        TreeNode* root = new TreeNode(nodes[l].first);
        int l1 = (l+1<nodes.size() && nodes[l+1].second == nodes[l].second+1) ? l+1: -1;
        int l2 = -1;
        for(int i=l+2; i<r; i++){
            if(nodes[i].second == nodes[l].second+1){
                l2 = i;
                break;
            }
        }
        int r1 = (l2 == -1) ? r : l2;
        int r2 = r;
        if(l1 != -1)
            root->left = build(nodes, l1, r1);
        if(l2 != -1)
            root->right = build(nodes, l2, r2);
        return root;
    }
    TreeNode* recoverFromPreorder(string s) {
        vector<PII> nodes;
        int num = 0;
        int cnt = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                int j = i;
                while(j<s.size() && (s[j]>='0' && s[j]<='9')){
                    num = num * 10 + (s[j]-'0');
                    j++;
                }
                nodes.push_back({num, cnt});
                num = 0;
                cnt = 0;
                i = j - 1;
            }
            else{
                int j = i;
                while(j<s.size() && s[j]=='-'){
                    j++;
                    cnt++;
                }
                i = j - 1;
            }
        }
        return build(nodes, 0, nodes.size());
    }
};
// @lc code=end

