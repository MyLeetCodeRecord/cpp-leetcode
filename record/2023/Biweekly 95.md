#### Biweekly 95

##### 1. [根据规则将箱子分类](https://leetcode.cn/problems/categorize-box-according-to-criteria/): `阅读理解`

```CPP
string categorizeBox(int length, int width, int height, int mass) {
    bool b = false;
    bool h = false;
    long long vol = (long long)length * width * height;
    if(length>=10000 || width>=10000 || height>=10000 || vol >= 1000000000)
        b = true;
    if(mass>=100)
        h = true;
    if(b && h)
        return "Both";
    if(b)
        return "Bulky";
    if(h)
        return "Heavy";
    return "Neither";
}
```

##### 2. [找到数据流中的连续整数](https://leetcode.cn/problems/find-consecutive-integers-from-a-data-stream/): `理解题`

> 透过现象看本质, 数据流流动的过程中, 唯一需要关注的就是「末尾字符」以及「它已经连续出现了多少个」

```CPP
int K, V, last, cnt;
DataStream(int value, int k) {
    V = value;
    K = k;
}
bool consec(int num) {
    if(num==last)
        cnt++;
    else{
        last = num;
        cnt = 1;
    }
    if(last==V && cnt >= K)
        return true;     
    return false;
}
```


##### 3. [查询数组 Xor 美丽值](https://leetcode.cn/problems/find-xor-beauty-of-array/): `位运算`

###### 方法一: 推导
> 位运算的特点: 每个比特位互不相关 => 拆分成每个比特单独看
>
> => 统计`((a | b) & c) = 1`个数的奇偶性
>
> 设在当前比特位(一共`30`个比特位)上, 有`y`个`1`, `n-y`个`0`
> 
> => `(a | b) = 1` & `c = 1`
>
> => `ones = (n^2 - (n-y)^2) * y = 偶数 - y^3`
>
> => `ones`的奇偶性等价于`y`的奇偶性
>
> => `y`的奇偶性等价于当前位`0`和`1`的异或

###### 方法二: 对称性
> `(nums[i] | nums[j]) & nums[k]`, `1<=i, j, k<n`任意取值
>
> 利用对称性, 对于每个`nums[k]`, `(nums[i] ｜ nums[j])`=`(nums[j] | nums[i])`会对称出现(除非`i==j`), 然后这两组取值`<i, j, k>`和`<j, i, k>`的有效值进行`XOR`结果为`0`
> 
> 结论一: 只有`i=j`对`XOR`结果有贡献 => `nums[i] & nums[k]`
>
> 进一步, 利用对称性, `(nums[i] & nums[k])` = `(nums[k] & nums[k])`也是成对出现的(除非`i==k`)
>
> 结论二: 只有`i=j=k`对`XOR`结果有贡献 => `nums[i]`
>
> 因此`XOR`结果为单项`nums[i]`的异或和

```CPP
int xorBeauty(vector<int>& nums) {
    long long res = 0;
    for(int x: nums){
        res = res ^ x;
    }
    return res;
}
```


##### 4. [最大化城市的最小供电站数目](https://leetcode.cn/problems/maximize-the-minimum-powered-city/): `二分` `前缀和` `差分`

> cv卡

```CPP
long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();
    long long prefixSum[n + 1], power[n], diff[n];
    prefixSum[0] = 0;
    for(int i=1; i<=n; i++){
        prefixSum[i] =prefixSum[i-1] + stations[i-1];
    }
    for(int i=0; i<n; i++){
        power[i] = prefixSum[min(i+r+1, n)] - prefixSum[max(i-r, 0)];  // 前缀和求区间和, 注意边界
    }

    auto check = [&](long long min_power) -> bool {
        memset(diff, 0, sizeof(diff));  // 重置差分数组
        long long sum_d = 0;  // 实时记录差分数组的前缀和
        long long need = 0;
        for(int i=0; i<n; i++){
            sum_d += diff[i]; // 累加差分值
            long long m = min_power - power[i] - sum_d;  // 计算不足的电量, 需要在以i为左边界的区间补足m个供电站
            if(m > 0){  // 需要新建供电站
                need += m;
                if(need > k)  // 提前退出
                    return false;
                sum_d += m;
                if(i + r * 2 + 1 < n)
                    diff[i + r * 2 + 1] -= m; // 差分更新
            }
        }
        return need<=k;
    };

    long long left = *min_element(power, power + n);
    long long right = left + k;
    while (left < right) {
        long mid = (right-left+1) / 2 + left;
        if(check(mid))
            left = mid;
        else
            right = mid-1;
    }
    return left;
}
```