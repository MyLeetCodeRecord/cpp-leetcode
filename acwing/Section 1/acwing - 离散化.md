#### 离散化

##### 1. 去重

```CPP
vector<int> vi;
// 排序
sort(vi.begin(), vi.end());
// 去重, 并去掉末尾剩余元素
vi.erase(unique(vi.begin(), vi.end()), vi.end());
```

> [unique()](https://blog.csdn.net/hhmy77/article/details/82902389): 去重, 但不删除元素, 原数组剩余位置元素未被修改
> 
> `unique`, `sort`接受的是迭代器, 操作对象也是迭代器, 而不是容器本身, 所以这些函数执行时是无法添加或删除容器元素的
> 
> 因此要在取`unique`后返回的迭代器基础上, 继续`erase`末尾元素

```CPP
// 自己实现unique去重
vector<int>::iterator unique(vector<int> &a){
    for(int i=0, j=0; i<a.size(); i++){
        if(i>0 && a[i]!=a[i-1]){
            a[j++] = a[i];  // 覆盖即可, 后面的位置不重要
        }
    }
    // a[0:j-1]是a中所有不同的数
    return a.begin() + j;
}
// 删除末尾元素
vi.erase(unique(vi), vi.end());
```


##### 2. 二分查找离散化的值

> 在**无重复有序数组**中查找`pos`, 不存在重复元素, 所以使用左侧/右侧端点模板都可以, 下面是左端点模板

```CPP
int find(int pos){
    int l = 0;
    int r = vi.size()-1;    // 去重(erase)后的size
    while(l < r){
        int mid = (r-l)/2+l;
        if(vi[mid] < pos)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```


##### 完整实现
```CPP
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;   // x, l, r
vector<PII> add, query;
vector<int> vi;
int a[N], prefixSum[N];
int n, m, x, c, l, r;

// 离散化Step 2: 实现find()对vi进行二分查找
int find(int pos){
    int l = 0;
    int r = vi.size()-1;
    while(l < r){
        int mid = (l + r)/2;
        if(vi[mid] < pos)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}

int main(){
    scanf("%d %d", &n, &m);
    // 将操作和询问中提及的所有pos写入vi数组, 用于排序去重
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
    // 离散化Step 3: 读「操作数组」, 构建离散化数组a[]
    for(PII pii : add){
        int apos = find(pii.first) + 1;  // 方便前缀和从1开始
        a[apos] += pii.second;
    }
    // 构建前缀和数组
    for(int i=1; i<=(int)vi.size(); i++){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }
    // 读「query数组」, 计算前缀和
    for(PII pii : query){
        int aLeftPos = find(pii.first) + 1;  // 前缀和从1开始
        int aRightPos = find(pii.second) + 1;
        printf("%d\n", prefixSum[aRightPos] - prefixSum[aLeftPos-1]);
    }
    return 0;
}
```