##### 1. prefixSum
```CPP
int a[N], prefixSum[N];
// 构建前缀和
for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    prefixSum[i] = a[i] + prefixSum[i-1];
}
// 使用前缀和
cout<<prefixSum[r] - prefixSum[l-1]<<endl;
```

##### 2. prefix(二维)
```CPP
int a[N][N], prefixSum[N][N];
// 构建前缀和
for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        scanf("%d", &a[i][j]);
        prefixSum[i][j] = a[i][j]+prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1];
    }
}
// 使用前缀和: 对于(x1,y1), (x2,y2)区域和的查询
cout<<prefixSum[x2][y2]-prefixSum[x1-1][y2]-prefixSum[x2][y1-1]+prefixSum[x1-1][y1-1]<<endl;
```

##### 3. difference
```CPP
int a[N], diff[N];
void diff_operation(int l, int r, int c){
    diff[l] += c;
    diff[r+1] -= c;
}
int main(){
    // 初始化
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        diff_operation(i, i, a[i]);
    }
    // 对diff[]执行q次操作
    int l, r, c;
    for(int i=0; i<q; i++){
        scanf("%d %d %d", &l, &r, &c);
        diff_operation(l, r, c);
    }
    // 求前缀和 => 写回a[]
    for(int i=1; i<n; i++){
        a[i] = diff[i] + a[i-1];
    }
    return 0;
}
```

##### 4. difference(二维)
```CPP
int a[N][N], diff[N][N];
void diff_operation(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
    // 初始化
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            diff_operation(i, j, i, j, a[i][j]);
        }
    }
    // 执行q次操作
    int x1, y1, x2, y2, c;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        diff_operation(x1, y1, x2, y2, c);
    }
    // 求前缀和
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

##### 5. 双指针-最长连续不重复子序列
```CPP
const int N = 100010;
int n, m, target;
int A[N];
unordered_map<int, int> mp;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    int ans = 1;
    for(int i=0, j=0; i<n; i++){
        // 右端点逐个右移
        mp[A[i]]++;
        // 左端点持续右移
        while(j<n && mp[A[i]]>1){
            mp[A[j++]]--;
        }
        ans = max(ans, i-j+1);
    }
    printf("%d\n", ans);
    return 0;
}
```

##### 6. 双指针-数组元素的目标和
```CPP
const int N = 100010;
int n, m, target;
int A[N], bElement;
unordered_map<int, int> mpA;

int main(){
    scanf("%d %d %d", &n, &m, &target);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
        mpA[A[i]] = i;
    }
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(mpA.find(target-bElement)!=mpA.end()){
            cout<<mpA[target-bElement]<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}
```

##### 7. 双指针-判断子序列
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
        if(bElement==A[idxA])
            idxA++;
        if(idxA == n)
            break;
    }
    if(idxA==n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
```