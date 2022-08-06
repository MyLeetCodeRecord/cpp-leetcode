#### 二分法

> 无论左or右端点, 将外层`while(l<r)`固定, 这样返回时不需要考虑返回`l`还是`r`, 因为`l=r`
> 
> 考虑边界时候想一下这张图
> 
> ![acwing-二分](/appendix/acwing-%E4%BA%8C%E5%88%86.png)
> 
> 对于模板中的`mid=(l+r)/2`和`mid=(l+r+1)/2`的选择, 有以下两种判断方式
> 
> * 直观的想法, `binarySearch()`返回值为`l=r=mid(最后一个)`, 如果求符合条件的右端点, 则应该令`mid=(l+r+1)/2`
> 
> * 科学地想🐶, 考虑这样的case, 只有两个元素的数组边界为`l = r - 1`, 初始时`mid = (l + r)/2 = l`, 此时更新`l=mid=l`会陷入死循环, 因此需要`mid = (l+r+1)/2`

##### 左侧端点
```CPP
int binary_search_left(int q[], int l, int r, int target){
    while(l<r){
        int mid = (l+r)/2;
        if(q[mid] < target)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}
```

##### 右侧端点
```CPP
int binary_search_right(int q[], int l, int r, int target){
    while(l<r){
        int mid = (l+r+1)/2;
        if(q[mid] > target)
            r = mid-1;
        else
            l = mid;
    }
    return r;
}
```

##### 二分法解的存在性
> **二分法一定有解**, 即使不存在target
> 
> 以左侧端点求解为例, 如果不存在`q[i]==x`, 将返回第一个大于等于x的数的位置
> 
> 判断返回值是否等于x, 即可判断**题目**是否无解


##### 浮点数二分
> 如果起始`n<1`, 直接使用`mid*mid>=n`判断会有问题, `r=n`, 比如0.01的二次方根是0.1 [只影响代码"启动", 不影响二分本质]
> 
> 解决方法是初始化起始的`r=max(1,n)`, 或者直接取数据边界(e.g. 10000)也可以
> 
> 求奇数方根时, 负数并不影响代码运行

```CPP
// 二分法模板の浮点数二分
// 以acwing790. 数的三次方根为例
double binary_search(double n, double l, double r){
    while(r-l > 1e-8){  // 多取几位
        double mid = (l+r)/2;
        // 体会一下"纯搜索", 不用+1 or +1e(-x)处理边界
        if(mid*mid*mid >= n)
            r = mid;
        else
            l = mid;
    }
    return l;
}

binary_search(n, -max(abs(n), 1.0), max(abs(n),1.0));

// or

binary_search(n, -10000, 10000);
```