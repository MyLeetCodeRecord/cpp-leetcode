#### Weekly 2 - No. 317 - `3*, rank 1321`

- [x] [温度转换](https://leetcode.cn/problems/convert-the-temperature/): 加减法


- [x] [6234. 最小公倍数为 K 的子数组数目](https://leetcode.cn/problems/number-of-subarrays-with-lcm-equal-to-k/)

> 这题的数据范围`1000`, 看起来就能`暴力`
> 
> 难点在于求每段数组的`lcm`, 于是百度了一下...再加上一层枚举左端点, 就过了...


> **两数的最小公倍数**
> 
> `lcm(a, b) = a * b / gcd(a, b)`
> 
> **数组的最小公倍数 => 传递**
> 
> 用`lcm`记录`nums[:j-1]`这段数组的最小公倍数, `lcm`初始化为`1`
> 
> 可以得到, `lcm(nums[:j]) = lcm * nums[j] / gcd(lcm, nums[j])`
> 
> 由于`nums[j]`每个数大于`1`, 因此一旦`lcm > target`, 应该提前`break`这个`起点i`取值

```CPP
// 最大公约数
int gcd(int a, int b){
    if(a % b == 0)
        return b
    return gcd(b, a % b);
}
// 求数组的最小公倍数
int getLCM(vector<int> nums, int start, int end){
    // 用long long初始化, 防止乘积溢出, 先除后乘就不用担心了
    long long lcm = 1;
    for(int j=start; j<=end; j++){
        // 先除后乘更好一些, 这里为了方便理解没有调换
        lcm = lcm * nums[j] / gcd(lcm, nums[j]);
    }
    return lcm;
}
```

> **完整实现**
```CPP
int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}
int subarrayLCM(vector<int>& nums, int k) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        long long lcm = 1;  // 中间过程用long long防止溢出
        for(int j=i; j<nums.size(); j++){
            lcm = lcm * nums[j] / gcd(lcm, nums[j]);
            if(lcm == k)
                ans++;
            if(lcm > k)
                break;
        }
    }
    return ans;
}
```


- [x] [逐层排序二叉树所需的最少操作数目](https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/)

> 读一遍题就可以发现上**每次遍历一整个layer**的`层序遍历(BFS)`
> 
> 先写一下我的写法, 看了灵神和y总的视频, 都是`环图`求的最小交换次数...但我是"直接放到正确位置"的做法
> 
> 然后继续百度, "使数组有序的最小交换次数", 发现没什么特别的, 就是遇到不匹配的, 交换一次放到指定位置, 直到指针扫完整个列表, **需要注意的是发生交换的话, 指针不能后移**
```CPP
// 交换代码: 不匹配则交换, 使数组有序
for(int i=0; i<layer.size(); ){
    // layer[i]在ta应该在的位置上, 移动指针 i
    if(i == mp[layer[i]]){
        i++;
        continue;
    }
    // 不在正确位置, 与正确位置(mp[layer[i]])上的元素交换, 指针 i 不移动
    else{
        swap(layer[i], layer[mp[layer[i]]]);
        cnt++;
    }
}
```

> 另一个问题是, **应该在的正确位置**怎么求?
> 
> **保存`key`**: 借助`map`的有序性, 将数组第i个元素以`<layer[i], ->`的形式保存, 就自动按`key(元素值)`排序了
> 
> **更新`value`**: 然后遍历`map`, 由于`map`的迭代器是按`key`(数组元素值)递增的, 只需要把`it->second`更新成一个从0开始的自增`idx++`, `mp[layer[i]]`就可以表示`layer[i]`应该在的正确位置了
```CPP
map<int, int> mp;

int idx = 0;
for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
    it->second = idx++;
}
```

> **完整实现**
```CPP
int layerOrder(TreeNode* root){
    int ans = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int fixsize = q.size();
        vector<int> layer;
        for(int i=0; i<fixsize; i++){
            TreeNode* cur = q.front();
            layer.push_back(cur->val);
            q.pop();
            if(cur->left!=NULL)
                q.push(cur->left);
            if(cur->right!=NULL)
                q.push(cur->right);
        }
        map<int, int> mp;
        // 这里只是把key加进去, val后面还会更新
        for(int i=0; i<layer.size(); i++){
            mp[layer[i]] = i;
        }
        // 更新value为"layer[i]应在的正确位置"
        int idx = 0;
        for(map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
            it->second = idx++;
        }
        int cnt = 0;
        for(int i=0; i<layer.size(); ){
            if(i == mp[layer[i]]){
                i++;
                continue;
            }
            else{
                swap(layer[i], layer[mp[layer[i]]]);
                cnt++;
            }
        }
        ans += cnt;
    }
    return ans;
}
int minimumOperations(TreeNode* root) {
    return layerOrder(root);
}
```
