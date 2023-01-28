class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1);
        vector<int> indegree(n+1, 0);
        for(vector<int> e: relations){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        int layer = 0;  // 记录层数
        int cnt = 0;    // 记录出现在拓扑序列中的课程数量
        for(int i=1; i<=n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            layer++;
            int _size = q.size();
            for(int i=0; i<_size; i++){
                int cur = q.front();
                cnt++;
                q.pop();
                for(int v: graph[cur]){
                    indegree[v]--;
                    if(indegree[v]==0)
                        q.push(v);
                }
            }
        }
        if(cnt < n)
            return -1;
        return layer;
    }
};