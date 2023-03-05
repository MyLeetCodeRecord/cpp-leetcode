#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;
vector<PII> intervals;

// 按区间左端点(开始时间)排序
bool cmp(pair<int,int> l, pair<int,int> r){
    return l.first < r.first;
}
// 区间合并 => 返回方案的写法
// 如果不需要返回方案, 直接用int ed记录右边界即可, 不需要维护curInterval
vector<PII> intervalMerge(vector<PII> intervals){
    vector<PII> ans;
    sort(intervals.begin(), intervals.end(), cmp);  // 默认排序也可以
    PII curInterval = intervals[0];  // curInterval当前维护区间, 也可以初始化为(-∞,-∞)
    for(int i=0; i<intervals.size(); i++){
        // 当前区间维护结束
        if(curInterval.second < intervals[i].first){
            ans.push_back(curInterval);
            curInterval = intervals[i];
        }
        // 继续维护当前区间
        else{
            curInterval.second = max(curInterval.second, intervals[i].second);
        }
    }
    // 最后一个区间
    ans.push_back(curInterval);
    return ans;
}
int main(){
    int n, l, r;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &l, &r);
        intervals.push_back({l,r});
    }
    vector<PII> ans = intervalMerge(intervals);
    cout<<ans.size()<<endl;
    return 0;
}