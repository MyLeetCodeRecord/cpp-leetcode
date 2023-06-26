/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
struct Trie {
    bool isEnd;
    vector<Trie *> child;
    Trie() {
        this->child = vector<Trie *>(26, NULL);
        this->isEnd = false;
    }
};
class Solution {
public:
    Trie * trie = new Trie();
    bool static cmp(string l, string r){
        return l.size()<r.size();
    }
    void add(string word) {
        Trie * t = trie;
        for(int i = 0; i < word.size(); i++){
            if (t->child[word[i]-'a'] == NULL) {
                t->child[word[i]-'a'] = new Trie();
            }
            t = t->child[word[i]-'a'];
        }
        t->isEnd = true;
    }
    // 比如 cat, cats, dog, catsdog这个用例
    // - 如果遇到cat就断开重新DFS, 其实是错误结果
    // - 因此即使遇到cat为isEnd, 也要继续向下找, 继续本次DFS
    bool dfs(string word, int cur){
        if(word.size() == cur)
            return true;
        Trie * t = trie;
        for (int i = cur; i < word.size(); i++){
            if(t->child[word[i]-'a'] == NULL)
                return false;
            // 假如断开, dfs(i+1)
            if(t->child[word[i]-'a']->isEnd){
                if(dfs(word, i+1))
                    return true;
            }
            // 不断开
            t = t->child[word[i]-'a'];
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // 按单词长度排序, 长的由短的组成, 所以先放短的
        sort(words.begin(), words.end(), cmp);
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            string word = words[i];
            if(word.size() == 0)
                continue;
            // 这里是if-else, 因为如果长的可以用多个短的表示, 则不需要长的加入Trie了
            if(dfs(word, 0))
                ans.push_back(word);
            else
                add(word);
        }
        return ans;
    }
};
// @lc code=end

