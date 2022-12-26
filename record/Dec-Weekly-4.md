#### Weekly 4

##### 1. [到目标字符串的最短距离](https://leetcode.cn/problems/shortest-distance-to-target-string-in-a-circular-array/): `一次遍历` `环形数组`
> 两个角度, 遍历找到每个target, 或者遍历每个元素

```CPP
int closetTarget(vector<string>& words, string target, int startIndex) {
    int ans = 110;
    int n = words.size();
    for(int i=0; i<n; i++){
        if(words[i]==target){
            // 注意是"环形数组", 需要计算两个方向距离
            ans = min(ans, min(abs(startIndex-i), n-abs(startIndex-i)));
        }
    }
    return ans>=110 ? -1 : ans;
}
```


##### 2. [每种字符至少取 K 个](https://leetcode.cn/problems/take-k-of-each-character-from-left-and-right/): `双指针`

###### (1) 双指针
> ![灵神-lc6270](/appendix/LC6270-2.png)
> 
> 不需要前缀和数组, `O(1)`空间

```CPP
int takeCharacters(string s, int k) {
    int n = s.size();
    int cnt[3];
    // i: 前缀终止下标(+1就是前缀长度), j: 后缀起始下标
    // 1. 当前缀为空时, 初始化 j 的起始位置
    int i = 0;
    int j = n;
    while(cnt[0]<k && cnt[1]<k && cnt[2]<k){
        if(j == 0)
            return -1;
        cnt[s[--j]-'a']++;
    }
    int ans = n-j;
    // 2. 枚举前缀终止位置, while收缩后缀
    for(i = 0; i < n; i++){
        cnt[s[i]-'a']++;
        while(j<n && cnt[s[j]]>k){
            cnt[s[j++]-'a']--;
        }
        ans = min(ans, i+1 + n-j);
        // 剪枝: 后缀为空后, 不再需要继续遍历其它更长前缀了
        if(j == n)
            break;
    }
    return ans;
}
```

###### (2) `计数前缀和`➡️双0⃣️做法
> 和第`92`场双周赛第三题: [LC2483. 商店的最少代价](/workspace/2483.%20%E5%95%86%E5%BA%97%E7%9A%84%E6%9C%80%E5%B0%91%E4%BB%A3%E4%BB%B7.cpp)差不多
>
> 求计数前缀和`prefixSum[n+1][3]`的同时, 另外用三个`map`, 记录字符`a / b / c`出现`i`次的最左位置
>
> 倒序遍历字符串, 可以利用`all0 - prefixSum[j][0]`求出后缀中`'a'`的个数(b, c同理), 然后由`'a'`限制的需要的最少前缀即为`needA = k-(all1 - prefixSum[j][0])`, 再利用`mpA[needA]`找到前缀的最短距离, 三个字符求得的最短距离取最大值`leftLimit = max(mpA[needA], max(mpB[needB], mpC[needC]))`, `min(n-j+leftLimit)`即为当前后缀对应的答案
>
> ![LC6270](/appendix/LC6270.png)


##### 3. [礼盒的最大甜蜜度](https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/): `(能力检测)二分` `贪心`
> 「能力检测二分」: 同[LC1552. 两球之间的磁力](/workspace/1552.%E4%B8%A4%E7%90%83%E4%B9%8B%E9%97%B4%E7%9A%84%E7%A3%81%E5%8A%9B.cpp), 找到要求的值 (比如这题是`gap`, [LC875. 爱吃香蕉的珂珂](/workspace/875.%E7%88%B1%E5%90%83%E9%A6%99%E8%95%89%E7%9A%84%E7%8F%82%E7%8F%82.cpp)中是`speed`), 然后检查当前`mid`是否满足, 进而调整边界
> 
> ![LC1552评论区](/appendix/LC6217.png)
> 
> **二分**
> 
> 首先**顺序**对最大甜蜜度没有影响, 先对`price[]`排序
> 
> 甜蜜度起始就是所选糖果的差, 如果用`gap`这个词来表示, 就可以分析出最大甜蜜度就是要找一个最小`gap`值
> 
> - `gap`越小, 能选的糖果越多
> - `gap`越大, 能选的糖果越少
>
> 由于具有**单调性**, 可以用`二分`([right模板](/acwing/Section%201/acwing%20-%20%E4%BA%8C%E5%88%86%E6%B3%95.md#%E5%8F%B3%E4%BE%A7%E7%AB%AF%E7%82%B9)), `check(mid)`的条件就是能选的糖果数量是否大于等于`K`

> **贪心**
> 
> `check(mid)`中, 已知`price[]`(有序)和`gap`
> 
> 利用`贪心`, 从`{price[0]}`作为起点, 每次遇到和`pre`(前一个选中的糖果)差距大于`gap`的, 就选择这个糖果 (反证法可以证明, `ans`是最优的)

```CPP
// 二分查找: 枚举的是「GAP」
int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());
    int l = 0;
    int r = 1e9;
    while(l < r){
        int mid = (l+r+1)/2;
        if(check(price, mid, k)==false)
            r = mid-1;
        else
            l = mid;
    }
    return l;
}
// 贪心: 一旦与上一个选中糖果的差值小于等于gap, 就取这个糖果
bool check(vector<int>& price, int gap, int k){
    int cnt = 1;    // 最小的糖果一定会取
    int pre = price[0];
    for(int i=1; i<price.size(); i++){
        if(price[i] - pre >= gap){
            cnt++;
            pre = price[i];
        }
        if(cnt >= k) // 提前结束
            return true;
    }
    return cnt >= k;
}
```