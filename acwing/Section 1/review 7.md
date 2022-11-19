##### 1. 快速排序
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

void quicksort(int q[], int l, int r){
    if(l >= r)
        return ;
    int x = q[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j+1, r);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    quicksort(q, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", q[i]);
    }
    return 0;
}
```

##### 2. 快速选择
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

int quickselect(int q[], int k, int l, int r){
    if(l >= r)
        return q[l];
    int x = q[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i]<x);
        do j--;  while(q[j]>x);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = j - l + 1;
    if(leftCnt >= k)
        return quickselect(q, k, l, j);
    else
        return quickselect(q, k-leftCnt, j+1, r);
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    cout<<quickselect(q, k, 0, n-1)<<endl;
    return 0;
}
```

##### 3. 归并排序
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N], tmp[N];

void mergesort(int q[], int l, int r){
    if(l>=r)
        return ;
    int mid = (l+r)/2;
    mergesort(q, l, mid);
    mergesort(q, mid+1, r);
    int i = l;
    int j = mid+1;
    int idx = l;
    while(i<=mid && j<=r){
        if(q[i] < q[j])
            tmp[idx++] = q[i++];
        else
            tmp[idx++] = q[j++];
    }
    while(i<=mid)
        tmp[idx++] = q[i++];
    while(j<=r)
        tmp[idx++] = q[j++];
    for(int a=l; a<=r; a++)
        q[a] = tmp[a];
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    mergesort(q, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d ", q[i]);
    return 0;
}
```

##### 4. 逆序对的数量
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N], tmp[N];

void mergesort(int q[], int l, int r){
    if(l>=r)
        return 0;
    int mid = (l+r)/2;
    long long sum = mergesort(q, l, mid) + mergesort(q, mid+1, r);
    int i = l;
    int j = mid+1;
    int idx = l;
    while(i<=mid && j<=r){
        if(q[j] < q[i]){
            tmp[idx++] = q[j++];
            sum += mid-i+1;
        }
        else{
            tmp[idx++] = q[i++];
        }
    }
    while(i<=mid)
        tmp[idx++] = q[i++];
    while(j<=r)
        tmp[idx++] = q[j++];
    for(int a=l; a<=r; a++)
        q[a] = tmp[a];
    return sum;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    cout<<mergesort(q, 0, n-1)<<endl;
    return 0;
}
```


#### 二分
```CPP
/* 左端点 */
int binary_search_left(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r) / 2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```

```CPP
/* 右端点 */
int binary_search_right(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
```

##### 5. 数的范围
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

int binary_search_left(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r) / 2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    if(q[l]!=target)
        return -1;
    return l;
}
int binary_search_right(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    if(q[r]!=target)
        return -1;
    return r;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    for(int i=0; i<m; i++){
        int target;
        scanf("%d", &target);
        int leftEnd = binary_search_left(q, 0, n-1, target);
        int rightEnd = binary_search_right(q, 0, n-1, target);
        cout<<leftEnd<<" "<<rightEnd<<endl;
    }
    return 0;
}
```

##### 6. 数的三次方根 - 浮点数二分
```CPP
double binary_search(double l, double r, double target){
    while(r-l > 1e-8){
        double mid = (l+r)/2;
        if(mid*mid*mid > target)
            r = mid;
        else
            l = mid;
    }
    return l;
}
```


#### 高精度

##### 7. 高精度加法
```CPP
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

