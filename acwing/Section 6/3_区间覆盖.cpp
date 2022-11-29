#include <cstdio>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 100010;
PII intervals[N];

int main(){
    int n, start, ed;
    scanf("%d %d", &start, &ed);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals+n);   // 左端点排序
    int cnt = 0;
    bool exist = false;
    for(int i=0; i<n; i++){
        // 双指针 => 找到first<start, 能延伸到最远的j
        int j = i;
        int localCover = INT_MIN;   // 不要直接赋值为intervals[i].second, 因为可能first并不小等于start
        while(j<n && intervals[j].first <= start){
            localCover = max(localCover, intervals[j].second);
            j++;
        }
        // 如果甚至不能到start => 不存在结果
        if(localCover < start){
            exist = false;
            break;
        }
        // 计数, 更新start(cover), 并比较是否到达ed
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
    if(exist)
        printf("%d\n", cnt);
    else
        printf("-1\n");
    return 0;
}