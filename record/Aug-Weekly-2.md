#### Weekly 2

> 一千六是什么多高的分? 三题还能继续掉, 不理解住了...
> 
> 据说是`4a+3b+2c+d`的计算公式...下次小心别罚时了吧, 至少别因为一个东西罚时两次...

##### 1. [矩阵中的局部最大值](https://leetcode.cn/problems/largest-local-values-in-a-matrix/)
> 第一题, 暴力遍历即可, 时间复杂度`O(n^2)`
> 
> 如果不想创建额外空间, 可以直接写回`grid[i-1][i-1]`, 即左上角位置
> 
> 但要注意返回数组的形状, 需要额外弹出两行两列

```CPP
    vector<vector<int> > d = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        // 不开辟新空间的做法 => 直接写回原数组, 但返回前需要调整矩阵size
        // vector<vector<int> > ans(n-2, vector<int>(n-2));
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int maxLocal = grid[i][j];
                for(int m=0; m<8; m++){
                    maxLocal = max(maxLocal, grid[i+d[m][0]][j+d[m][1]]);
                }
                grid[i-1][j-1] = maxLocal;
            }
            grid[i-1].pop_back();
            grid[i-1].pop_back();
        }
        grid.pop_back();
        grid.pop_back();
        return grid;
    }
```

##### 2. 边积分最高的节点
> 因为`long long` WA了两次...真的会谢...看在好久没做Leetcode的份上, 选择原谅自己

```CPP
int edgeScore(vector<int>& edges) {
    long long ans = 0;
    int node = 0;
    int n = edges.size();
    vector<long long> sums(n, 0);
    for(int i=0; i<n; i++){
        sums[edges[i]] += i;
        if(sums[edges[i]] > ans){
            node = edges[i];
            ans = sums[edges[i]];
        }
        else if(sums[edges[i]] == ans && edges[i]<node){
            node = edges[i];
        }
    }
    return node;
}
```

##### 3. 根据模式串构造最小数字
> `暴力回溯`or`贪心`
> 写`回溯`的时候迟疑了, 其实知道复杂度`9!`没问题, 但还是...非要想贪心?
> 
> ![LC6150](/appendix/LC6150.png)

###### 贪心
> 贪心的话, 识别每一个`m*I + n*D`的子串, 如果不是开头, 则`m--`
> 
> 然后对每个`m*I + n*D`进行生成, 全局`cur`控制这段子串使用的数字范围(起始)

```CPP
string getSubStr(int cur, int iCnt, int dCnt){
    int n = iCnt + dCnt + 1;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        if(i<=iCnt){
            ans[i] = cur++;
        }
        else{
            ans[i] = cur-1;
        }
    }
    for(int i=1; i<=dCnt; i++){
        ans[n-i-1] = cur++;
    }
    string str = "";
    for(int i=0; i<n; i++){
        str += ('0'+ans[i]);
    }
    return str;
}
string smallestNumber(string pattern) {
    string ans;
    int idx = 0;
    int cur = 1;
    int i=0, j=0; 
    while(i<pattern.size()){
        int iCnt = 0;
        int dCnt = 0;
        while(pattern[i]=='I' && pattern[j] == pattern[i]){
            iCnt++;
            j++;
        }
        if(i!=0)
            iCnt--;
        //cout<<iCnt<<" "<<pattern.substr(i, j-i)<<"??";
        i = j;
        while(pattern[i]=='D' && j<pattern.size() && pattern[j] == pattern[i]){
            dCnt++;
            j++;
        }
        //cout<<dCnt<<" "<<pattern.substr(i, j-i)<<"!!";
        i = j;
        //cout<<endl;
        ans += getSubStr(cur, iCnt, dCnt);
        cur += (iCnt+dCnt+1);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return ans;
}
```

###### 回溯
> 回溯法明明很好写啊, 第一个数字可以用回溯外的一层`0~9`的循环实现, 🪂🪂🪂

```CPP
vector<string> ans;
string path;
void backtrack(string pattern, int cur, vector<bool>& visit){
    if(ans.size() > 0)  // 字典序最小即可
        return ;
    if(cur==pattern.size() || path.size()==pattern.size()+1){
        ans.push_back(path);
        return ;
    }
    if(pattern[cur]=='I'){
        for(int i=path.back()-'0'+1; i<=9; i++){
            if(visit[i]==false){
                path += ('0'+i);
                visit[i] = true;
                backtrack(pattern, cur+1, visit);
                path = path.substr(0, path.size()-1);
                visit[i] = false;
            }
        }
    }
    else{
        for(int i=path.back()-'0'-1; i>=1; i--){
            if(visit[i]==false){
                path += ('0'+i);
                visit[i] = true;
                backtrack(pattern, cur+1, visit);
                path = path.substr(0, path.size()-1);
                visit[i] = false;
            }
        }
    }
}
string smallestNumber(string pattern) {
    // 一直纠结的"第一个数字", 其实可以在外层处理呀...
    vector<bool> visit(10, false);
    for(int i=1; i<=9; i++){
        if(ans.size()>0)
            return ans[0];
        visit[i] = true;
        path += ('0'+i);
        backtrack(pattern, 0, visit);
        visit[i] = false;
        path = "";
    }
    return ans[0];
}
```

###### next_permutation
> 也可以用`next_permutation`, 属于**纯**暴力做法, 可以保证字典序, 但生成过程没有考虑`I or D`

```CPP
string smallestNumber(string str){
    string ans;
    // first permutation
    for(int i=1; i<=str.size(); i++){
        ans += ('0'+i);
    }
    // 循环 - next_permutation
    while(true){
        bool flag = true;
        // 检查当前排列是否符合模板串, 不符合跳过
        for(int i=0; i<str.size(); i++){
            if(str[i]=='I' && ans[i]>ans[i+1]){
                flag = false;
                break;
            }
            else if(str[i]=='D' && ans[i]<ans[i+1]){
                flag = false;
                break;
            }
        }
        if(flag)
            break;
        next_permutation(ans.begin(), ans.end());
    }
    return ans;
}
```

##### 4. 统计特殊整数
> 学完`数位dp`再写