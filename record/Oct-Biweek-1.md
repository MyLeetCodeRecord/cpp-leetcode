#### Biweek 1

##### 1. [删除字符使频率相同](https://leetcode.cn/problems/remove-letter-to-equalize-frequency/)
> todo

##### 2. [最长上传前缀](https://leetcode.cn/problems/longest-uploaded-prefix/): `priority_queue`
> **优先队列**能够保证随时弹出已经收集齐的元素
> **连贯性**通过检查`pq.top()==_size`即可
> `upload / insert`时检查当前连贯性即可
```CPP
priority_queue<int,vector<int>,greater<int> > pq;
int prefix = 0;

LUPrefix(int n) {
}
void upload(int video) {
    pq.push(video);
    while(!pq.empty() && pq.top() == prefix+1){
        prefix++;
        pq.pop();            
    }
}
int longest() {
    while(!pq.empty() && pq.top() == prefix+1){
        prefix++;
        pq.pop();
    }
    return prefix;
}
```


##### 3. [所有数对的异或和](https://leetcode.cn/problems/bitwise-xor-of-all-pairings/): `bit`
> 1. 两组数逐个对应`XOR`, 相当于`nums1`中的每个元素都要参与`nums2.size()`次, `nums2`同理
> 
> 2. `n XOR n = 0` => 如果一个元素参与了偶数次异或运算, 则相当于0; 如果参与了奇数次运算, 相当于只参与了一次

```CPP
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int ans = 0;
    if(size1 % 2 == 1){
        for(int i=0; i<nums2.size(); i++){
            ans = ans ^ nums2[i];
        }
    }
    if(size2 % 2 == 1){
        for(int i=0; i<nums1.size(); i++){
            ans = ans ^ nums1[i];
        }
    }
    return ans;
}
```


##### 4. [满足不等式的数对数目](https://leetcode.cn/contest/biweekly-contest-88/problems/number-of-pairs-satisfying-inequality/)
> todo