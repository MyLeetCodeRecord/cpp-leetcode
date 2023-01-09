class Solution {
public:
    int minSwap(vector<int>& arr){
        int n = arr.size();
        // map存储的是元素应该放在的正确位置
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[copy[i]] = i;
        }
        // 找到所有环路
        vector<bool> visited(n, false);
        int loopNum = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                // 遍历一个环, 标记所有节点为visited=true
                int j = i;
                while(!visited[j]){
                    visited[j] = true;
                    j = mp[arr[j]];
                }
                loopNum++;
            }
        }
        return n - loopNum;
    }
    int BFS(TreeNode* root){
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> layer;
            int _size = q.size();
            for(int i=0; i<_size; i++){
                TreeNode* cur = q.front();
                q.pop();
                layer.push_back(cur->val);
                if(cur->left != NULL)
                    q.push(cur->left);
                if(cur->right != NULL)
                    q.push(cur->right);
            }
            ans += minSwap(layer);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        return BFS(root);
    }
};