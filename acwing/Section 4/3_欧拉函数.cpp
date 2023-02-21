#include <cstdio>
#include <iostream>
using namespace std;

/* 欧拉函数: 用公式做 */
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        int ans = x;
        // 分解质因数
        for(int j=2; j<=x/j; j++){
            if(x % j==0){
                ans = ans / j * (j-1);
                // 每次除尽
                while(x % j==0){
                    x /= j;
                }
            }
        }
        if(x > 1)
            ans = ans / x *(x-1);
        cout<<ans<<endl;
    }
    return 0;
}