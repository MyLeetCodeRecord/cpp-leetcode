/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        for (int i = 0; i < order.size(); ++i) {
            val[order[i] - 'a'] = i + 1;
        }
        // 匿名函数
        sort(s.begin(), s.end(), [&](char c0, char c1) {
            return val[c0 - 'a'] < val[c1 - 'a'];
        });
        return s;
    }
};
/* 不会匿名函数的话
// 要定义在类外边
map<char, int> m;

bool cmp(char a, char b) {
    return m[a] < m[b];
}

class Solution {
public:
    string customSortString(string order, string s) {
        int idx = 0;
        for (auto c : order) {
            m[c] = idx++;
        }
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
 */
// @lc code=end

