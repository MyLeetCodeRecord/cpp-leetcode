#### 筛质数

##### 方法一: 朴素筛法 -> 埃式筛法 - `O(nlogn)`
> 思路: 从小到大, 把每个数的倍数筛掉, 剩下的数没有因数, 所以是质数

```CPP
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
```


##### 方法二: 线性筛法 - `O(n)`
```CPP
/* 线性筛法 O(n)
 * n只会被它的最小质因子筛选掉, 不会重复筛选
 */
void getPrimes_linear(int n){
    for(int i=2; i<=n; i++){
        if(!state[i])
            prime[idx++] = i;
        for(int j=0; prime[j]<=n/i; j++){
            state[prime[j]*i] = true;
            if(i%prime[j]==0)       // primes[j]是i的最小质因子
                break;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    getPrimes_linear(n);
    printf("%d", idx);
    return 0;
}
```