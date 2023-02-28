#### 链表
##### 1. 单链表
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int e[N], nxt[N];
int head = -1, idx = 0;

void insertHead(int x){
    e[idx] = x;
    nxt[idx] = head;
    head = idx++;
}
void insertNode(int k, int x){
    e[idx] = x;
    nxt[idx] = nxt[k-1];
    nxt[k-1] = idx++;
}
void deleteNode(int k){
    if(k==0){
        head = nxt[head];
        return ;
    }
    nxt[k-1] = nxt[nxt[k-1]];
}
void printList(){
    int cur = head;
    while(cur!=-1){
        printf("%d ", e[cur]);
        cur = nxt[cur];
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        char op;
        cin>>op;
        int k, x;
        if(op == 'H'){
            scanf("%d", &x);
            insertHead(x);
        }
        else if(op == 'D'){
            scanf("%d", &k);
            deleteNode(k);
        }
        else{
            scanf("%d %d", &k, &x);
            insertNode(k, x);
        }
    }
    printList();
    return 0;
}
```

##### 2. 双链表
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int element[N], pre[N], post[N], idx;

void init(){
    idx = 2;
    post[0] = 1;
    pre[1] = 0;
}
void rightInsert(int k, int x){
    element[idx] = x;
    pre[idx] = k;
    post[idx] = post[k];
    pre[post[k]] = idx;
    post[k] = idx;
    idx++;
}
void deleteNode(int k){
    post[pre[k]] = post[k];
    pre[post[k]] = pre[k];
}
int main(){
    int m;
    scanf("%d", &m);
    init();
    for(int i=0; i<m; i++){
        string op;
        int k, x;
        cin>>op;
        if(op=="L"){
            scanf("%d", &x);
            rightInsert(0, x);
        }
        else if(op=="R"){
            scanf("%d", &x);
            rightInsert(pre[1], x); // tail不能直接接新节点, 而是找到pre[tail]
        }
        else if(op=="D"){
            scanf("%d", &k);
            deleteNode(k+1);    // idx从2开始存储
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
        printf("%d ", element[cur]);
        cur = post[cur];
    }
    return 0;
}
```


#### 栈
##### 3. 模拟栈
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int sk[N], top = 0;

bool isEmpty(){
    return top == 0;
}
void push(int x){
    sk[top++] = x;
}
void pop(){
    if(top!=0)
        top--;
}
int query(){
    if(query==0)
        return -1;
    return sk[top-1];
}
int main(){
    int n;
    cin>>n;
    string op;
    int val;
    for(int i=0; i<n; i++){
        cin>>op;
        if(op=="push"){
            cin>>val;
            insert(val);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            cout<<(isEmpty()?"YES":"NO")<<endl;
        }
        else{
            query();
        }
    }
    return 0;
}
```

##### 4. 表达式求值
```CPP
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

stack<int> numSk;
stack<char> symbolSk;
unordered_map<char, int> priority{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void calc_eval(){
    if(symbolSk.empty())
        return ;
    int b = numSk.top();        numSk.pop();
    int a = numSk.top();        numSk.pop();
    char op = symbolSk.top();   symbolSk.pop();
    if(op=='+')
        numSk.push(a+b);
    else if(op=='-')
        numSk.push(a-b);
    else if(op=='*')
        numSk.push(a*b);
    else
        numSk.push(a/b);
}
int main(){
    string ex;
    cin>>ex;
    for(int i=0; i<(int)ex.size(); i++){
        char ch = ex[i];
        if(isdigit(ch)){
            int j = i;
            int num = 0;
            while(j<(int)ex.size() && isdigit(ex[j])){
                num = num*10 + (ex[j]-'0');
                j++;
            }
            numSk.push(num);
            i = j-1;
        }
        // 如果是左括号, 这种情况不能和+-*/的情况合并, 或者将"("的优先级设为最高
        else if(ch == '('){
            symbolSk.push('(');
        }
        // 如果是右括号, 则计算直到找到匹配的左括号
        else if(ch==')'){
            while(!symbolSk.empty() && symbolSk.top() != '('){
                calc_eval();
            }
            symbolSk.pop();       // 将左括号也弹出
        }
        // 如果是更低优先级的符号, 需要将更高优先级的符号先计算完
        else{
            while(!symbolSk.empty() && priority[symbolSk.top()] >= priority[ch]){
                calc_eval();
            }
            symbolSk.push(ch);
        }
    }
    while(!symbolSk.empty())
        calc_eval();
    cout<<numSk.top()<<endl;
    return 0;
}
```


#### 队列
##### 5. 模拟队列
```CPP
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int q[N];
int head = 0, tail = 0;

bool isEmpty(){
    return head >= tail;
}
void insert(int x){
    q[tail++] = x;
}
void pop(){
    if(!isEmpty())
        head++;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        string op;
        cin>>op;
        if(op=="push"){
            int x;
            cin>>x;
            insert(x);
        }
        else if(op=="pop"){
            pop();
        }
        else if(op=="empty"){
            cout<<(isEmpty()?"YES":"NO")<<endl;
        }
        else{
            cout<<q[head]<<endl;
        }
    }
    return 0;
}
```


#### [单调栈](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%8D%95%E8%B0%83%E6%A0%88.md)
##### 6. 单调栈 - 左侧最近的更小元素
```CPP
#include <cstdio>
#include <stack>
using namespace std;

stack<int> sk;

int main(){
    int n, cur;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        while(!sk.empty() && cur<=sk.top())
            sk.pop();
        if(!sk.empty())
            printf("%d ", sk.top());
        else
            printf("-1 ");
        sk.push_back(cur);
    }
    return 0;
}
```


##### LC739. 每日温度
```CPP
// 求左边的最近最大/最小 => ans[cur] = sk.top()
// 求右边的最近最大/最小 => ans[popped] = cur
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> sk;
    int n = temperatures.size();
    vector<int> ans(n, 0);  // ans记录的idx下标间隔
    for(int i=0; i<n; i++){
        while(!sk.empty() && temperatures[i] > temperatures[sk.top()]){ // 注意ans要用的是idx下标
            ans[sk.top()] = i-sk.top();
            sk.pop();
        }
        sk.push(i);
    }
    return ans;
}
```


##### LC496. 下一个更大元素I
```CPP
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> bigger(nums2.size(), -1);   // 存元素下标
    stack<int> sk;
    for(int i=0; i<nums2.size(); i++){
        while(!sk.empty() && nums2[i]>nums2[sk.top()]){
            bigger[sk.top()] = nums2[i];
            sk.pop();
        }
        sk.push(i);
    }
    unordered_map<int, int> mp;
    for(int i=0; i<nums2.size(); i++){
        mp[nums2[i]] = i;
    }
    vector<int> ans(nums1.size(), -1);
    for(int i=0; i<nums1.size(); i++){
        ans[i] = bigger[mp[nums1[i]]];
    }
    return ans;
}
```
