/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    // 首先可以用[LC392.判断子序列]的做法, 超不超时就不知道了
    // 方法一: 分桶
    // 将单词放到首字母对应对桶中
    // 匹配后, 下一个字母作为首字母, 移动到新的桶中
    // 对于匹配完的单词, 计数到ans即可
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<queue<string> > buckets(26, queue<string>());
        // 初始化buckets
        for(string w: words){
            buckets[w[0]-'a'].push(w);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            auto &q = buckets[s[i]-'a'];
            int _size = q.size();
            for(int i=0; i<_size; i++){
                string w = q.front();
                q.pop();
                if(w.size()==1){
                    cnt++;
                    continue;
                }
                else if(w.size() > 1){
                    w = w.substr(1);
                    buckets[w[0]-'a'].push(w);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

