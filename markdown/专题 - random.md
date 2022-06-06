#### 随机数

##### 投针试验
[LC478. 在圆内随机生成点](LC478.%20在圆内随机生成点.md)

```CPP
class Solution {
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    vector<double> randPoint() {
        double xx = 1;
        double yy = 1;
        // 直到 a^2+b^2 <= r^2
        do {
            // 2.0: 作用一是double, 作用二是结合-1达到正负的效果
            xx = 2.0*rand()/RAND_MAX - 1;
            yy = 2.0*rand()/RAND_MAX - 1;
        } while(xx*xx + yy*yy > 1);
        return {x + r*xx, y + r*yy};
    }
};
```

##### 蓄水池抽样
[LC398. 随机数索引](/workspace/398.%E9%9A%8F%E6%9C%BA%E6%95%B0%E7%B4%A2%E5%BC%95.cpp)

> [蓄水池抽样](https://blog.csdn.net/wq3095435422/article/details/124413184)讲解
> 
> 场景: 当内存有限，数据长度很大，甚至未知，那么如何从中随机选取k个数据，并且要求是等概率

```CPP
int pick(int target) {
    int ans = 0;
    int cnt = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == target) {
            cnt++; // 第 cnt 次遇到 target
            if (rand() % cnt == 0) {
                ans = i;
            }
        }
    }
    return ans;
}
```
