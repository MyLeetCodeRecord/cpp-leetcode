#include <cstdio>
#include <iostream>
using namespace std;

// 二分法模板の浮点数二分, 唯一需要改变的是check()函数
double binary_search(double target, double l, double r){
    while(r-l > 1e-8){  // 多取几位
        double mid = (l+r)/2;
        // 体会一下"纯搜索", 不用+1 or +1e(-x)处理边界
        if(mid*mid*mid >= target)
            r = mid;
        else
            l = mid;
    }
    return l;
}

// 如果起始n<1, 令初始r=n, 直接使用mid*mid>=n判断会有问题, 比如0.01的二次方根是0.1>0.01 【只影响代码”启动”, 不影响二分本质】
// 解决方法是初始化起始的r=max(1,n), 或者直接取数据边界(e.g. 10000)也可以
// 求奇数方根时, 负数并不影响代码运行(不影响在二分数轴上左右的归属)
int main(){
    double n;
    scanf("%lf", &n);
    printf("%lf\n", binary_search(n, -10000.0, 10000.0));
    return 0;
}