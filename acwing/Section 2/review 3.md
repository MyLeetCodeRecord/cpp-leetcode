##### 1. 单调队列

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];
int q[N], h=0, t=-1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    h = 0;
    t = -1;
    for(int i=0; i<n; i++){
        // 检查head是否超过k, 超过则弹出
        if(h <= t && i-q[h]+1 > k)
            h++;
        // 弹出order & worse的队尾元素 => 单调队列也会操作队尾
        while(h <= t && a[i]<=a[q[t]])
            t--;
        // 插入当前元素
        q[++t] = i;
        // head即为当前窗口答案
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    printf("\n");
    h = 0;
    t = -1;
    for(int i=0; i<n; i++){
        if(h <= t && i-q[h]+1 > k)
            h++;
        while(h <= t && a[i]>=a[q[t]])
            t--;
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    printf("\n");
    return 0;
}
```


#### Trie
##### 2. Trie字符串统计
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Trie{
    Trie* child[26];
    int time;
    Trie(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        time = 0;
    }
};
void insert(Trie* trie, string word){
    Trie* t = trie;
    for(int i=0; i<word.size(); i++){
        if(t->child[word[i]-'a']==NULL)
            t->child[word[i]-'a'] = new Trie();
        t = t->child[word[i]-'a'];
    }
    t->time++;
}
int search(Trie* trie, string word){
    Trie* t = trie;
    for(int i=0; i<word.size(); i++){
        if(t->child[word[i]-'a']==NULL)
            return 0;
        t = t->child[word[i]-'a'];
    }
    return t->time;
}
int main(){
    int n;
    scanf("%d", &n);
    Trie* trie = new Trie();
    for(int i=0; i<n; i++){
        char op;
        string word;
        cin>>op>>word;
        if(op=='I')
            insert(trie, word);
        else
            printf("%d\n", search(trie, word));
    }
    return 0;
}
```

##### 3. 最大异或对
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

struct Trie{
    Trie* child[2];
    Trie(){
        child[0] = NULL;
        child[0] = NULL;
    }
};
void insert(Trie* trie, int x){
    Trie* t = trie;
    // 注意"对齐"
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & 1;
        if(t->child[cur]==NULL)
            t->child[cur] = new Trie();
        t = t->child[cur];
    }
}
int search(Trie* trie, int x){
    Trie* t = trie;
    int ans = 0;
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & 1;
        int not_cur = (cur==0);
        if(t->child[not_cur] != NULL){
            t = t->child[not_cur];
            ans = ans * 2 + 1;
        }
        else{
            t = t->child[cur];
            ans = ans * 2;
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    Trie* trie = new Trie();
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        insert(trie, x);
        ans = max(ans, search(trie, x));
    }
    cout<<ans<<endl;
    return 0;
}
```


#### 并查集
##### 4. 连通块中点的数量
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int father[N], sizeList[N];

void init(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
        sizeList[i] = 1;
    }
}
int find(int u){
    if(u != father[u])
        father[u] = find(father[u]);
    return father[u];
}
void union_2(int u, int v){
    int fu = find(u);
    int fv = find(v);
    if(fu != fv){
        father[fu] = fv;
        sizeList[fv] += sizeList[fu];
    }
}
bool inSame(int u, int v){
    return find(u) == find(v);
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    init(n);
    for(int i=0; i<m; i++){
        string op;
        cin>>op;
        int u, v;
        if(op=="C"){
            scanf("%d %d", &u, &v);
            union_2(u, v);
        }
        else if(op=="Q1"){
            scanf("%d %d", &u, &v);
            if(inSame(u, v))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else{
            scanf("%d", &u);
            printf("%d\n", sizeList[find(u)]);
        }
    }
    return 0;
}
```


#### 堆
##### 5. 堆排序(小顶堆)
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int heap[N], _size=0;;

void up(int k){
    if(k!=1 && heap[k] < heap[k/2]){
        swap(heap[k], heap[k/2]);
        up(k/2);
    }
}
void down(int k){
    int smaller = k;
    if(2*k <= _size && heap[2*k] < heap[smaller])
        smaller = 2*k;
    if(2*k+1 <= _size && heap[2*k+1] < heap[smaller])
        smaller = 2*k+1;
    if(smaller != k){
        swap(heap[k], heap[smaller]);
        down(smaller);
    }
}
void push(int x){
    heap[++_size] = x;
    up(_size);
}
int pop(){
    int popped = heap[1];
    heap[1] = heap[_size--];
    down(1);
    return popped;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%d", &heap[++_size]);
    }
    for(int i=n/2; i>=1; i--){
        down(i);
    }
    for(int i=0; i<m; i++){
        printf("%d ", pop());
    }
    return 0;
}
```

#### 散列表
##### 6. 模拟散列表
```CPP
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], nxt[N], idx=0;

void insert(int x){
    int k = (x % N + N) % N;    // hash值
    e[idx] = x;
    nxt[idx] = h[k];
    h[k] = idx++;
}
bool query(int x){
    int k = (x % N + N) % N;
    int start = h[k];
    while(start != -1){
        if(e[start] == x)
            return true;
        start = nxt[start];
    }
    return false;
}
int main(){
    int n;
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for(int i=0; i<n; i++){
        char op[2];
        int x;
        scanf("%s%d", op, &x);  // 注意字符数组的scanf读入方式
        if(*op == 'I')
            insert(x);
        else{
            if(query(x))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
```

##### 7. 字符串前缀哈希
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010, P = 131;

char str[N];
ULL h[N], p[N];

ULL getHash(int l, int r){
    return h[r] - h[l-1] * p[r-l+1];
}
int main(){
    int n, m;
    scanf("%d %d %s", &n, &m, str+1);
    // 预处理 p[i] 和 h[i]
    p[0] = 1;
    for(int i=1; i<=n; i++){
        p[i] = p[i-1] * P;
        h[i] = h[i-1] * P + str[i];
    }
    for(int i=0; i<m; i++){
        int l1, r1, l2, r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if(getHash(l1, r1) == getHash(l2, r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
```