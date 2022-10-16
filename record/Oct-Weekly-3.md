#### Weekly 3

##### 1. [与对应负数同时存在的最大正整数](https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/)
```CPP
int findMaxK(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=nums.size()-1; i>=0; i--){
        for(int j=0; j<nums.size(); j++){
            if(nums[i]==-1*nums[j])
                return nums[i];
        }
    }
    return -1;
}
```

##### 2. [反转之后不同整数的数目](https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations/): `set`
```CPP
unordered_set<int> st;

int getReverse(int n){
    st.insert(n);
    int num = 0;
    while(n!=0){
        num *= 10;
        num += n % 10;
        n = n / 10;
    }
    st.insert(num);
    return num;
}
int countDistinctIntegers(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        getReverse(nums[i]);
    }
    return st.size();
}
```

##### 3. [反转之后的数字和](https://leetcode.cn/problems/sum-of-number-and-its-reverse/): `1e5 => 暴力`
```CPP
unordered_set<int> st;
int getReverseSum(int n){
    int tmp = n;
    int num = 0;
    while(n!=0){
        num *= 10;
        num += n % 10;
        n = n / 10;
    }
    st.insert(tmp+num);
    return tmp+num;
}
bool sumOfNumberAndReverse(int num) {
    for(int i=1; i<=100000; i++){
        int sum = getReverseSum(i);
        if(sum==num)
            return true;
    }
    return st.find(num)!=st.end();
}
```

##### 4. [统计定界子数组的数目](https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/): `滑动窗口` `双指针`

```CPP
long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;
    int smin = 0, smax = 0; // 窗口内的minK和maxK的数量
    for(int i=0, last=0, j=0; i<nums.size(); i++){
        // 遇到超出minK~maxK的数, 重置窗口
        if(nums[i] < minK || nums[i] > maxK){
            j = i+1;
            last = i+1;
            smin = 0;
            smax = 0;
            continue;
        }
        // 逐个向右扩大窗口的过程中, 统计minK和maxK个数
        if(nums[i]==minK)
            smin++;
        if(nums[i]==maxK)
            smax++;
        // 收缩左侧窗口, 从last到最后一个minK或者maxK的位置
        while(j<=i){
            if(nums[j]==minK)
                smin--;
            if(nums[j]==maxK)
                smax--;
            if(smin==0 || smax==0){
                if(nums[j]==minK)
                    smin++;
                if(nums[j]==maxK)
                    smax++;
                break;
            }
            j++;
        }
        if(smin!=0 && smax!=0)
            ans += j-last+1;
    }
    return ans;
}
```