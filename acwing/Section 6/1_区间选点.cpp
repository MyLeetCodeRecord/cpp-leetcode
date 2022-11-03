#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;
// 按右端点排序
bool static cmp(PII l, PII r){
    if(l.second == r.second)
        return l.first < r.first;
    return l.second < r.second;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<PII> intervals(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int ans = 0;
    int ed = INT_MIN;
    for(int i=0; i<n; i++){
        if(intervals[i].first > ed){
            ed = intervals[i].second;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}