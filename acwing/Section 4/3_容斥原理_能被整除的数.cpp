#include <cstdio>
#include <iostream>
using namespace std;

const int N = 16;
int prime[N];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d", &prime[i]);
    }
    // 容斥原理
    long long ans = 0;
    for(int i=1; i<(1<<m); i++){
        int cnt = 0;        // 二进制状态 i 中 1 的个数
        long long t = 1;    // 乘积 = 容斥原理中的交集
        for(int j=0; j<m; j++){
            if(i >> j & 1){
                cnt++;
                t *= prime[j];
                if(t > n){  // 大于n的数不能被n整除
                    t = -1;
                    break;
                }
            }
        }
        if(t == -1){
            continue;
        }
        else if(cnt & 1){
            ans += n/t;
        }
        else{
            ans -= n/t;
        }
    }
    cout<<ans<<endl;
    return 0;
}