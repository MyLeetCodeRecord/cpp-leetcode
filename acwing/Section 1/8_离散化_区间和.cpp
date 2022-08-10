#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 思路: 对所有使用到的下标离散化, 包括add和query两类操作涉及的下标
typedef pair<int, int> PII;

const int N = 300010;
int n, m;
vector<int> vi;
vector<PII> add, query;
int a[N], prefixSum[N];

// find: 在vi中二分查找target离散化后(在数组a[]中)的位置
int find(int target){
    int l = 0;
    int r = vi.size()-1;
    while(l<r){
        int mid = (l+r)/2;
        if(vi[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l+1;  // "+1": 为了求前缀和, 映射到从1开始
}

// 对大范围数据离散化到1~size, 在离散化后的数组上计算PrefixSum
int main(){
    scanf("%d %d", &n, &m);
    int x, c, l, r;
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &c);
        add.push_back({x, c});
        vi.push_back(x);        // 加入需要离散化的下标(add)
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &l, &r);
        query.push_back({l, r});
        vi.push_back(l);        // 加入需要离散化的下标(query)
        vi.push_back(r);
    }
    // 去重
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    // 构建a[]
    for(PII item: add){
        int x = find(item.first);
        a[x] += item.second;
    }
    // 构建前缀和
    for(int i=1; i<=(int)vi.size(); i++){
        prefixSum[i] = a[i] + prefixSum[i-1];
    }
    // m次查询
    for(PII item: query){
        int l = find(item.first);
        int r = find(item.second);
        cout<<prefixSum[r] - prefixSum[l-1]<<endl;
    }
    return 0;
}