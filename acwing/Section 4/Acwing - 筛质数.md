#### 筛质数

##### 方法一: 朴素筛法 -> 埃式筛法 - `O(nloglogn)`
> 朴素筛法: 从小到大, 把每个数的倍数筛掉, 剩下的数没有因数, 所以是质数
> - 每个非质数会被**所有因子**标记
> - 标记次数: `n/2 + n/3 + n/4 + ··· + 1 = O(nlnn)`
> 
> 埃式筛法: 进一步, 只筛掉质数的倍数, 减少一定量的重复标记
> - 每个数被**所有质因子**标记, (但`6`还是会被**所有质因子**`2`和`3`都标记一遍)
> - 标记次数: `n/2 + n/3 + n/5 + ···`, 只保留质数对应的项 (质数定理: 1~n中约有`n/lnn`个质数)

```CPP
int prime[N], idx = 0;
bool state[N];
int getPrimes(int n){
    for(int i=2; i<=n; i++){
        // 当前数 i 未被标记为非质数, 那说明它是质数
        if(!state[i]){
            prime[idx++] = i;
            // 埃氏筛法: 只标记「质数」的倍数
            for(int j=2*i; j<=n; j+=i){
                state[j] = true;
            }
        }
    }
    return idx;
}
```


##### 方法二: 线性筛法 - `O(n)`
> `n`只会被它的**最小质因子**筛选掉, 不会重复筛选

```CPP
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