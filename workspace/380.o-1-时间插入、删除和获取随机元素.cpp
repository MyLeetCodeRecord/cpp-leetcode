/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
const int N = 200010;
class RandomizedSet {
public:
    unordered_map<int, int> mp;
    int list[N], idx=0;

    RandomizedSet() {
    }
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        list[idx] = val;
        mp[val] = idx++;
        return true;
    }
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        int pos = mp[val];
        list[pos] = list[--idx];
        mp[list[pos]] = pos;
        mp.erase(val);
        return true;
    }
    int getRandom() {
        int r = rand() % idx;
        return list[r];
    }
};
// @lc code=end

