/*
 * @lc app=leetcode.cn id=1668 lang=cpp
 *
 * [1668] 最大重复子字符串
 */

// @lc code=start
class Solution {
public:
    /* 注意到字符串长度不超过 100
     * 直接从大到小枚举 word 的重复次数 k, 判断 word 重复该次数后是否是 sequence 的子串
     * 是则直接返回当前的重复次数 k */
    int maxRepeating(string sequence, string word) {
        string key = word;
        int cnt = 0;
        // 检查存在性即可 => find(k*key)
        while (sequence.find(key) != string::npos) {
            key += word;  // 扩充用于搜索的key, 相当于将key重复k次
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

