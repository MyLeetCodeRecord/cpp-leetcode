#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/* 在区间分组 (求分组数量) 的基础上, 需要维护一个group_id维度 */
typedef pair<int, int> PII;

const int N = 50010;
pair<PII, int> cows[N]; // <<l, r>, cow_idx>, 默认按l排序
int id[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &cows[i].first.first, &cows[i].first.second);
        cows[i].second = i;
    }
    sort(cows, cows+n);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i=0; i<n; i++){
        PII cur = cows[i].first;
        // 如果不存在这样的组, 则开启一个新的分组将其放入, 赋予新的ID
        if(heap.empty() || heap.top().first >= cur.first){
            PII stall = {cur.second, heap.size()+1};
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
        // 如果存在这样的组, 则将当前区间放入, 并更新该组的maxR, 组号不变
        else{
            PII stall = heap.top();
            heap.pop();
            stall.first = cur.second;
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
    }
    cout<<heap.size()<<endl;
    for(int i=0; i<n; i++){
        printf("%d\n", id[i]);
    }
    return 0;
}