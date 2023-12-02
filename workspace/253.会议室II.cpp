class Solution {
public:
    // [start, end]范围更大的「1094. 拼车」
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for(vector<int> &interval : intervals){
            int l = interval[0], r = interval[1];
            diff[l] += 1;
            diff[r] -= 1;
        }
        int ans = 0;
        int preSum = 0;
        for(auto &[k, v]: diff){
            preSum += v;
            ans = max(ans, preSum);
        }
        return ans;
    }
};