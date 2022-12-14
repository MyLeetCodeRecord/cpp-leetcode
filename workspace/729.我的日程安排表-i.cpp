/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

// @lc code=start
// set + 二分查找(lower_bound)
typedef pair<int, int> PII;
const int INF = 1e9+10;
class MyCalendar {
public:
    set<PII> st;
    MyCalendar() {}
    bool overlap(PII l, PII r){
        if(l.second<=r.first || r.second<=l.first)
            return false;
        return true;
    }
    bool book(int start, int end) {
        st.insert({INF, 0});
        st.insert({-INF, 0});
        auto it = st.lower_bound({start, -INF});
        PII cur = {start, end};
        if(overlap(*it, cur) || overlap(*(--it), cur))
            return false;
        st.insert(cur);
        return true;
    }
};

/* 暴力法
    vector<pair<int, int>> booked;
public:
    bool book(int start, int end) {
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
*/
// @lc code=end

