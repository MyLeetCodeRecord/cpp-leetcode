/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    // ans = n - loopNum
    vector<int> father;
    void init(int n){
        father.resize(n);
        for(int i=0; i<n; i++)
            father[i] = i;
    }
    int find(int u){
        if(father[u] != u)
            father[u] = find(father[u]);
        return father[u];
    }
    void union2(int u, int v){
        int fu = find(u);
        int fv = find(v);
        father[fu] = fv;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        init(n);
        // 合并相邻的一对座位
        for(int i=0; i<n; i+=2){
            union2(row[i]/2, row[i+1]/2);
        }
        int loopNum = 0;
        for(int u=0; u<n; u++){
            if(father[u] == u)
                loopNum++;
        }
        return n-loopNum;
    }
};
// @lc code=end

