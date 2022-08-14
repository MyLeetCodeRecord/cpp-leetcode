##### 1. linkedlist
```CPP
const int N = 100010;
int element[N], nextNode[N];
int head, idx;

void init(){
    head = -1;
    idx = 0;
}
void insertHead(int x){
    element[idx] = x;
    nextNode[idx] = head;
    head = idx++;
}
void insertNode(int k, int x){
    element[idx] = x;
    nextNode[idx] = nextNode[k-1];
    nextNode[k-1] = idx++;
}
void deleteNode(int k){
    if(k==0){
        head = nextNode[head];
        return ;
    }
    nextNode[k-1] = nextNode[nextNode[k-1]];
}
```

##### 2. Bi-linkedlist
```CPP
const int N = 100010;
int element[N], pre[N], post[N];    // 0, 1位置分别放
int idx;

void init(){
    pre[1] = 0;
    post[0] = 1;
    idx = 2;
}
void rightInsert(int k, int x){
    element[idx] = x;
    post[idx] = post[k];
    pre[idx] = k;
    pre[post[k]] = idx;
    post[k] = idx;
    idx++;
}
void leftInsert(int k, int x){
    rightInsert(pre[k], x);
}
void deleteNode(int k){
    post[pre[k]] = post[k];
    pre[post[k]] = pre[k];
}
int main(){
    int m;
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        string op;
        int k, x;
        cin>>op;
        if(op=="L"){
            scanf("%d", &x);
            rightInsert(0, x);      // head和tail始终是空节点
        }
        else if(op=="R"){
            scanf("%d", &x);
            rightInsert(pre[1], x); // tail不能直接接新节点, 而是找到pre[tail]
        }
        else if(op=="D"){
            scanf("%d", &k);
            deleteNode(k+1);        // idx从2开始存储
        }
        else if(op=="IL"){
            scanf("%d %d", &k, &x);
            rightInsert(pre[k+1], x);
        }
        else{
            scanf("%d %d", &k, &x);
            rightInsert(k+1, x);
        }
    }
    int cur = post[0];
    while(cur != 1){
        printf("%d", cur);
        cur = post[cur];
    }
    return 0;
}
```

##### 3. 单调栈 - 左侧最近的小于cur的值
```CPP
stack<int> sk;

int main(){
    int n, cur;
    cin>>n;
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

##### 4. 单调队列 - 滑动窗口内的最小值
```CPP
const int N = 1000010;
int a[N];
int q[N], h, t;

void init(){
    h = 0;
    t = -1;
}
int main(){
    int n, k, cur;
    scanf("%d %d", &n, &k);
    init();
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
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