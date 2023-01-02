#### Weekly 3

##### 1. [统计相似字符串对的数目💚](https://leetcode.cn/problems/count-pairs-of-similar-strings/): `暴力` `hash`

```CPP
int similarPairs(vector<string>& words) {
    int n = words.size();
    // 注意只检查存在性, 而不是要求数目相等(否则直接排序比较字符串相等就行了)
    vector<vector<bool> > hash(n, vector<bool>(26, 0));
    for(int i=0; i<n; i++){
        for(char ch: words[i]){
            hash[i][ch-'a'] = true;
        }
    }
    int ans = 0;
    // 双指针
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            bool same = true;
            for(int k=0; k<26; k++){
                if(hash[i][k] != hash[j][k]){
                    same = false;
                    break;
                }
            }
            ans += same;
        }
    }
    return ans;
}
```


##### 2. [使用质因数之和替换后可以取到的最小值🧡](https://leetcode.cn/problems/smallest-value-after-replacing-with-sum-of-prime-factors/): `质因数分解`

> 本质不断进行就是`质因数分解`

```CPP
int divide(int x){
    int ans = 0;
    for(int i=2; i<=x/i; i++){
        while(x % i == 0){
            x /= i;
            ans += i;
        }
    }
    if(x != 1)
        ans += x;
    return ans;
}
int smallestValue(int n) {
    int _min = n;
    n = divide(n);
    while(n < _min){
        _min = n;
        n = divide(n);
    }
    return _min;
}
```


##### 3. [添加边使所有节点的度数都为偶数❤️](https://leetcode.cn/problems/add-edges-to-make-degrees-of-all-nodes-even/): `graph` `分类讨论` `set`

> 周赛中其实已经分析出`0/2/4`几种情况了
> 
> 没有解决的问题是: 如何快速检查两点之间有没有边, 以及如何快速获取节点的度 ➡️ 可以用`set数组`来解决

```CPP
/* 只能处理奇数节点个数 = 0 / 2 / 4的情况
 * - 0 => true
 * - 2 => (1) 两个节点间无边; or (2) 有一个outside节点
 * - 4 => 四个点互相连接[3种匹配情况]
 */
bool isPossible(int n, vector<vector<int>>& edges) {
    unordered_set<int> g[n+1];
    for(vector<int> e: edges){
        g[e[0]].insert(e[1]);
        g[e[1]].insert(e[0]);
    }
    vector<int> odds;
    int outside = 0;
    for(int i=1; i<=n; i++){
        if(g[i].size() % 2 == 1)
            odds.push_back(i);
    }
    if(odds.size()==0)
        return true;
    if(odds.size()==2){
        int a = odds[0];
        int b = odds[1];
        // 如果a与b之间没有边, 加一条a-b就可以
        if(g[a].find(b)==g[a].end())
            return true;
        // 可以由outside节点延伸两条边
        else{
            for(int i=1; i<=n; i++)
                if(g[i].size() < n-2 && g[i].find(a)==g[i].end() && g[i].find(b)==g[i].end())
                    return true;
        }
        return false;
    }
    if(odds.size()==4){
        int a = odds[0];
        int b = odds[1];
        int c = odds[2];
        int d = odds[3];
        if(g[a].find(b)==g[a].end() && g[c].find(d)==g[c].end())    // a&b  c&d
            return true;
        if(g[a].find(c)==g[a].end() && g[b].find(d)==g[b].end())    // a&c  b&d
            return true;
        if(g[a].find(d)==g[a].end() && g[b].find(c)==g[b].end())    // a&d  b&c
            return true;
        return false;
    }
    return false;
}
```


##### 4. [查询树中环的长度❤️](https://leetcode.cn/problems/cycle-length-queries-in-a-tree/): `最近公共祖先LCA` `完全二叉树`
> `LCA`问题, `len = dist(a, lca) + dist(b, lca) + 1`
> 
> y总 ➡️ 爬山法: **先调到同一层**, 然后共同向上查找公共祖先, 向上爬升的过程就是遍历环的过程, 额外加一条`<a, b>`
> 
> 灵神 ➡️ 每次选深度更深的点(编号更大), **交替上升**

```CPP
// y总: 先对齐, 再一起爬升
int getHeight(int x){
    int h = 0;
    while(x!=0){
        x /= 2;
        h++;
    }
    return h;
}
vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    for(vector<int> q: queries){
        int a = q[0];
        int b = q[1];
        if(a < b)
            swap(a, b);
        int ah = getHeight(a);
        int bh = getHeight(b);
        int len = 0;
        for(int i=0; i<ah-bh; i++){
            a /= 2;
            len++;
        }
        while(a!=b){
            a /= 2;
            b /= 2;
            len += 2;
        }
        ans.push_back(len+1);
    }
    return ans;
}
```

```CPP
// 灵神: 交替上升
vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    for(vector<int> &q: queries){
        int a = q[0];
        int b = q[1];
        int len = 0;
        while(a != b){
            if(a > b)
                a /= 2;
            else
                b /= 2;
            len++;
        }
        ans.push_back(len+1);
    }
    return ans;
}
```