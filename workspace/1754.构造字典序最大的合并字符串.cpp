/*
 * @lc app=leetcode.cn id=1754 lang=cpp
 *
 * [1754] 构造字典序最大的合并字符串
 */

// @lc code=start
class Solution {
public:
    // 双指针 + 不用substr
    bool compare(string& s1, string& s2, int i, int j){
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else
                return s1[i] > s2[j];
        }
        return i!=s1.size();    // !!!
    }
    string largestMerge(string word1, string word2) {
        string ans = "";
        int i = 0;
        int j = 0;
        while(i<word1.size() && j<word2.size()){
            if(compare(word1, word2, i, j))
                ans += word1[i++];
            else
                ans += word2[j++];
        }
        if(i != word1.size())
            ans += word1.substr(i);
        if(j != word2.size())
            ans += word2.substr(j);
        return ans;
    }
};
/*
class Solution {
public:
    // 递归
    string largestMerge(string word1, string word2) {
        if(word1.size()==0)
            return word2;
        if(word2.size()==0)
            return word1;
        if(word1 > word2)
            return word1[0]+largestMerge(word1.substr(1), word2);
        else
            return word2[0]+largestMerge(word1, word2.substr(1));
    }
};
*/
// @lc code=end

