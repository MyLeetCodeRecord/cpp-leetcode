#### Weekly 1
##### 1. [可被3整出的偶数的平均值](https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/): `math`

> 思路: `能被3整除的偶数` <-> `能被6整除`
> 
> 注意事项
> - 分母`cnt`可能为0
> - 向下取整

```CPP
int averageValue(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    for(int n: nums){
        if(n % 6==0){
            ans += n;
            cnt++;
        }
    }
    if(cnt == 0)
        return 0;
    return floor(ans/cnt);
}
```

##### 2. [最流行的视频创作者](https://leetcode.cn/problems/most-popular-video-creator/): `map`
> 写着写着就乱了...先整理好思路, 想清楚每个`map`要记录什么

```CPP
vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
    int n = creators.size();
    unordered_map<string, long long> creator_mp;
    unordered_map<string, int> video_mp;
    for(int i=0; i<n; i++){
        creator_mp[creators[i]] += views[i];
        if(video_mp.find(creators[i]) == video_mp.end()){
            video_mp[creators[i]] = i;
        }
        else{
            int t = video_mp[creators[i]];
            if((views[i] > views[t]) || (views[i]==views[t] && ids[i]<ids[t]))
                video_mp[creators[i]] = i;
        }
    }
    long long maxClick = -1;
    for(unordered_map<string, long long>::iterator it=creator_mp.begin(); it!=creator_mp.end(); it++){
        maxClick = max(maxClick, it->second);
    }
    vector<vector<string>> ans;
    for(unordered_map<string, long long>::iterator it=creator_mp.begin(); it!=creator_mp.end(); it++){
        if(it->second == maxClick)
            ans.push_back({it->first, ids[video_mp[it->first]]});
    }
    return ans;
}
```

##### 3. [美丽整数的最小增量](https://leetcode.cn/problems/minimum-addition-to-make-integer-beautiful/)
> 先观察case
> 
> - `16, 6  => 20`
> - `467, 6 => 470 => 500`
> - `8, 2 => 10`
> 
> 发现`+1`就是使
> - 每个位置增大(这不是我们的目的)
> - or 进位(当前bit置0, 下一位+1), 所以这就是`一步`操作
> 
> 基本思路: 不断`进位`(有意义的+1), 就可能使数位和`sum`变小
> 
> 比如`467 -> 470 -> 500 -> 1000`

```CPP
int getBitSum(long long n){
    int ans = 0;
    while(n!=0){
        ans += n%10;
        n /= 10;
    }
    return ans;
}
vector<int> getBits(long long n){
    vector<int> bits;
    while(n!=0){
        bits.push_back(n%10);
        n /= 10;
    }
    bits.resize(13);
    return bits;
}
long long makeIntegerBeautiful(long long n, int target) {
    long long n_origin = n;
    int sum = getBitSum(n);
    vector<int> bits = getBits(n);  // 记录每一位, 进位也要记录下来!
    if(sum <= target)
        return 0;
    // 下面如果用更新后的bits[]来求更新后的n, 会更清晰一些...
    int idx = 0;
    long long base = 1;
    while(sum > target){
        sum = sum - bits[idx] + 1;
        n += (base * (10-bits[idx]));   // 进位后的值, 或者最后用更新后的bits来求新的n
        bits[idx+1] += 1;           // 将进位也记录到bits上
        idx++;
        base *= 10;
    }
    return n - n_origin;
}
```