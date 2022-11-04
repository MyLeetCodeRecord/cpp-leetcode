/*
 * @lc app=leetcode.cn id=1620 lang=cpp
 *
 * [1620] 网络信号最好的坐标
 */

// @lc code=start
class Solution {
public:
    // 枚举: 数据范围很小, 50^50个坐标, 每个坐标最多累计50次信号量 => O(10^6)
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        // 不管是不是缩小边界, (Cx, Cy)一定在towers围成的外接矩形中(平行于坐标轴的"外接矩形")
        // 如果想缩小边界, 可以求一下上下左右4个max
        
        // 遍历坐标时要注意字典序
        double maxSignal = 0;
        int ansX = 0;
        int ansY = 0;
        for(int x=0; x<=50; x++){
            for(int y=0; y<=50; y++){
                int signal = 0;
                // !!! 这里的 & 会节省十几倍的时间...
                for (vector<int> &tower : towers) {
                    // 注意这里是圆形, 而且尽量用平方值进行比较, 得到可达性
                    int squaredDistance = (tower[0]-x)*(tower[0]-x) + (tower[1]-y)*(tower[1]-y);
                    if (squaredDistance <= radius * radius) {
                        double distance = sqrt((double)squaredDistance);
                        signal += floor((double)tower[2] / (1 + distance));
                    }
                }
                if (signal > maxSignal) {
                    ansX = x;
                    ansY = y;
                    maxSignal = signal;
                }
            }
        }
        return {ansX, ansY};
    }
};
// @lc code=end

