#include <cstdio>
#include <iostream>
#include <priority_queue>
using namespace std;

/* 贪心, 每次选最小质量的两个, 合并后加入待合并石子列表 => 哈夫曼树的思想
 * 因为是列表是动态的, 并且要取最小值, 插入新值并保持顺序 => priority_queue
 * 
 * 另一道合并石子是只能合并相邻两堆, 要用dp[i][j] & prefixSum[]
 */

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int s;
        scanf("%d", &s);
        pq.push(s);
    }
    long long sum = 0;
    for(int i=0; i<n-1; i++){   // 合并n-1次
        int top1 = pq.top();    pq.pop();
        int top2 = pq.top();    pq.pop();
        pq.push(top1 + top2);
    }
    cout<<pq.top()<<endl;
    return 0;
}