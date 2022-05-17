/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int fIndex = 0;
        int sIndex = 0;
        while(fIndex < firstList.size() && sIndex < secondList.size()){
            int fl = firstList[fIndex][0];
            int fr = firstList[fIndex][1];
            int sl = secondList[sIndex][0];
            int sr = secondList[sIndex][1];
            // 不相交
            if(fl > sr){
                sIndex++;
                continue;
            }
            if(sl > fr){
                fIndex++;
                continue;
            }
            // 相交 (4种情况), 先想好怎么划分情况更少, 别漏掉
            // 边界相等时怎么处理都可以, 但是需要处理, 不然循环没法继续
            if(fl <= sl && fr <= sr){
                ans.push_back({sl, fr});
                fIndex++;
            }
            else if(fl <= sl && fr >= sr){
                ans.push_back({sl, sr});
                sIndex++;
            }
            else if(fl >= sl && fr >= sr){
                ans.push_back({fl, sr});
                sIndex++;
            }
            else if(fl >= sl && fr <= sr){
                ans.push_back({fl, fr});
                fIndex++;
            }
        }
        return ans;
    }
};
// @lc code=end

