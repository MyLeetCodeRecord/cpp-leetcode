#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 把每种矩阵排列当成一个节点, 用string存储
 * 每个状态作为一个节点, 可以简化为一个字符串 e.g. 12345678x
 * 如果两个状态可以通过移动X一次来得到, 则说明两个节点有边
 */

int direction[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

int BFS(string start, string dest){
    // map存储距离
    unordered_map<string, int> d;  // state -> dest
    d[start] = 0;
    
    // BFS
    queue<string> q;
    q.push(start);
    while(!q.empty()){
        string cur = q.front();
        q.pop();
        // 到达dest
        if(cur==dest)
            return d[cur];
        // 映射回二维坐标(x, y)
        int k = cur.find('x');
        int x = k / 3;
        int y = k % 3;
        // 四个可能的下一步, 放入BFS的queue中
        for(int i=0; i<4; i++){
            // X的下一个位置可以表示为 nextX*3 + nextY
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if(nextX>=0 && nextX<3 && nextY>=0 && nextY<3){
                string nextState = cur;
                swap(nextState[k], nextState[nextX*3 + nextY]);
                // 否则可能重复走同一个格子, 或者需要用一个visit
                if(d.find(nextState) == d.end()){
                    d[nextState] = d[cur] + 1;  // 由cur传递+1, 或者按层遍历, d[nextState]=layer
                    q.push(nextState);
                }
            }
        }
    }
    return -1;
}
int main(){
    string start = "";
    string dest = "12345678x";
    for(int i=0; i<9; i++){
        char ch;
        cin>>ch;
        start += ch;
    }
    cout<<BFS(start, dest)<<endl;
    return 0;
}