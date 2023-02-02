/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
class Solution {
public:
    // 题目: 求去重后的所有排列(去掉一个全空排列)
    int ans = 0;
    void backtrack(string s, vector<bool> &visited, int cur){
        ans++;
        if(cur==s.size()){
            return ;
        }
        for(int i=0; i<s.size(); i++){
            if(i!=0 && !visited[i-1] && s[i]==s[i-1])
                continue;
            if(!visited[i]){
                visited[i] = true;
                backtrack(s, visited, i);
                visited[i] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> visited(tiles.size());
        backtrack(tiles, visited, 0);
        return ans-1;
    }
};
// @lc code=end

