/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string word: wordList){
            st.insert(word);
        }
        if(st.find(endWord)==st.end())
            return 0;
        // 单向BFS
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int step = 0;
        while(!q.empty()){
            step++;
            int _size = q.size();
            for(int i=0; i<_size; i++){
                string cur = q.front();
                if(cur == endWord)
                    return step;
                q.pop();
                for(int j=0; j<cur.size(); j++){
                    for(int k=0; k<26; k++){
                        string t = cur;
                        t[j] = 'a' + k;
                        // 转移条件: 在wordList中  &  没访问过
                        if(st.find(t)!=st.end() && visited.find(t)==visited.end()){
                            visited.insert(t);
                            q.push(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

