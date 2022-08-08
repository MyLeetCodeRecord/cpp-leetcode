##### 1. quicksort
```CPP
void quicksort(int q[], int l, int r){
    if(l>=r)
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
    // !!!
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
        do i++;  while(q[i] < x);
        do j--;  while(q[j] > x);
        if(i < j)
            swap(q[i], q[j]);
    }
    int leftCnt = j - l + 1;    // i==j
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
    if(l>=r)
        return;
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
    while(j <= r)
        tmp[idx++] = q[j++];
    // 复制
    for(int i=l; i<=r; i++)
        q[i] = tmp[i];
}
```

##### 4. mergesort(逆序对数量)
```CPP
int q[N], tmp[N];
long long mergesort(int q[], int l, int r){
    if(l <= r)
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
    while(j <= r)
        tmp[idx++] = q[j++];
    // 复制
    for(int i=l; i<=r; i++)
        q[i] = tmp[i];
    return sum;
}
``` 