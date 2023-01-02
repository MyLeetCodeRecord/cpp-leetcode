#### Biweek 1

##### 1. [删除字符使频率相同](https://leetcode.cn/problems/remove-letter-to-equalize-frequency/)
> 统计做法要做N多特判断, `wa`了5次
> 
> 第一题的数据范围`2<=word.length<=100`, 而且只删除一个字母, 可以直接枚举每个字母...
> 
> 算了...考场上的粘过来吧...累了

```CPP
bool equalFrequency(string word) {
    map<char, int> mp;

    for(int i=0; i<word.size(); i++){
        mp[word[i]]++;
    }
    int minCnt = INT_MAX;
    int maxCnt = INT_MIN;
    for(map<char,int>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second > maxCnt)
            maxCnt = it->second;
        if(it->second < minCnt){
            minCnt = it->second;
        }
    }
    int maxNums = 0;
    int minNums = 0;
    for(map<char,int>::iterator it=mp.begin(); it!=mp.end(); it++){
        if(it->second == maxCnt)
            maxNums ++;
        if(it->second == minCnt)
            minNums += it->second;
    }
    
    if(minCnt == maxCnt && maxNums==1){
        return true;
    }
    if(minCnt == 1 && maxCnt == 1){
        return true;
    }
    if(maxCnt-minCnt > 1){
        return false;
    }
    else{
        if(minCnt==1 && minNums==1){
            return true;
        }
        if(maxCnt - minCnt == 0){
            return false;
        }
        if((maxCnt - minCnt == 1) && (maxNums == 1)){
            return true;
        }
    }
    return false;
}
```

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
> 
> 3. 检查一下数据范围, `int` is ok.

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
> - 方法一: 树状数组
> - 方法二: 归并排序
> 
> 天呐, 又读了一遍题, 太难了以后再说吧🫢 下班💨
