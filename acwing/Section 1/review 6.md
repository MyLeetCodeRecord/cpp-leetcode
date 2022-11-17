##### 1. 快速排序
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];

void quicksort(int q[], int l, int r){
    if(l >= r)
        return;
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

int quickselect(int q[], int l, int r, int k){
    if(l>=r)
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
        return quickselect(q, l, j, k);
    else
        return quickselect(q, j+1, r, k-leftCnt);
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    cout<<quickselect(q, 0, n-1, k)<<endl;
    return 0;
}
```

##### 3. 归并排序
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int q[N];
int tmp[N];

void mergeSort(int q[], int l, int r){
    if(l>=r)
        return ;
    // 递归
    int mid = (l+r)/2;
    mergeSort(q, l, mid);
    mergeSort(q, mid+1, r);
    // 合并
    int i = l;
    int j = mid+1;
    int idx = l;
    while(i<=mid && j<=r){
        if(q[i] <= q[j])
            tmp[idx++] = q[i++];
        else
            tmp[idx++] = q[j++];
    }
    while(i<=mid){
        tmp[idx++] = q[i++];
    }
    while(j<=r){
        tmp[idx++] = q[j++];
    }
    for(int a=l; a<=r; a++)
        q[a] = tmp[a];
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &q[i]);
    }
    mergesort(q, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", q[i]);
    }
    return 0;
}
```

##### 4. 逆序对的数量
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int n;
int q[N], tmp[N];

long long mergeSort(int q[], int l, int r){
    if(l>=r)
        return 0;
    long long sum = 0;
    // 递归 => 先让左右两部分分别有序
    int mid = (r-l)/2+l;
    sum += mergeSort(q, l, mid);
    sum += mergeSort(q, mid+1, r);
    // 合并
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(q[j] < q[i]){    // q[j]即将被弹出, 正是对它计数的好机会
                            // 相当于固定q[j], 左侧q[i]后面的所有(都大于等于q[i])都可以与q[j]组成逆序对
            tmp[idx++] = q[j++];
            sum += (mid-i+1);
        }
        else
            tmp[idx++] = q[i++];
    }
    // 下面两个条件互斥, 不用额外加if
    while(i <= mid){   // left剩余
        tmp[idx++] = q[i++];
    }
    while(j <= r){     // right剩余
        tmp[idx++] = q[j++];
    }
    // !!!将合并结果从tmp复制回原始数组q
    for(int i=l; i<=r; i++){
        q[i] = tmp[i];
    }
    return sum;
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &q[i]);
    cout<<mergeSort(q, 0, n-1)<<endl;
    return 0;
}
```


#### 二分
```CPP
/* target左端点 */
// 如果不存在target, 会返回从左到右第一个 >=x 的位置
int binary_search_left(int q[], int target, int l, int r){
    while(l < r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    // 判断是否存在 = target
    if(q[l] != target)
        return -1;
    return l;
}
```

```CPP
/* target右端点 */
int binary_search_right(int q[], int target, int l, int r){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }
    // 判断是否存在 = target
    if(q[r] != target)
        return -1;
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

// 如果不存在target, 会返回从左到右第一个 >=x 的位置
int binary_search_left(int q[], int target, int l, int r){
    while(l < r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    // 判断是否存在 = target
    if(q[l] != target)
        return -1;
    return l;
}
int binary_search_right(int q[], int target, int l, int r){
    while(l < r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid - 1;
        else
            l = mid;
    }
    // 判断是否存在 = target
    if(q[r] != target)
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
        int query;
        scanf("%d", &query);
        int leftEnd = binary_search_left(q, query, 0, n-1);
        int rightEnd = binary_search_right(q, query, 0, n-1);
        cout<<leftEnd<<" "<<rightEnd<<endl;
    }
    return 0;
}
```

##### 6. 数的三次方根
```CPP
binary_search_float(double target, double l, double r){
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
vector<int> bigAdd(vector<int> &A, vector<int> &B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size() || i<B.size(); i++){
        if(i < A.size())
            t += A[i];
        if(i < B.size())
            t += B[i];
        ans.push_back(t%10);
        t /= 10;
    }
    if(t > 0)
        ans.push_back(t);
    return ans;
}
```

##### 8. 高精度减法
```CPP
bool compareBig(string a, string b){
    if(a.size() > b.size())
        return true;
    return a > b;
}
vector<int> bigMinus(vector<int> &A, vector<int> &B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i < A.size(); i++){
        if(i < B.size())
            t = A[i] - B[i] + t;
        else
            t = A[i] + t;
        ans.push_back((t+10) % 10);
        if(t < 0)
            t = -1;  // 借位
        else
            t = 0;
    }
    // 去除前导0
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
```

##### 9. 高精度乘法
```CPP
vector<int> bigMultiply(vector<int> &A, int b){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t += A[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while(t > 0){
        ans.push_back(t % 10);
        t /= 10;
    }
    // 去除前导0 (如果b=0)
    while(ans.back()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
```

##### 10. 高精度除法
> 除法从高位开始计算
```CPP
vector<int> bigDivide(vector<int> &A, int b, int &r){
    vector<int> ans;
    for(int i=A.size()-1; i>=0; i--){
        r = r * 10 + A[i];
        ans.push_back(r / b);
        r = r % b;
    }
    // 这里得到的ans是高位开始存储的
    reverse(ans.begin(), ans.end());
    // 去除前导0
    while(ans.size()>1 && ans.back()==0){
        ans.pop_back();
    }
    return ans;
}
```