vector<int> bigAdd(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size() || i<B.size(); i++){
        if(i<A.size())
            t += A[i];
        if(i<B.size())
            t += B[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if(t != 0){
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    for(int j=s2.size()-1; j>=0; j--)
        B.push_back(s2[j]-'0');
    vector<int> ans = bigAdd(A, B);
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}
```

##### 8. 高精度减法
```CPP
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

bool compareBig(string A, string B){
    if(A.size() == B.size())
        return A >= B;
    return A.size() > B.size();
}
vector<int> bigMinus(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t += A[i];
        if(i<B.size())
            t -= B[i];
        ans.push_back((t+10)%10);
        if(t < 0)
            t = -1;
        else
            t = 0;
    }
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    // 去除前导0, 因为减法前需要比较大小
    // 这里最好用指针找位置, 别一直substr
    while(s1.size()>1 && s1[0]=='0')
        s1 = s1.substr(1, s1.size()-1);
    while(s2.size()>1 && s2[0]=='0')
        s2 = s2.substr(1, s2.size()-1);
    if(compareBig(s1, s2)==false){
        swap(s1, s2);
        printf("-");
    }
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    for(int i=s2.size()-1; i>=0; i--)
        B.push_back(s2[i]-'0');

    vector<int> ans = bigMinus(A, B);
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i];
    return 0;
}
```

##### 9. 高精度乘法
```CPP
vector<int> bigMultiply(vector<int> A, int b){
    if(b==0)
        return {0};
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t += A[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while(t!=0){
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}
```

##### 10. 高精度除法
> 除法从高位开始计算
```CPP
vector<int> bigDivide(vector<int> A, int b, int &r){
    vector<int> ans;
    for(int i=A.size()-1; i>=0; i--){
        r = r * 10 + A[i];
        ans.push_back(r / b);
        r %= b;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
```


#### 前缀和 & 差分
##### 11. 前缀和
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int prefixSum[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);
        prefixSum[i+1] = prefixSum[i-1] + x;
    }
    for(int i=0; i<m; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        cout<<prefixSum[r] - prefixSum[l-1]<<endl;
    }
    return 0;
}
```

##### 12. 二维前缀和
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int prefixSum[N][N];

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            scanf("%d", &x);
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + x;
        }
    }
    int x1, x2, y1, y2;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cout<<prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1]<<endl;
    }
    return 0;
}
```

##### 13. 一维差分
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int a[N], diff[N];

void diff_operation_1d(int l, int r, int c){
    diff[l]   += c;
    diff[r+1] -= c;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        diff_operation_1d(i, i, a[i]);  // diff的初始化, a[i]其实只需要一个变量代替, 但后面还可以作为前缀和数组
    }
    int l, r, c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &l, &r, &c);
        diff_operation_1d(l, r, c);
    }
    // a[]现在作为对diff[]求前缀和的载体
    for(int i=1; i<=n; i++){
        a[i] = a[i-1] + diff[i];
        printf("%d ", a[i]);
    }
    return 0;
}
```

##### 14. 二维差分
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int diff[N][N];

void diff_operation(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            diff_operation(i, j, i, j, a[i][j]);    // 初始化
        }
    }
    int x1, y1, x2, y2, c;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        diff_operation(x1, y1, x2, y2, c);
    }
    // 二维前缀和 => a[][]
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + diff[i][j];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```

##### 15. 最长连续不重复子序列
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int q[N];
unordered_map<int, int> mp;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    int ans = 1;
    for(int i=0, j=0; i<n; i++){
        mp[q[i]]++;
        while(j<=i && mp[q[i]]>1){
            mp[q[j++]]--;
        }
        ans = max(ans, i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 16. 数组元素的目标和
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int A[N], B[N];

int main(){
    int n, m, target;
    scanf("%d %d %d", &n, &m, &target);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    for(int j=0; j<n; j++)
        scanf("%d", &B[j])
    for(int i=0, j=m-1; i<n; ){
        while(j>=0 && A[i] + B[j] > target){
            j--;
        }
        if(A[i] + B[j] == target){
            printf("%d %d", i, j);
        }
    }
    return 0;
}
```

##### 17. 判断子序列
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int A[N], bElement, n, m;

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    int idx = 0;
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(bElement==A[idx])
            idx++;
        if(idx==n || n-idx > m-j-1)  // 提前终止
            break;
    }
    if(idx>=n)      // 因为数组A[]后面有0填充, 所以最好提前终止或将此处设为>=
        printf("Yes");
    else
        printf("No");
    return 0;
}
```

##### 18. 二进制中1的个数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

int lowbit(int x){
    return x & (-x);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        int cnt = 0;
        while(x != 0){
            x -= lowbit(x);
            cnt++;
        }
        printf("%d", cnt);
    }
    return 0;
}
```

##### 19. 区间合并
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

vector<PII> intervals;

vector<PII> intervalMerge(vector<PII> &intervals){
    vector<PII> ans;
    PII curInterval = intervals[0];
    for(int i=1; i<intervals.size(); i++){
        if(intervals[i].first > curInterval.second){
            ans.push_back(curInterval);
            curInterval = intervals[i];
        }
        else{
            // 注意这里是更新为更大值, 而不是无脑更新成intervals[i].second
            curInterval.second = max(curInterval.second, intervals[i].second);
        }
    }
    ans.push_back(curInterval);
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int st, ed;
        scanf("%d %d", &st, &ed);
        intervals.push_back({st, ed});
    }
    // 按开始时间排序
    sort(intervals.begin(), intervals.end());
    vector<PII> ans = intervalMerge(intervals);
    cout<<ans.size()<<endl; 
    return 0;
}
```

