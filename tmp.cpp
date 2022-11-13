int layerOrder(TreeNode* root){
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int fixsize = q.size();
        vector<int> layer;
        for(int i=0; i<fixsize; i++){
            TreeNode* cur = q.front();
            layer.push_back(cur->val);
            q.pop();
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        map<int, int> mp;
        // 这里只是把key加进去, val后面还会更新
        for(int i=0; i<layer.size(); i++){
            mp[layer[i]] = i;
        }
        // 更新value为"layer[i]应在的正确位置"
        int idx = 0;
        for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
            it->second = idx++;
        }
        int cnt = 0;
        for(int i=0; i<layer.size(); ){
            if(i == mp[layer[i]]){
                i++;
                continue;
            }
            else{
                swap(layer[i], layer[mp[layer[i]]]);
                cnt++;
            }
        }
        ans += cnt;
    }
    return ans;
}