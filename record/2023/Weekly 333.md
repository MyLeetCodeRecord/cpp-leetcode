#### Weekly 333

##### 1. [合并两个二维数组 - 求和法](https://leetcode.cn/problems/merge-two-2d-arrays-by-summing-values/): `归并` / `map`

> 周赛的时候用的`unordered_map`+`sort` / `map`的方式
>
> 但是两个输入数组都是有序的, 可以直接`O(m+n)`归并([归并排序](/acwing/Section%201/2_mergesort.cpp)的合并部分)

```CPP
vector<vector<int>> mergeArrays(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> ans;
    int i = 0;
    int j = 0;
    while(i<A.size() && j<B.size()){
        if(A[i][0] == B[j][0]){
            ans.push_back({A[i][0], A[i][1] + B[j][1]});
            i++;
            j++;
        }
        else if(A[i][0] < B[j][0])
            ans.push_back(A[i++]);
        else
            ans.push_back(B[j++]);
    }
    while(i < A.size()){
        ans.push_back(A[i++]);
    }
    while(j < B.size()){
        ans.push_back(B[j++]);
    }
    return ans;
}
```


##### 2. [将整数减少到零需要的最少操作数](https://leetcode.cn/problems/minimum-operations-to-reduce-an-integer-to-0/): `找规律` ➕ `双指针` / `DFS` ➕ `记忆化搜索`

> **周赛做法: 找规律 ➕ 双指针模拟**
>
> 从后向前找连续的`1` ➡️ `双指针`
> - 如果`len > 1`, 说明`+1进位`能获得最少操作次数, 最后由`...0 1...1 0...`变成`...1 0...0 0...`
>   - 将这一段连续的`1`全都改成`0`
>   - 将`j`指向的`0`改成`1`
> - 从`j`开始继续向前找连续`1`, 直到最后一位, 注意应该加一位`前缀0`, 防止最高位进位出错
>
> - 经过上述遍历过程后变成间隔的单独`1`
>   - e.g. `10...010...010...`
>   - 这些`1`能够且只能通过一次减法(`-2^k`)去除, 因此统计`1`的个数即为剩余的操作次数

```CPP
string getBinary(int x){
    string res = "";
    while(x != 0){
        if(x & 1)
            res = "1" + res;
        else
            res = "0" + res;
        x >>= 1;
    }
    return res;
}
int minOperations(int n) {
    int ans = 0;
    string s = getBinary(n);
    // 注意应该加一位`前缀0`, 防止最高位进位出错
    s = '0' + s;
    for(int i=s.size()-1; i>=0; i--){
        // 找一段连续的1, 如果长度大于1, 完成进位
        if(s[i]=='1'){
            int j = i;
            while(j>=0 && s[j]=='1')
                j--;
            if(i-j > 1){
                ans++;
                for(int k=j+1; k<=i; k++)   // +1进位
                    s[k] = '0';
                s[j] = '1';
                i = j+1;
            }
        }
    }
    // 剩下的是间隔的10...010...01, 每一个1表示一个必须做减法的2的幂次, 统计1的个数即为操作次数
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1')
            ans++;
    }
    return ans;
}
```

> **方法二: `DFS` ➕ `记忆化搜索`**
> - 因为最低位的`1`必须修改, 并且只能由自身的操作修改, 因此从后往前, 不断找最后一个`1` ➡️ `lowbit(x) = (-x) & x`
>
> - 对于一个`1 0...0`, 想要消除`1`, 需要`+lowbit`或者`-lowbit`(也就是`2^k`), 并且对后续问题进行修改(`x`变成`x+lowbit`或者`x-lowbit`)
>   - 加`2^k`消掉这一位的`1` => `DFS(x+lowbit)`
>   - 减`2^k`消掉这一位的`1` => `DFS(x-lowbit)`
>
> 二者取最小值, 返回`1 + min(DFS(x-lowbit), DFS(x+lowbit))`

```CPP
vector<int> memory;
// 记忆化搜索
int DFS(int x){
    if((x & (x-1))==0){
        memory[x] = 1;
        return 1;
    }
    if(memory[x] != -1)
        return memory[x];
    int lowbit = (-x) & x;
    memory[x] = 1 + min(DFS(x-lowbit), DFS(x+lowbit));
    return memory[x];
}
int minOperations(int n) {
    vector<int> mem(200010, -1);
    memory = mem;
    return DFS(n);
}
```