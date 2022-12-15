/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
struct Trie{
    int val;
    int len;
    Trie* child[26];
    Trie(){
        val = 0;
        len = 0;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};
class MapSum {
private:
    Trie* trie;
public:
    MapSum() {
        trie = new Trie();
    }
    void insert(string key, int val) {
        Trie* t = trie;
        for(char ch: key){
            if(t->child[ch-'a']==NULL)
                t->child[ch-'a'] = new Trie();
            t = t->child[ch-'a'];
        }
        t->val = val;
        t->len = key.size();
    }
    int dfs(Trie* t){
        int ans = 0;
        for(int i=0; i<26; i++){
            if(t->child[i] != NULL){
                ans += (t->child[i]->val);
                ans += dfs(t->child[i]);
            }
        }
        return ans;
    }
    int sum(string prefix) {
        Trie* t = trie;
        int ans = 0;
        for(char ch: prefix){
            if(t->child[ch-'a']==NULL)
                return ans;
            // 确保是前缀, 如果不判断, 更短的单词val也会计入ans
            if(t->child[ch-'a']->len >= prefix.size())
                ans += t->child[ch-'a']->val;
            t = t->child[ch-'a'];
        }
        ans += dfs(t);
        return ans;
    }
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

