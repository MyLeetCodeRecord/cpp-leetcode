#include <cstdio>
#include <iostream>
#include <priority_queue>
using namespace std;

/* 贪心, 每次选最小质量的两个, 合并后加入待合并果子列表 => 哈夫曼树的思想
 * 因为是列表是动态的, 并且要取最小值, 插入新值并保持顺序 => priority_queue
 * 
 * 另一道合并石子是只能合并相邻两堆, 要用dp[i][j] & prefixSum[]
 */

priority_queue<int> pq;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int fruit;
        scanf("%d", &fruit);
        pq.push(fruit);
    }
    long long ans = 0;
    while(pq.size()>1){
        int a = pq.top();   pq.pop();
        int b = pq.top();   pq.pop();
        pq.push(a+b);
        ans += (a+b);
    }
    cout<<ans<<endl;
    return 0;
}