/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution {
public:
    bool static cmp(vector<int> &l, vector<int> &r){
        return l[1] > r[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int space = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for(vector<int> box: boxTypes){
            if(box[0] >= truckSize){
                space += truckSize * box[1];
                break;
            }
            else{
                space += box[0] * box[1];
                truckSize -= box[0];
            }
        }
        return space;
    }
};
// @lc code=end

