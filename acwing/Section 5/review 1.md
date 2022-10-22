##### 1. 01背包

```CPP
const int N = 1010;
int w[N], v[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=C; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 2. 完全背包

```CPP
const int N = 1010;
int w[N], v[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d", &w[i], &v[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=C; j++){
            if(j >= w[i])
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 3. 多重背包 - 朴素做法 - 展开为01背包

```CPP
const int N = 110;
int w[N], v[N], s[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=C; j>=0; j--){
            for(int k=1; k<=s[i]; k++){
                if(j >= k*w[i])
                    dp[j] = max(dp[j], dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}
```

##### 4. 多重背包 - 二进制优化

```CPP
typedef pair<int, int> PII;

const int N = 1010, M = 2010;
int w[N], v[N], s[N];
int dp[M];
vector<PII> goods;

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    for(int i=0; i<n; i++){
        for(int k=1; k<s[i]; k*=2){
            s[i] -= k;
            goods.push_back({k * w[i], k * v[i]});
        }
        if(s[i] > 0){
            goods.push_back({s[i] * w[i], s[i] * v[i]})
        }
    }
    for(int i=0; i<goods.size(); i++){
        for(int j=C; j>=goods[i].first; j--){
            dp[j] = max(dp[j], dp[j-goods[i].first] + goods[i].second);
        }
    }
    cout<<dp[C]<<endl;
}
```

##### 5. 分组背包
```CPP
const int N = 110;
int s, w[N], v[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d", &s);
        for(int j=0; j<s; j++){
            scanf("%d %d", &w[j], &v[j]);
        }
        for(int j=C; j>=0; j--){
            for(int k=0; k<s; k++){
                if(j>=w[k]){
                    dp[j] = max(dp[j], dp[j-w[k]]+v[k]);
                }
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}```