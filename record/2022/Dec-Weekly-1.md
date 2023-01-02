#### Weekly 1

##### 1. [回环句](https://leetcode.cn/problems/circular-sentence/): `双指针` `循环数组`
> 一个角度是**前后两个单词比较**, 另一个角度**检查每个空格两端字符是否相等**

> **Step 1**: 字符串处理
> 
> - 方式一是用双指针找到单词的开头和结尾, 在每个空格及句子末尾断开, 构成单词数组
> 
> - 方式二是通过stringstream将字符串读入数组

```CPP
// 方式一: stringstream处理字符串
stringstream ssin(sentence);
vector<string> words;
string str;
while(ssin>>str){
    words.push_back(str);
}

// 方式二: 双指针
for(int i=0; i<sentence.size(); ){
    int j = i;
    while(j<sentence.size() && sentence[j]!=' '){
        j++;
    }
    string sub = sentence.substr(i, j-i);
    strs.push_back(sub);
    i = j;
}
```

> **Step 2**: 循环判断相邻单词合法性
> 
> 要比较结尾与开头单词, 可以用`(i+1) % n`来统一处理, 或者单独判断一下结尾单词

```CPP
for(int i=0; i<n; i++){
    if(strs[i].back() != strs[(i+1) % strs.size()][0])
        return false;
}
return true;
```


##### 2. 划分技能点相等的团队(https://leetcode.cn/problems/divide-players-into-teams-of-equal-skill/)

> **方法一: 排序**, 每次选最大和最小作为一组, 复杂度`O(nlogn)`
> 
> **方法二: 哈希**, 复杂度`O(n)`
> 以`sum/(n/2)`作为`target`, 对于每个`nums[i]`, 检查`target-nums[i]`还有多少个
> - 如果有`target-nums[i]`, 消除掉一个
> - 如果没有`target-nums[i]`, 放到哈希表中等待后面使用
> 
> 但其实...
> ![LC2491](/appendix/LC2491.png)

```CPP
// 方法一: 排序+首尾双指针
long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    // 排序, 然后每次取(当前)最大最小作为一组
    sort(skill.begin(), skill.end());
    int sum = skill[0] + skill.back();
    long long ans = skill[0] * skill.back();
    for(int i=1; i<n/2; i++){
        // 每次取当前首、尾元素划分为一组
        if(sum != skill[i]+skill[n-i-1])
            return -1;
        // 记录cost
        ans += (skill[i] * skill[n-i-1]);
    }
    return ans;
}
```

```CPP
// 方法二: map
long long dividePlayers(vector<int>& skill) {
    // step 1: 求每个分组target
    int n = skill.size();
    int sum = 0;
    for(int s: skill)
        sum += s;
    if(sum % (n/2) != 0)
        return -1;
    int target = sum / (n/2);
    // 哈希表
    unordered_map<int, int> mp;
    long long ans = 0;
    for(int i=0; i<n; i++){
        // 如果配对元素已经存在, 直接消除掉, 表示配对成功, 并记录到ans中
        if(mp.find(target-skill[i]) != mp.end()){
            mp[target-skill[i]]--;
            ans += (skill[i] * (target-skill[i]));
            if(mp[target-skill[i]]==0){
                mp.erase(target-skill[i]);
            }
        }
        // 如果配对元素尚不存在(不代表后面数组不会出现), 先加入哈希表等待
        else{
            mp[skill[i]]++;
        }
    }
    if(mp.size()>0)
        return -1;
    return ans;
}
```


##### 3. [两个城市间路径的最小分数](https://leetcode.cn/problems/minimum-score-of-a-path-between-two-cities/): 连通块的最短距离 ➡️ `并查集` or `BFS`
> 边可以重复走, 问题本质就是求, 与`起点1`连通的边的最小值, 或者说连通图中的最小边
> 
> `Dijkstra`我都抄上了...原来是最小边...

###### 方法一: 直观想法 ➡️ `并查集`

> **集合最小边的维护**
> 
> 可以开一个`minWeight[N]`数组, 与`sizeList[N]`性质类似, 在合并时更新, 只有集合`root`的`minWeight`值有意义
>
> 如果不维护`minWeight[N]`, 就要两次遍历`roads`

```CPP
// 先写个并查集模板
const int N = 100010;

int father[N];
int minWeight[N];

void _init(int n){   // 注意下标是不是从1开始
    for(int i=1; i<=n; i++){
        father[i] = i;
        minWeight[i] = INT_MAX;
    }
}
int _find(int u){
    if(father[u] != u){
        father[u] = _find(father[u]);    // 路径压缩
    }
    return father[u];
}
void _union(int u, int v){
    int fu = _find(u);
    int fv = _find(v);
    if(fu != fv){
        father[fu] = fv;            
        minWeight[fv] = min(minWeight[fu], minWeight[fv]);
    }
}
bool inSame(int u, int v){
    return _find(u) == _find(v);
}
```

> **遍历`roads`, 更新`minWeight`**
> 
> 遍历边的时候也要更新`minWeight`, 注意直接更新到`father[u]`和`father[v]`上
> 
> 合并也可以直接用`father[u]`和`father[v]`, 避免多重复一次`find(u)`和`find(v)`

```CPP
int minScore(int n, vector<vector<int>>& roads) {
    _init(n);
    for(vector<int> r: roads){
        int fu = _find(r[0]);
        int fv = _find(r[1]);
        minWeight[fu] = min(minWeight[fu], r[2]);
        minWeight[fv] = min(minWeight[fv], r[2]);
        _union(fu, fv);
    }
    return minWeight[_find(1)];
}
```

###### 方法二: `BFS`/`DFS`就可以检查连通性
> 只要遍历完整个块就可以求出最小边长了, 只不过想不通**要不要处理重复访问**
> 
> 灵神说 ➡️ 因为是图所以`visit[N]`还是要有的, 只要先检查边权, 再判断`visited[neighbor] => DFS(neighbor)`即可
> 
> ![LC2492](/appendix/LC2492.png)

```CPP
const int N = 100010;

int ans = INT_MAX;    
bool visited[N] = {false};

// 邻接表存储图, 注意无向图, 边相关的size要double一下
int h[N], e[2*N], nxt[2*N], w[2*N], idx=0;
void insert(int a, int b, int d){
    e[idx] = b;
    w[idx] = d;
    nxt[idx] = h[a];
    h[a] = idx++;
}
void DFS(int u){
    visited[u] = true;
    for(int i=h[u]; i!=-1; i=nxt[i]){
        int j = e[i];
        // 不管能不能DFS(child), 先检查边权
        ans = min(ans, w[i]);
        if(!visited[j])
            DFS(j);
    }
}
int minScore(int n, vector<vector<int>>& roads) {
    // 建图
    memset(h, -1, sizeof h);
    for(auto edge : roads){
        insert(edge[0], edge[1], edge[2]);
        insert(edge[1], edge[0], edge[2]);
    }
    // 检查起点1连通图中的所有边
    DFS(1);
    return ans;
}
```

##### 4. [将节点分成尽可能多的组](https://leetcode.cn/problems/divide-nodes-into-the-maximum-number-of-groups/)

> 哦, 看了灵神的视频题解, 好难, 总会有水的周赛让我ak
> 
> 补个[染色法判断二分图]()