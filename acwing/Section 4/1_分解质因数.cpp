#include <cstdio>
#include <iostream>
using namespace std;

/* 分解质因数
 * 暴力法 => O(n) 超时
 * for(int i=2; i<=n; i++){ ... }
 * 性质: n 最多只包含一个大于sqrt(n)的质数因子, 就是它本身[对它做特殊判断]
 * for(int i=2; i<=n/i; i++){ ... }
 * if(n>1)
 *   // 单独处理
*/
void divide(int n){
    for(int i=2; i<=n/i; i++){
        if(n % i==0){
            // 对当前因子 i 计次
            int times = 0;
            while(n % i==0){
                n /= i;
                times++;
            }
            printf("%d %d\n", i, times);
        }
    }
    if(n > 1)
        printf("%d %d\n", n, 1);
    printf("\n");
}

int main(){
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        divide(x);
    }
    return 0;
}