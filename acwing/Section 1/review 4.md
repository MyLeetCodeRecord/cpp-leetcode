##### 1. quicksort
> `quicksort`, `mergesort`记得**递归终点**=>`if(l>=r)`, 递归都要考虑递归终点

```CPP
void quicksort(int q[], int l, int r){
    if(l >= r)
        return ;
    int x = q[(l+r)/2];
    int i = l - 1;
    int j = r + 1;
    while(i < j){
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j+1, r);
}
```

##### 2. quickselect
```CPP
int quickselect(int q[], int k, int l, int r){
    if(l >= r)
        return q[l];
    int x = q[(l+r)/2];
    int i = l - 1;
    int j = r + 1;
    while(i < j){
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = j - l + 1;
    if(leftCnt >= k)
        return quickselect(q, k, l, j);
    else
        return quickselect(q, k-leftCnt, j+1, r);
}
```

##### 3. mergesort
```CPP
int q[N], tmp[N];

void mergesort(int q[], int l, int r){
    if(l >= r)
        return;
    // 递归
    int mid = (l+r)/2;
    mergesort(q, l, mid);
    mergesort(q, mid+1, r);
    // 合并
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(q[i] <= q[j])
            tmp[idx++] = q[i++];
        else
            tmp[idx++] = q[j++];
    }
    // 剩余
    while(i<=mid)
        tmp[idx++] = q[i++];
    while(j<=r)
        tmp[idx++] = q[j++];
    // 复制回q[]
    for(int a=l; a<=r; a++)
        q[a] = tmp[a];
}
```

##### 4. mergesort(逆序对的数量)
```CPP
long long mergesort(int q[], int l, int r){
    if(l<=r)
        return 0;
    int mid = (l+r)/2;
    long long sum = mergesort(q, l, mid) + mergesort(q, mid+1, r);
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        // 逆序对统计: 遇到待弹出的q[j]
        if(q[j] < q[i]){
            sum += (mid-i+1);
            tmp[idx++] = q[j++];
        }
        else{
            tmp[idx++] = q[i++];
        }
    }
    while(i<=mid)
        tmp[idx++] = q[i++];
    while(j<=r)
        tmp[idx++] = q[j++];
    for(int i=l; i<=r; i++)
        q[i] = tmp[i];
    return sum;
}
```

##### 5. binarysearch
```CPP
// 满足条件的左侧端点(如果不存在, 返回第一个大于target的值)
int binary_search_left(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```

```CPP
// 右侧端点
int binary_search_left(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
```

```CPP
// 存在性
int leftEnd = binary_search_left(q, 0, n-1, target);
if(q[leftEnd] != target)
    printf("Not exist.");
```

##### 6. binarysearch(float, 求三次方根)
```CPP
double binary_search_float(double n, double l, double r){
    while(r-l <= 1e-8){
        double mid = (l+r)/2;
        if(mid*mid*mid < n)
            l = mid;
        else
            r = mid;
    }
    return l;
}
binary_search_float(n, -max(abs(n), 1.0), max(abs(n), 1.0));
```

##### 7. prefixSum
```CPP
int q[N], prefixSum[N];

for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    prefixSum[i] = a[i] + prefixSum[i-1];
}

cout<<prefixSum[r]-prefixSum[l-1]<<endl;
```

##### 8. prefixSum(二维)
```CPP
int a[N][N], prefixSum[N][N];
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        scanf("%d", &a[i][j]);
        prefixSum[i][j] = a[i][j]+prefixSum[i][j-1]+prefixSum[i-1][j]-prefixSum[i-1][j-1];
    }
}
cout<<prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1]<<endl;
```

##### 9. difference
```CPP
int a[N], diff[N];

void diff_operation(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        diff_operation(i, i, a[i]);
    }
    int l, r, c;
    for(int i=0; i<q; i++){
        scanf("%d % d %d", &l, &r, &c);
        diff_operation(l, r, c);
    }
    for(int i=1; i<=n; i++){
        a[i] = diff[i] + a[i-1];
        printf("%d ", a[i]);
    }
    return 0;
}
```

