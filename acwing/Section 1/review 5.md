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
