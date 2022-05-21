class Solution {
public:
    bool static cmp(vector<int> &l, vector<int> &r){
        if(l[0] == r[0]){
            return l[1] < r[1];
        }
        return l[0] < r[0];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int preEnd = 0;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] < preEnd){
                return false;
            }
            preEnd = intervals[i][1];
        }
        return true;
    }
};