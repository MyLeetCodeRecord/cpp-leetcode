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