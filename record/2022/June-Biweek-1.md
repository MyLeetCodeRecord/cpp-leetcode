#### Biweek 1

##### 1. 强密码检验器 II

> [题目](https://leetcode.cn/problems/strong-password-checker-ii/) - `字符串`
>
> 搞了个`break`, 罚时罚时👿
> 
> 第一题为什么要搞break

```CPP
bool strongPasswordCheckerII(string password) {
    bool has_A = false;
    bool has_a = false;
    bool hasNum = false;
    bool hasSpecial = false;
    string special = "!@#$%^&*()-+";
    if(password.size() < 8)
        return false;
    for(int i=0; i<password.size(); i++){
        if(i!=0 && password[i] == password[i-1])
            return false;
        if(password[i]>='0' && password[i]<='9')
            hasNum = true;
        if(password[i]>='a' && password[i]<='z')
            has_a = true;
        if(password[i]>='A' && password[i]<='Z')
            has_A = true;
        if(special.find(password[i])!=special.npos)
            hasSpecial = true;
    }
    return has_A && has_a && hasNum && hasSpecial;
}
```

##### 2. 咒语和药水的成功对数
> [题目](https://leetcode.cn/problems/successful-pairs-of-spells-and-potions/) - `二分法`应用
> 
> Really really struggling...
> 
> 初始想法: 在两层遍历的框架下, potions排序可以提前结束 ==> 超时
> 
> 于是, `lower_bound`终于想起来用了, 虽然还得现查...使用`二分法`定位`potions`中第一个**大于等于 success / spells[i] 的位置**, 比它大的都是可以与`spells[i]`组合的potion
> 
> 然后边界处理又很麻烦...单纯取整做不到, 需要区别处理`能整除`和`不能整除`两种情况
>
> 还要注意的问题是`数字类型`, `long long`比较保险

```CPP
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans(spells.size(), 0);
    for(int i=0; i<spells.size(); i++){
        int spell = spells[i];
        long long threshold = success / spell;
        // 不能整除
        if(success % spell != 0){
            threshold += 1;
        }
        int pos = potions.end() - lower_bound(potions.begin(), potions.end(), threshold);
        ans[i] = pos;
    }
    return ans;
}
```
