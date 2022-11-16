#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int,int> PII;

const int N = 100010;
PII intervals[N];

int main(){
    int start, ed, n;
    scanf("%d %d", &start, &ed);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals + n);   // 按左端点排序
    int cnt = 0;
    bool exist = false;
    for(int i=0; i<n; i++){
        // 双指针
        int j = i;
        int localCover = INT_MIN;
        while(j<n && intervals[j].first<=start){
            localCover = max(localCover, intervals[j].second);
            j++;
        }
        if(localCover < start){
            cnt = -1;
            break;
        }
        else{
            cnt++;
            start = localCover;
            if(start >= ed){
                exist = true;
                break;
            }
        }
        i = j - 1;
    }
    // 为什么需要exist?
    // 比如一个[start, +∞]的case, 右边界到不了, 但i已经遍历结束了
    if(exist)
        cout<<cnt<<endl;
    else
        cout<<"-1"<<endl;
    return 0;
}