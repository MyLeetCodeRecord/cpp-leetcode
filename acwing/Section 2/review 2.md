##### 1. 单调栈

```CPP
// 找左侧最近的小于cur的值
stack<int> sk;
for(int i=0; i<n; i++){
    scanf("%d", &cur);
    while(!sk.empty() && cur<sk.top())
        sk.pop();
    if(!sk.empty())
        printf("%d\n", sk.top());
    else
        printf("-1\n");
    sk.push(cur);
}
```

```CPP
// 找到右侧最近的更大值位置
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> sk;
    vector<int> ans;
    for(int i=0; i<temperatures.size(); i++){
        int cur = temperatures[i];
        while(!sk.empty() && cur > temperatures[sk.top()]){
            ans[sk.top()] = i;
            sk.pop();
        }
        sk.push(i);
    }
    return ans;
}
```


##### 2. 单调队列
```CPP
const int N = 1000010;
int a[N], q[N], head, tail;
int n, k;

void init(){
    head = 0;
    tail = -1;
}
int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    init();
    // 找窗口内最小
    for(int i=0; i<n; i++){
        if(head<=tail && i-q[head] >= k)
            head++;
        while(head<=tail && a[i] < a[q[tail]])  // a[i]是比队列(窗口)中元素更好的答案
            tail--;
        q[++tail] = i;
        if(i>=k-1)
            printf("%d ", a[q[head]]);
    }
    printf("\n");
    init();
    // 找窗口内最大
    for(int i=0; i<n; i++){
        if(head<=tail && i-q[head] >= k)
            head++;
        while(head<=tail && a[i] > a[q[tail]])  // a[i]是比队列(窗口)中元素更好的答案
            tail--;
        q[++tail] = i;
        if(i>=k-1)
            printf("%d ", a[q[head]]);
    }
    return 0;
}
```