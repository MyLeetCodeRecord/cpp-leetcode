#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
PII intervals[N];

bool static cmp(PII &l, PII &r){
    return l.second < r.second;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals+n, cmp);
    int cnt = 0;
    int ed = INT_MIN;
    for(int i=0; i<n; i++){
        if(intervals[i].first > ed){
            ed = intervals[i].second;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}