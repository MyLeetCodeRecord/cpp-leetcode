#### Weekly 1 - No.316

##### 1. [对数组执行操作](https://leetcode.cn/problems/apply-operations-to-an-array/): `模拟` + `双指针`

> 第一步`模拟`, 修改数组值; 第二步将非0元素移动到前面, 0放到末尾
> 
> 移动过程:
> - 新开一个数组空间很简单
> - 不创建额外空间就用`双指针`, 和新建空间的双指针写法其实是一样的...
```CPP
vector<int> applyOperations(vector<int>& nums) {
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            nums[i] += nums[i+1];
            nums[i+1] = 0;
        }
    }
    int i = 0, j = 0;
    while(j<nums.size()){
        if(nums[j]==0)
            j++;
        else
            nums[i++] = nums[j++];
    }
    while(i<nums.size())
        nums[i++] = 0;
    return nums;
}
```


##### 2. [长度为K子数组中的最大和](https://leetcode.cn/problems/maximum-sum-of-distinct-subarrays-with-length-k/): `固定尺寸的滑动窗口` + `map`

> 首先`len`和`K`都是`10e5`, "每次滑动窗口后重新统计窗口内是否有重复元素"的暴力做法肯定不可以
> 
> 窗口每移动一位, 变化的只有窗口左右两个元素, 左出右进, 这样就可以忽略统计窗口内`K`个元素出现频次的重复性工作了
> 
> ![LC6230](/appendix/LC6230.png)
> 
> `Tips`: 在python里可以直接用`for _in, _out in zip(nums[k-1:], nums)`维护**左出右进**的对应关系

> 实现思路:
> - **Step 0**: 用`map`记录每个元素出现频次, 并用`sum`维护窗口内的和, `cnt`记录窗口内频次=1的元素个数(也可以用`mp.erase()`和`mp.size()`取代`cnt`)
> 
> - **Step 1**: 先加进`K`个元素, 作为起点
>   - 记录`mp[nums[i]]`, 并统计互不相同元素`cnt`
> 
> - **Step 2**: 滑动窗口(更新`mp`, `cnt`, `sum`)
>   - 左边`mp[nums[l]]--; sum-=nums[l];`, 如果`mp[nums[l]]==0`, `cnt--`
>   - 右边`mp[nums[r]]++; sum+=nums[r];`, 如果`mp[nums[r]]==1`, `cnt++`

```CPP
long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    long long ans = 0;
    long long sum = 0;
    for(int i=0; i<k; i++){
        mp[nums[i]]++;
        sum += nums[i];
    }
    if(mp.size()==k)
        ans = max(ans, sum);
    for(int l=0; l+k<nums.size(); l++){
        int r = l+k;
        sum -= nums[l];
        mp[nums[l]]--;
        if(mp[nums[l]]==0){
            mp.erase(nums[l]);
        }
        sum += nums[r];
        mp[nums[r]]++;
        if(mp.size() == k)
            ans = max(ans, sum);
    }
    return ans;
}
```


##### 3. [雇佣 K 位工人的总代价](https://leetcode.cn/problems/total-cost-to-hire-k-workers/)

> 需要的操作
> - **长期、动态维护最小值**
> - 去掉最小值
> - 加入新元素
> 
> ➡️ `堆(priority_queue)`
> 
> ❗️维护堆的时候要注意, 有些元素已经使用过了, 要保证两个`priority_queue`中始终有`candidates`个`unused`元素, 并且要注意不要`out of index`
> 
> 如果两个堆中最小值相等, 题目要求取`id`更小的, 其实就是优先选择`heap1`中的元素

```CPP
typedef pair<int, int> PII;
long long totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    long long ans = 0;
    vector<bool> chosen(n, false);
    priority_queue<PII, vector<PII>, greater<PII>> heap1;
    priority_queue<PII, vector<PII>, greater<PII>> heap2;
    int left = 0;
    int right = n-1;
    // 初始化两个heap
    for(int i=0; i<candidates; i++){
        heap1.push({costs[i], i});
        left++;
        heap2.push({costs[costs.size()-1-i], costs.size()-1-i});
        right--;
    }
    // 雇佣 k 个工人
    while(k > 0){
        k--;
        int popped = -1;
        // 如果heap1的top更小, 或者两个堆顶元素相同, 优先弹出heap1
        if(!heap1.empty() && heap1.top().first <= heap2.top().first){
            ans += costs[heap1.top().second];
            popped = heap1.top().second;
            heap1.pop();
        }
        else{
            ans += costs[heap2.top().second];
            popped = heap2.top().second;
            heap2.pop();
        }
        // 标记这个员工被选中过
        chosen[popped] = true;
        // 额外处理heap1.top() == heap2.top()相等
        if(popped == heap2.top().second){
            heap2.pop();
        }
        // 维护两个heap的size==candidates, 直到到超过边界
        while(left < n && heap1.size() < candidates){
            if(left < n && !chosen[left])
                heap1.push({costs[left], left});
            left++;
        }
        while(right >= 0 && heap2.size() < candidates){
            if(right >= 0 && !chosen[right])
                heap2.push({costs[right], right});
            right--;
        }
    }
    return ans;
}
```