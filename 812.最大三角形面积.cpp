/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 */

// @lc code=start
class Solution {
public:
    // 已知三点坐标, 三角形面积 = (1/2) *abs((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3))
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0.0;
        for(int i=0; i<points.size()-2; i++){
            vector<int> p1 = points[i];
            for(int j=i+1; j<points.size()-1; j++){
                vector<int> p2 = points[j];
                for(int k=j+1; k<points.size(); k++){
                    vector<int> p3 = points[k];
                    double S = abs((p1[0]-p3[0]) * (p2[1]-p3[1]) - (p2[0]-p3[0])*(p1[1]-p3[1]));
                    if(S > ans)
                        ans = S;
                }
            }
        }
        return 0.5*ans;
    }
};
// @lc code=end

