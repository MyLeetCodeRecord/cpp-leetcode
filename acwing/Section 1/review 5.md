##### 1. quicksort

```CPP
void quicksort(int q[], int l, int r){
    if(l>=r)
        return ;
    int x = q[(l+r)/2];
    int i = l - 1;
    int j = r + 1;
    while(i<j){
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j+1, r)
}
```

##### 2. quickselect
```CPP
int quickselect(int q[], int k, int l, int r){
    if(l>=r)
        return q[l];
    int x = q[(l+r)/2];
    int i = l - 1;
    int j = r + 1;
    while(i < j){
        do i++; while(q[i] < x);
        do j++; while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = (j - l + 1);
    if(leftCnt >= k)
        return quickselect(q, k, l, j);
    else
        return quickselect(q, k-leftCnt, j+1, r);
}
```

##### 3. mergesort
```CPP
const int N = 100010;
int q[N], tmp[N];

void mergesort(int q[], int l, int r){
    if(l>=r)
        return ;
    int mid = (l+r)/2;
    mergesort(q, l, mid);
    mergesort(q, mid+1, r);
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(q[i] <= q[j])
            tmp[idx++] = q[i++];
        else
            tmp[idx++] = q[j++];
    }
    while(i <= mid){
        tmp[idx++] = q[i++];
    while(j <= r){
        tmp[idx++] = q[j++];
    for(int a=l; a<=r ;a++)
        q[a] = tmp[a];
}
```

##### 4. mergesort(逆序对的数量)
```CPP
long long mergesort(int q[], int l, int r){
    if(l>=r)
        return 0;
    int mid = (l+r)/2;
    long long sum = mergesort(q, l, mid) + mergesort(q, mid+1, r);
    int idx = l;
    int i = l;
    int j = mid;
    while(i<=mid && j<=r){
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
// 满足条件的左侧端点, 如果不存在, 则返回第一个大于target的值
int binary_search_left(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r)/2;
        if(q[l] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```

```CPP
int binary_search_right(int q[], int l, int r, int target){
    while(l < r){
        int mid = (l+r)/2;
        if(q[r] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
```

```CPP
int leftEnd = binary_search_left(q, 0, n-1, target);
if(leftEnd>=n || q[leftEnd]!=target)
    cout<<"not exist"<<endl;
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
int main(){
    int n;
    cin>>n;
    cout<<binary_search_float(n, -10000.0, 10000.0)<<endl;
    return 0;
}
```

##### 7. 前缀和
```CPP
const int N = 100010;
int q[N], prefixSum[N]; // 都错开一位
int n, l, r;

int main(){
    for(int i=1; i<=n; i++){
        scanf("%d", &q[i]);
        prefixSum[i] = q[i] + prefixSum[i-1];
    }
    for(int i=0; i<q; i++){
        scanf("%d %d", l, r);
        cout<<prefixSum[r] - prefixSum[l-1]<<endl;
    }
    return 0;
}
```

##### 8. 前缀和(二维)
```CPP
const int N = 10010;
int a[N][N], prefix[N][N];
int n, q, x1, y1, x2, y2;

int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &a[i][j]);
            prefixSum[i][j] = a[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
        printf("%d\n", prefixSum[x2][y2]-prefixSum[x2][y1-1]-prefixSum[x1-1][y2]+prefixSum[x1-1][y1-1]);
    }
    return 0;
}
```

##### 9. difference
```CPP
int a[N], diff[N];
int n, q, l, r, c;

void diff_operation(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        diff_operation(i, i, a[i]); //diff[]的"初始化"
    }
    for(int i=0; i<q; i++){
        scanf("%d %d %d", &l, &r, &c);
        diff_operation(l, r, c);
    }
    // diff[]求前缀和写入a[] (此时a[]没有数值作用, 只是承载作用)
    for(int i=1; i<=n; i++){
        a[i] = diff[i] + a[i-1];
        print("%d ", a[i]);
    }
    return 0;
}
```

##### 10. difference(二维)
```CPP
int a[N][N], diff[N][N];
int n, m, q, x1, y1, x2, y2, c;

void diff_operation_2d(int x1, int y1, int x2, int y2){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            diff_operation_2d(i, j, i, j, a[i][j]);
        }
    }
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d %d", &x1, &x2, &x3, &x4, &c);
        diff_operation_2d(x1, y1, x2, y2, c);
    }
    // diff[][]求前缀和写入a[][] (此时a[][]没有数值作用, 只是承载作用)
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