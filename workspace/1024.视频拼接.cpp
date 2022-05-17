/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution {
public:
    bool static cmp(vector<int> &l, vector<int> &r){
        // 起点相同优先选长的
        if(l[0]==r[0])
            return l[1]>r[1];
        return l[0]<r[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        clips.push_back({time, time});
        sort(clips.begin(), clips.end(), cmp);
        int cnt = 0;
        int cover = 0;
        int localCover = cover;
        for(int i=0; i<clips.size(); i++){
            if(cover >= time)
                return cnt;
            if(localCover >= time)
                return cnt+1;
            // 空隙
            if(clips[i][0] > cover){
                // localCover补不上
                if(clips[i][0] > localCover)
                    return -1;
                // localCover补得上
                else{
                    cover = localCover;
                    cnt++;
                }
            }
            if(clips[i][1] > cover){
                localCover = max(localCover, clips[i][1]);
            }
        }
        return -1;
    }
};
// @lc code=end

