/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
    typedef pair<long long, int> PII;
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly;
        ugly.push_back(1);
        // 第一维(排序维度)一定是prime * idx
        // 第二维是idx
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(int i=0; i<primes.size(); i++){
            pq.push({primes[i], 0});
        }
        while(ugly.size() < n){
            PII t = pq.top();
            pq.pop();
            int minVal = t.first;
            int idx = t.second;
            int prime = minVal / ugly[idx];
            if(minVal != ugly.back())
                ugly.push_back(minVal);
            pq.push({(long long)prime * ugly[idx+1], idx+1});

        }
        return ugly.back();
    }
};
// @lc code=end

