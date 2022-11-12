class Solution {
public:
    vector<string> ans;
    string path;
    void backtrack(string s, vector<bool>& visit){
        if(path.size() == s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=0; i<s.size(); i++){
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if(i>0 && s[i]==s[i-1] && visit[i-1]==false)
                continue;
            if(!visit[i]){
                visit[i] = true;
                path.push_back(s[i]);
                backtrack(s, visit);
                visit[i] = false;
                path.pop_back();
            }
        }
    }
    vector<string> permutation(string s) {
        vector<bool> visit(s.size(), false);
        sort(s.begin(), s.end());   // 同一层去重问题 - 必须先排序
        backtrack(s, visit);
        return ans;
    }
};