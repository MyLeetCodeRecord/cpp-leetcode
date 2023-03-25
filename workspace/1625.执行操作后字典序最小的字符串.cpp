/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */

// @lc code=start
class Solution {
public:
    // https://leetcode.cn/problems/lexicographically-smallest-string-after-applying-operations/solution/python3javacgo-yi-ti-shuang-jie-bfs-bao-xl8n2/
    // BFS暴力 / for循环暴力(区分b的奇偶)
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for(int i=0; i<n; i++){
            s = s.substr(n-b) + s.substr(0, n-b);
            for(int j=0; j<10; j++){
                // 枚举对奇数位的修改
                for(int odd=1; odd<n; odd+=2){
                    s[odd] = (s[odd]-'0'+a) % 10 + '0';
                }
                ans = min(ans, s);
                // 如果b为奇数, 也要枚举对偶数的修改
                if(b % 2 == 1){
                    for(int p=0; p<10; p++){
                        for(int even=0; even<n; even+=2){
                            s[even] = (s[even]-'0'+a) % 10 + '0';
                        }
                        ans = min(ans, s);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

