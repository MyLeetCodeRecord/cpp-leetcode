/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
public:
    // 思路一: 构建dict, 定义一个比较规则 cmp, 逐个比较相邻单词
    // 思路二: 构建Trie, 过程中确保遍历节点or创建节点时没有大于它的字母(当前节点的child列表)被激活过...麻烦到懒得写

    // 规则 1: 字母表顺序
    // 规则 2: apples < apple => 长度越短的越小
    bool cmp(map<char, int> &dict, string &l, string &r){
        for(int i=0; i<min(l.size(), r.size()); i++){
            if(dict[l[i]] < dict[r[i]])
                return true;
            if(dict[l[i]] > dict[r[i]])
                return false;
        }
        return l.size() <= r.size();    //["hello","hello"]
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> dict;
        for(int i=0; i<order.size(); i++)   // 应该没有不合法字符吧
            dict[order[i]] = i;
        for(int i=0; i<words.size()-1; i++){
            if(cmp(dict, words[i], words[i+1])==false)
                return false;
        }
        return true;
    }
};
// @lc code=end

