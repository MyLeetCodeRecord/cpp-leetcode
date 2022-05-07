/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    // 两个string节点可达: 字符串差最多一个字符
    bool reachable(string a, string b){
        if(a.size()!=b.size())
            return false;
        int diff=0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i])
                diff++;
        }
        return diff <= 1;
    }
    // 按层BFS
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, bool> visit;
        queue<string> q;
        q.push(start);
        visit[start] = true;
        int ans = INT_MAX;
        int step = 0;
        while(!q.empty()){
            step++;
            // 每次将queue弹空, 表示一层, 也就是一步
            int len = q.size();
            for(int a=0; a<len; a++){
                string top = q.front();
                q.pop();
                for(int i=0; i<bank.size(); i++){
                    if(!visit[bank[i]] && reachable(top, bank[i])){
                        q.push(bank[i]);
                        visit[bank[i]] = true;
                    }
                    // 一旦end被标记为visit了, 则表示到达终点了, 由于是“按层BFS”, 所以出现visit[end]=true的步数一定是所有可能路径中最短的
                    if(visit[end]==true){
                        ans = min(ans, step);
                    }
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
// @lc code=end

