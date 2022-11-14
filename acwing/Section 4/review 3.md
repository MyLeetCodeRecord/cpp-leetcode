###### 1. 试除法判定质数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n==1)
        return false;
    for(int j=2; j<=n/j; j++){
        if(n % j == 0)
            return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(isPrime(x))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
```

##### 2. 分解质因数 - 直接打印
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

void dividePrime(int x){
    for(int j=2; j<=x/j; j++){
        int time = 0;
        if(x % j == 0){
            while(x % j == 0){
                time++;
                x /= j;
            }
            cout<<j<<" "<<time<<endl;
        }
        if(x > 1)
            cout<<x<<" 1"<<endl;
        cout<<endl;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        dividePrime(x);
    }
    return 0;
}
```

##### 3. 筛质数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
int prime[N], idx=0;
bool st[N];     // true-合数; false-质数

void getPrimes(int n){
    for(int i=2; i<=n; i++){
        if(!st[i]){
            prime[idx++] = i;
            for(int j=2*i; j<=n; j+=i){
                st[j] = true;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n)
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        getPrimes(x);
        cout<<idx<<endl;
    }
    return 0;
}
```

##### 4. 试除法求约数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

void getDivisor(int n){
    stack<int> sk;
    for(int i=1; i<=n/i; i++){
        if(n%i==0){
            printf("%d", i);
            if(i != n/i)
                sk.push(n/i);
        }
    }
    while(!sk.empty()){
        printf("%d ", sk.top());
        sk.pop();
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
    }
    return 0;
}
```

##### 5. 约数个数
> 先进行质因数分解 => $p_1^{a_1}*p_2^{a_2}*···*p_k^{a_k}$
> 
> 约数个数 = $(a_1+1)*(a_2+1)*...*(a_k+1)$

```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        for(int j=2; j<=x/j; j++){
            while(x % j == 0){
                x /= j;
                mp[j]++;
            }
        }
        if(x > 1)
            mp[x]++;
    }
    long long ans = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans *= (it->second+1);
        ans %= 1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 6.约数总和
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int getOneItem(int p, int a){
    long long ans = 1;  // 中间乘积结果用long long防止溢出
    for(int i=0; i<a; i++){
        ans = ans*p + 1;
        ans %= 1000000007;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        for(int j=2; j<=x/j; j++){
            while(x % j==0){
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1)
            mp[x]++;
    }
    long long ans = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans *= getOneItem(it->first, it->second);
        ans %= 1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 7. 最大公约数
```CPP
int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a%b);
}
```

##### 8. 最小公倍数
```CPP
int lcm(int a, int b){
    return a / gcd(a,b) * b;
}
```

##### 9. 欧拉函数 - 1~N中与N互质的数的个数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        long long ans = x;
        for(int j=2; j<=x/j; j++){
            if(x % j == 0){
                ans = ans / j * (j-1);
                while(x % j == 0)
                    x /= j;
            }
        }
        if(x > 1)
            ans = ans / j * (j-1);
        cout<<ans<<endl;
    }
    return 0;
}
```

##### 10. 快速幂
```CPP
// 迭代
int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n>>=1;
    }
    return ans;
}
```

```CPP
// 递归
int quickPow(int a, int n, int mod){
    if(n==0)
        return 1;
    if(n & 1)
        return (long long)a * quickPow(a, n-1, mod) % mod;
    else{
        int half = quickPow(a, n/2, mod);
        return (long long)half * half % mod;
    }
}
```

##### 11. 快速幂求逆元 - `quickPow(a, p-2, p)`
```CPP
int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1){
            ans = ans * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, p;
        scanf("%d %d", &a, &p);
        // 互质才有乘法逆元
        if(a % p != 0)
            cout<<quickPow(a, p-2, p)<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}
```

##### 12. 能被整除的数 - 容斥原理
```CPP
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
    // 用二进制表示集合性质(第j位为1表示能整除primes[j], 为0表示不能整除primes[j])
    for(int i=1; i<(1<<m); i++){
        int cnt = 0;        // 二进制状态 i 中 1 的个数
        long long t = 1;    // 乘积 = 容斥原理中的交集
        for(int j=0; j<m; j++){
            if(i >> j & 1){
                cnt++;
                t *= prime[j];
                if(t > n){
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
```

##### 13. 组合数I
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 2010;
int dp[N][N];

void calcCombination(){
    for(int i=0; i<N; i++){
        dp[i][0] = 1;
        for(int j=1; j<=i; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            dp[i][j] %= 1000000007;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    calcCombination();
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cout<<dp[a][b]<<endl;
    }
    return 0;
}
```

##### 14. 组合数II - `C(a,b)=a!` + 乘法逆元
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
const int MOD = 1000000007;
int fact[N], infact[N];

int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n!=0){
        if(n & 1)
            ans = ans * a % mod;
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans;
}
void prepareFact(){
    fact[0] = 1;
    infact[0] = 1;
    for(int i=1; i<N; i++){
        fact[i] = (long long)fact[i-1] * i % MOD;
        infact[i] = (long long)infact[i-1] * quickPow(i, MOD-2, MOD) % MOD;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    prepareFact();
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        long long ans = (long long)fact[a] * infact[b] % MOD * infact[a-b] % MOD;
        cout<<ans<<endl;
    }
    return 0;
}
```