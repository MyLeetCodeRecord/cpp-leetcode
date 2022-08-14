##### 1. 单调栈
```CPP
// 找到左边最近的小于当前元素的值(的位置)
int main(){
    int n, cur;
    stack<int> sk;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        while(!sk.empty() && cur <= sk.top()){
            sk.pop();
        }
        if(!sk.empty())
            printf("%d ", sk.top());
        else
            printf("-1 ");
        sk.push(cur);
    }
    return 0;
}
```

##### 2. 单调队列 - 滑动窗口内的最小值
```CPP
const int N = 100010;
int q[N];   // 存储下标
int h, t;

int main(){
    int n, k, cur;
    scanf("%d %d", &n, &k);
    h = 0;
    t = -1;
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        // 本题要求滑动窗口内的最小值, 所以要控制单调队列长度
        if(h<=t && cur-q[h]+1 > k)
            h++;
        // 持续弹出"older & worse"的队尾元素
        while(h<=t && a[cur] < a[q[t]]){
            t--;
        }
        q[++t] = cur;
        printf("%d", a[q[h]]);
    }
    return 0;
}
```

##### 3. Trie - 最大异或对
```CPP
struct TrieNode{
    TrieNode* child[2]; // 0 or 1
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
TrieNode* trie;
void insert(int x){
    TrieNode* t = trie;
    for(int k=30; k>=0; k--){
        int cur = (x>>k) & 1;
        if(t->child[cur]==NULL)
            t->child[cur] = new TrieNode();
        t = t->child[cur];
    }
}
int search(int x){
    TrieNode* t = trie;
    int Xor = 0;
    for(int k=30; k>=0; k--){
        int cur = (x>>k) & 1;
        int not_cur = (cur==0) ? 1 : 0;
        if(t->child[not_cur]!=NULL){
            t = t->child[not_cur];
            Xor = Xor*2+1;
        }
        else{
            t = t->child[cur];
            Xor = Xor*2;
        }
    }
    return Xor;
}
int main(){
    trie = new TrieNode();
    int n, x;
    scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        insert(x);
        ans = max(ans, search(x));
    }
    printf("%d", ans);
    return 0;
}
```

##### 4. 并查集 - 连通块大小
```CPP
const int N = 100010;
int father[N], sizeList[N];

void init_ufs(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
        sizeList[i] = 1;
    }
}
int find_ufs(int u){
    if(father[u]!=u)
        father[u] = find_ufs(father[u]);
    return father[u];
}
void union_ufs(int u, int v){
    int fu = find_ufs(u);
    int fv = find_ufs(v);
    if(fu!=fv){
        father[fv] = fu;
        sizeList[fu] += sizeList[fv];
    }
}
int main(){
    int n;
    cin>>n;
    init_ufs(n);
    string op;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>op;
        if(op=="C"){
            scanf("%d %d", &a, &b);
            union_ufs(a, b);            
        }
        else if(op=="Q1"){
            scanf("%d %d", &a, &b);
            if(inSame(a, b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if(op=="Q2"){
            scanf("%d", &a);
            printf("%d\n", sizeList[find_ufs(a)]);
        }
    }
    return 0;
}
```

##### 5. 并查集 - 食物链
```CPP
const int N = 50010;
int father[N];
int dist[N];    // 到father[i]的距离

void init_ufs(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
    }
}
int find_ufs(int u){
    if(father[u]!=u){
        int tmp = find_ufs(father[u]);
        dist[u] += dist[father[u]];
        father[u] = tmp;
    }
    return father[u];
}
int main(){
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    init_ufs(n);
    for(int i=0; i<k; i++){
        int relation, x, y;
        scanf("%d %d %d", &relation, &x, &y);
        if(x>n || y>n){
            ans++;
        }
        else{
            int px = find_ufs(x);
            int py = find_ufs(y);
            if(relation==1){
                if(px==py && (dist[x]-dist[y])%3!=0){
                    ans++;
                }
                else if(px!=py){
                    father[px] = py;    // 改变了谁的father, 就去调整谁的dist
                    dist[px] = dist[y]-dist[x];
                }
            }
            else{
                if(px==py && (dist[x]-dist[y]-1)%3!=0){
                    ans++;
                }
                else if(px!=py){
                    father[px] = py;
                    dist[px] = dist[y]-dist[x]+1;
                }
            }
        }
    }
    return 0;
}
```