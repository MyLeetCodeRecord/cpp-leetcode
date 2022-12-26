/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 */

// @lc code=start
class Solution {
public:
    // 同Weekly325第三题: 礼盒的最大甜蜜度, 二分查找gap, 利用贪心性质check
    // 如果有多个满足条件的gap, 应该取区间内最右的一个 => 用right模板

    // 二分查找: 枚举的是「GAP」
    int maxDistance(vector<int>& position, int k) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = position.back() - position[0];
        while(l < r){
            int mid = (l+r+1)/2;
            if(check(position, mid, k)==false)
                r = mid-1;
            else
                l = mid;
        }
        return l;
    }
    // 贪心: 一旦与上一个选中元素的距离小于等于gap, 就取这个糖果
    bool check(vector<int>& position, int gap, int k){
        int cnt = 1;
        int pre = position[0];
        for(int i=1; i<position.size(); i++){
            if(cnt >= k)
                return true;
            if(position[i]-pre >= gap){
                pre = position[i];
                cnt++;
            }
        }
        return cnt >= k;
    }
};
// @lc code=end

