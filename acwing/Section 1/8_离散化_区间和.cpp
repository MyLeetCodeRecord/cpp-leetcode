#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 离散化:
 * 对所有使用到的下标(x, l, r)离散化, 包括add和query两类操作涉及的下标
 * 建立一个原数组vi到离散化数组a中位置的二分查找方式
 * 然后对离散化的数组构建前缀和
 */

typedef pair<int, int> PII;

const int N = 300010;   // x, l, r
vector<PII> add, query;
vector<int> vi;
int a[N], prefixSum[N];
int n, m, x, c, l, r;

// 离散化Step 2: find()对vi进行二分查找
int find(int target){
    int l = 0;
    int r = vi.size()-1;
    while(l < r){
        int mid = (l + r)/2;
        if(vi[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &c);
        add.push_back({x, c});
        vi.push_back(x);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &l, &r);
        query.push_back({l, r});
        vi.push_back(l);        // l, r也要加入vi, 只不过不会在a[lPos]和a[rPos]上加值而已
        vi.push_back(r);
    }
    // 离散化Step 1: 排序+去重
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    // 离散化Step 3: 构建离散化数组a[]
    for(PII pii : add){
        int apos = find(pii.first) + 1;  // 方便前缀和从1开始
        a[apos] += pii.second;
    }
    // 构建前缀和
    for(int i=1; i<=(int)vi.size(); i++){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    // 执行query
    for(PII pii : query){
        int aLeftPos = find(pii.first) + 1;  // 前缀和从1开始
        int aRightPos = find(pii.second) + 1;
        printf("%d\n", prefixSum[aRightPos] - prefixSum[aLeftPos-1]);
    }
    return 0;
}