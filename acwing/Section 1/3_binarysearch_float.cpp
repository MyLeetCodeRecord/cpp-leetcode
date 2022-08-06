#include <cstdio>
#include <iostream>
using namespace std;

double n;

// 二分法模板の浮点数二分, 唯一需要改变的是check()函数
int binary_search(double n, double l, double r){
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

int main(){
    cin>>n;
    printf("%lf\n", binary_search(n, -10000.0, 10000.0));
    return 0;
}