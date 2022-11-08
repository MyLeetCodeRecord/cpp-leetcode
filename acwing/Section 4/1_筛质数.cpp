#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;
int prime[N], idx = 0;
bool state[N];
void getPrimes(int n){
    for(int i=2; i<=n; i++){
        // 当前数 i 未被标记为非质数, 那说明它是质数
        if(!state[i]){
            prime[idx++] = i;
            // 埃氏筛法: 只标记“质数”的倍数
            for(int j=2*i; j<=n; j+=i){
                state[j] = true;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    getPrimes(n);
    cout<<idx<<endl;
    return 0;
}