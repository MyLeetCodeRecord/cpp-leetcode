#### Weekly 330

##### 1. [统计桌面上的不同数字](https://leetcode.cn/problems/count-distinct-numbers-on-board/): `模拟` `找规律`

###### 方法一: 模拟
> `10^9`只是障眼法, 如果某一轮检查没有新增加的数字, 则下一轮也不会出现更新, 因此可以用「是否有更新」或者「最多`n=100`次」来作为终止条件

```CPP
int distinctIntegers(int n) {
    int ans = 0;
    vector<int> vi;
    vi.push_back(n);
    vector<bool> hashTable(n+1, false);
    hashTable[n] = true;
    bool exchange = true;
    while(exchange){
        exchange = false;
        for(int a=0; a<vi.size(); a++){
            for(int i=1; i<vi[a]; i++){
                if(vi[a] % i == 1 && hashTable[i]==false){
                    exchange = true;
                    vi.push_back(i);
                    hashTable[i] = true;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(hashTable[i]==true)
            ans++;
    }
    return ans;
}
```

###### 方法二: 找规律
> 对于每个已经加入的数字`x`, `x-1`一定可以在下一轮加入, 因此可以这样延伸, 一共有`n-1`个元素被加进来, 但要注意`n==1`时, `ans=1`

```CPP
int distinctIntegers(int n) {
    if(n==1)
        return 1;
    return n-1;
}
```


##### 2. [猴子碰撞的方法数](https://leetcode.cn/problems/count-collisions-of-monkeys-on-a-polygon/): `反向思维` `快速幂`
> 题目描述有一点问题
> - 如果按照样例的规则(交换中相遇也算作碰撞), 只有整体顺时针和整体逆时针两种情况要排除 => `2^n-2`
>
> - 如果按照题目描述
>   - 对于奇数个节点, 同样只有整体顺时针和整体逆时针两种情况要排除 => `2^n - 2`
>   - 对于偶数个节点, 可以两两交换, 额外排除两种相邻交换方案 => `2^n - 4`
>
> 然后问题转化为了[`需要求余的快速幂`](/acwing/Section%204/Acwing%20-%20%E5%BF%AB%E9%80%9F%E5%B9%82.md)
>
> `WA`了一次, 因为`1-2 < 0`, 因此应该多加一层`MOD`, `ans = (ans+MOD-2) % MOD`

```CPP
long long quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1){
            ans *= a;
            ans %= mod;
        }
        a = (long long)a * a % mod;     // 7^1, 7^2, 7^4 ...
        n >>= 1;
    }
    return ans % mod;
}
int monkeyMove(int n) {
    long long ans = quickPow(2, n, 1000000007);
    ans = (ans + 1000000007 - 2) % 1000000007;
    return ans;
}
```


##### 3. [将珠子放入背包中](https://leetcode.cn/problems/put-marbles-in-bags/)

> 看起来是个`dp`问题, 但是`O(n^2) = O(1^10)`会超时, 事实也是如此...
>
> 观察样例发现, `cost`只取决于所有**分界位置**两侧的两个元素, 并且「相邻两个元素一定被同时取得」, 并且选取方案「与位置顺序无关」
>
> 由于所有珠子都需要用到, 所以无论哪种方案, 左右两个端点一定要取得, 不会对两种方案的差造成影响, 所以只需要取`K-1`个分界点即可
>
> 将相邻元素相加获得数组`sum`, 并对其排序
>
> - `maxCost`方案为, 取`sum`中前`K-1`大的数求和
> - `minCost`方案为, 取`sum`中前`K-1`小的数求和

```CPP
long long putMarbles(vector<int>& w, int K) {
    if(K==1 || w.size()==K)
        return 0;
    int n = w.size();
    // 求相邻和数组
    vector<int> sum(n-1, 0);
    for(int i=0; i<n-1; i++){
        sum[i] = w[i] + w[i+1];
    }
    // 排序
    sort(sum.begin(), sum.end());
    // 取K-1个分界点
    long long maxCost = 0, minCost = 0;
    for(int i=0; i<K-1; i++){
        maxCost += sum[sum.size()-1-i];
        minCost += sum[i];
    }
    return maxCost - minCost;
}
```


##### 4. [统计上升四元组](https://leetcode.cn/problems/count-increasing-quadruplets/): `前后缀数组`

> 枚举四元组的方式 => 枚举中间两个元素会更高效
>
> 对于`i<j<k<l`, 求满足`nums[i]<nums[k]<nums[j]<nums[l]`的四元组的个数
> 
> 如果暴力枚举, 则有`O(n^2)`个`<nums[k], nums[j]>`对
>
> 另外, `1<=nums[i]<=nums.size` & `nums`中所有数字互不相同, 因此`nums`数组是一个`1~n`的排列
> 
> 于是可以定义**前后缀数组**
> - 定义
>   - `greater[k][x]`: 在`k`右侧比`x`大的元素个数
>   - `less[j][x]`: 在`j`左侧比`x`小的元素个数
> - 计算
>   - 倒序遍历`nums`, 如果`x < nums[k+1]`, 大于`x`的数字加一, 即`greater[k][x]++`
>   - 正序遍历`nums`, 如果`x > nums[j-1]`, 小于`x`的数字加一, 即`less[j][x]++`

```CPP
int great[4000][4001];
long long countQuadruplets(vector<int> &nums) {
    int n = nums.size(), less[n + 1];
    for (int k = n - 2; k >= 2; k--) {
        // copy一下
        memcpy(great[k], great[k + 1], sizeof(great[k + 1]));
        for (int x = nums[k + 1] - 1; x > 0; x--)
            great[k][x]++;  // x<nums[k+1], 对于x, 大于它的数的个数 +1
    }
    long long ans = 0;
    memset(less, 0, sizeof(less));
    for (int j = 1; j < n - 2; j++) {
        for (int x = nums[j - 1] + 1; x <= n; x++)
            less[x]++;  // x>nums[j-1], 对于x, 小于它的数的个数+1
        for (int k = j + 1; k < n - 1; k++)
            if (nums[j] > nums[k])
                ans += less[nums[k]] * great[k][nums[j]];
    }
    return ans;
}
```