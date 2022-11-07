#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/* "替换成向右范围更大的区间不亏..."
 * Step 1: 将所有区间按左端点排序
 * Step 2: 从前往后枚举每个区间, 在所有能覆盖`start`的区间中, 选择右端点最大的区间, 将`start`更新成右端点的最大值
 * `A: ...-----x------------....`
 * `B: ......--x------..........`
 * 上面两个区间相比, 两者都能覆盖`start(x)`, 但`A`的覆盖区域更远, 右端点更大, 所以`A`是更优解
 */

typedef pair<int,int> PII;

const int N = 100010;
PII intervals[N];

int main(){
    int st, ed, n;
    scanf("%d %d", &st, &ed);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i].first, &intervals[i].second);
    }
    sort(intervals, intervals + n);   // 按左端点排序
    int cnt = 0;
    int cover = st;
    bool exist = false;
    // 双指针
    for(int i=0; i<n; i++){
        int j = i;
        int localCover = INT_MIN;
        // 检查所有cover范围内的区间的最右值 - localCover
        while(j < n && intervals[j].first <= cover){
            localCover = max(localCover, intervals[j].second);
            j++;
        }
        if(localCover < cover){
            cnt = -1;
            break;
        }
        cnt++;
        if(localCover >= ed){
            exist = true;
            break;
        }
        cover = localCover;
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