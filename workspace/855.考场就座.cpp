/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
int N;

int dist(const pair<int, int>& p) {
    auto [l, r] = p;
    // 如果包含最左或最右, 是可以坐在最左或最右位置的, 此时距离就是区间长度
    // 如果不包含, 就只能坐在l, r的中间, 所以距离返回一半
    if (l == -1 || r == N) return r - l - 1;
    return (r - l) >> 1;
}
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        int d1 = dist(a), d2 = dist(b);
        return d1 == d2 ? a.first < b.first : d1 > d2;
    };
};
class ExamRoom {
private:
    set<pair<int, int>, cmp> ts;
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    int n;

    void add(pair<int, int> s) {
        ts.insert(s);
        left[s.second] = s.first;
        right[s.first] = s.second;
    }
    void del(pair<int, int> s) {
        ts.erase(s);
        left.erase(s.second);
        right.erase(s.first);
    }
public:
    ExamRoom(int n) {
        N = n;
        this->n = n;
        add({-1, n});
    }
    int seat() {
        auto s = *ts.begin();
        int p = (s.first + s.second) >> 1;
        if (s.first == -1) {
            p = 0;
        } else if (s.second == n) {
            p = n - 1;
        }
        del(s);
        add({s.first, p});
        add({p, s.second});
        return p;
    }
    void leave(int p) {
        int l = left[p], r = right[p];
        del({l, p});
        del({p, r});
        add({l, r});
    }
};
// @lc code=end
