##### 1. quicksort
```CPP
void quicksort(int q[], int l, int r){
    if(l>=r)
        return ;
    int x = q[(l+r)/2];
    // !!!
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i] < q[x]);
        do j++;  while(q[i] > q[x]);
        if(i < j)
            swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j+1, r);
}
```

##### 2. quickselect(第k小的数)
```CPP
int quickselect(int q[], int k, int l, int r){
    if(l==r)
        return q[l];
    int x = q[(l+r)/2];
    int i = l-1;
    int j = r+1;
    while(i < j){
        do i++;  while(q[i] < q[x]);
        do j++;  while(q[j] > q[x]);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = j - l + 1;
    if(leftCnt <= k)
        return quickselect(q, k, l, j);
    else
        return quickselect(q, k-leftCnt, j+1, r);
}
```

##### 3. mergesort
```CPP
int q[N], tmp[N];
void mergesort(int q[], int l, int r){
    if(l>=r)
        return ;
    int mid = (l+r)/2;
    // 递归
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
    while(i <= mid)
        tmp[idx++] = q[i++];
    while(j <= mid)
        tmp[idx++] = q[j++];
    // 复制
    for(int i=l; i<=r; i++)
        q[i] = tmp[i];
}
```

##### 4. mergesort(逆序对数量)
```CPP
long long mergesort(int q[], int l, int r){
    if(l>=r)
        return 0;
    // 递归
    int mid = (l+r)/2;
    long long sum = mergesort(q, l, mid) + mergesort(q, mid+1, r);
    // 合并
    int idx = l;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r){
        if(q[i] <= q[j])
            tmp[idx++] = q[i++];
        else{
            tmp[idx++] = q[j++];
            sum += mid-i+1;
        }
    }
    while(i <= mid)
        tmp[idx++] = q[i++];
    while(j <= mid)
        tmp[idx++] = q[j++];
    // 复制
    for(int i=l; i<=r; i++)
        q[i] = tmp[i];
    return sum;
}
```

##### 5. binarysearch
```CPP
// 左侧端点(如果不存在, 返回第一个大于target的位置)
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
// 右侧端点(如果不存在, 返回第一个小于target的位置)
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

```CPP
// 存在性
int leftEnd = binary_search_left(arr, 0, n-1, target);
if(a[leftEnd] != target)
    printf("Not exist.\n");
```

##### 6. binarysearch(float, 求三次方根)
```CPP
double binary_search_float(double n, double l, double r){
    while(r-l >= 1e-8){
        double mid = (l+r)/2;
        if(mid*mid*mid > n)
            r = mid;
        else
            l = mid;
    }
    return l;
}

// 调用方式 => 解决“启动”问题
binary_search_float(n, -max(abs(n), 1.0), max(abs(n),1.0));
// or
binary_search_float(n, -10000, 10000);
```

##### 7. prefixSum
```CPP
int a[N], prefixSum[N];
// 构建前缀和
for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    prefixSum[i] = a[i]+prefixSum[i-1];
}
// 使用前缀和, 查询[l, r]的区间和
cout<<prefixSum[r] - prefixSum[l-1]<<endl;
```

##### 8. prefixSum(二维)
```CPP
// 二维前缀和可以对齐
int a[N][N], prefixSum[N][N];
// 构建
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        scanf("%d", &a[i][j]);
        prefixSum[i][j] = a[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
    }
}
// 使用: 对于(x1,y1), (x2,y2)区域和的查询
prefixSum[x2][y2]-prefixSum[x1-1][y2]-prefixSum[x2][y1-1]+prefixSum[x1-1][y1-1];
```

##### 9. difference
```CPP
int a[N], diff[N];
void diff_operation(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        diff_operation(i, i, a[i]); // 初始化
    }
    // 对diff[]执行m次操作
    int l, r, c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &l, &r, &c);
        diff_operation(l, r, c);
    }
    // 求前缀和 => 写回数组a[]
    for(int i=1; i<=n; i++){
        a[i] = a[i-1] + diff[i];
        printf("%d ", a[i]);
    }
    return 0;
}
```

##### 10. difference(二维)
```CPP
int a[N][N], diff[N][N];
void diff_operation(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
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
    // 求前缀和
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = diff[i][j] + a[i-1][j] + a[i][j-1] + a[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```