##### 10. difference(二维)
```CPP
int a[N][N], diff[N][N];
void diff(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            diff_operation(i, j, i, j, a[i][j]);
        }
    }
    int x1, y1, x2, y2, c;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        diff_operation(x1, y1, x2, y2, c);
    }
    // 求二维prefixSum
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = diff[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

##### 11. 双指针 - 最长连续不重复子序列
```CPP
const int N = 100010;
int n, m, target;
int A[N];
unordered_map<int, int> mp; // 记录当前连续区间内元素出现次数

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int ans = 1;
    for(int i=0, j=0; i<n; i++){
        // 右端点逐个右移
        mp[A[i]]++;
        // 左端点持续右移
        while(j < i && mp[A[i]]>1){
            mp[A[j++]]--;
        }
        ans = max(ans, i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 12. 双指针 - 数组元素的目标和
```CPP
const int N = 100010;
int n, m, target;
int A[N], bElement;
unordered_map<int, int> mpA;    // val -> index

int main(){
    scanf("%d %d %d", &n, &m, &target);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
        mpA[A[i]] = i;
    }
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(mpA.find(target-bElement)!=mpA.end()){
            cout<<mpA[target-bElement]<<" "<<j<<endl;
            break;
        }
    }
    return 0;
}
```

##### 13. 双指针 - 判断子序列
```CPP
const int N = 100010;
int n, m;
int A[N], bElement;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    int idxA = 0;
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(bElement == A[idxA])
            idxA++;
        if(idxA == n)
            break;
    }
    if(idxA == n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
```

##### 14. lowbit - 求二进制表示中1的个数
```CPP
int lowbit(int x){
    return x&(-x);
}
int main(){
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){ // n个数
        cin>>x;
        int cnt = 0;
        while(x!=0){
            x -= lowbit(x);
            cnt++;
        }
        cout<<cnt<<" ";
    }
    return 0;
}
```

##### 15. 离散化
```CPP
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vi;
// 排序
sort(vi.begin(), vi.end());
// 去重, 去掉末尾元素
vi.erase(unique(vi.begin(), vi.end()), vi.end());
```

```CPP
// 自己实现unique去重
vector<int>::iterator unique(vector<int> &a){
    for(int i=0, j=0; i<a.size(); i++){
        if(i>0 && a[i]!=a[i-1])
            a[j++] = a[i];
    }
    return a.begin() + j;
}
vi.erase(unique(vi), vi.end());
```

```CPP
typedef pair<int, int> PII;

const int N = 300010;
int n, m;
int x, c, l, r;

vector<PII> add, query;
int a[N], prefixSum[N];

// 二分查找target在a[]中的下标位置
int find(int target){
    int l = 0;
    int r = vi.size()-1;
    while(l < r){
        int mid = (l+r)/2;
        if(vi[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l+1;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &c);
        add.push_back({x, c});
        vi.push_back(x);
    }
    for(int i=0; i<m; i++){
        scanf("%d %d", &l, &r);
        query.push_back({l, r});
        vi.push_back(l);
        vi.push_back(r);
    }
    // 对vi去重
    sort(vi.begin(), vi.end());
    vi.erase(unique(vi.begin(), vi.end()), vi.end());
    for(PII item: add){
        int x = find(item.first);
        a[x] += item.second;
    }
    for(int i=1; i<=vi.size(); i++){
        preSum[i] = a[i]+preSum[i-1];
    }
    // m次查询
    for(PII item: query){
        int l = find(item.first);
        int r = find(item.second);
        cout<<prefixSum[r] - prefixSum[l-1]<<endl;
    }
    return 0;
}
```

##### 16. 区间合并
```CPP
typedef pair<int, int> PII;

vector<PII> intervals, ans;

vector<PII> intervalMerge(vector<PII> intervals){
    cin>>n;
    sort(intervals.begin(), intervals.end());   // 开始时间排序
    PII curInterval = intervals.begin();
    for(int i=0; i<intervals.size(); i++){
        if(curInterval.second < intervals[i].first){
            ans.push_back(curInterval);
            curInterval = intervals[i];
            continue;
        }
        else{
            curInterval.second = max(curInterval.second, intervals[i].second);
        }
    }
    ans.push_back(curInterval);
    return ans;
}
```