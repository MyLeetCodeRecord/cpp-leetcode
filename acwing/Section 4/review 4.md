##### 1. 试除法判定质数
```CPP
bool isPrime(int x){
    if(x==1)
        return false;
    for(int j=2; j<=x/j; j++){
        if(x % j == 0)
            return false;
    }
    return true;
}
```

##### 2. 分解质因数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

void dividePrime(int x){
    for(int j=2; j<=x/j; j++){
        if(x % j == 0){
            int time = 0;
            while(x % j == 0){
                x /= j;
                time++;
            }
            printf("%d %d\n", j, time);
        }
    }
    if(x > 1)
        printf("%d 1\n", x);
    printf("\n");
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

##### 3. 筛质数 - 埃氏筛法
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
bool state[N];          // true: 合数; false: 质数
int prime[N], idx=0;    // 存储答案

void getPrimes(int n){
    for(int i=2; i<=n; i++){
        if(!state[i]){
            prime[idx++] = i;
            for(int j=i*2; j<=n; j+=i){
                state[j] = true;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    getPrime(n);
    cout<<idx<<endl;
    return 0;
}
```

##### 4. 试除法求约数
```CPP
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 约数都是成对出现的(除了根号x)
void getDivisors(int x){
    vector<int> half;
    for(int i=1; i<=x/i; i++){
        if(x % i == 0){
            printf("%d ", i);
            if(x / i != i)
            half.push_back(x/i);
        }
    }
    reverse(half.begin(), half.end());
    for(int i: half){
        printf("%d ", i);
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        getDivisors(x);
    }
    return 0;
}
```

##### 5. 求约数个数 - 分解质因数 - 公式
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

void getPrimes(int n){
    for(int j=2; j<=n/j; j++){
        while(n % j == 0){
            mp[j]++;
            n /= j;
        }
    }
    if(n > 1)
        mp[n]++;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x = 0;
        scanf("%d", &x);
        getPrimes(x);
    }
    long long ans = 0;
    for(unordered_map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans *= (it->second+1);
        ans %= 1000000007;
    }
    return 0;
}
```

##### 6. 约数总和 - 质因数分解 - 公式
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;

void getPrimes(int n){
    for(int j=2; j<=n/j; j++){
        while(n % j == 0){
            mp[j]++;
            n /= j;
        }
    }
    if(n > 1)
        mp[n]++;
}
long long getOneItem(int p, int a){
    long long ans = 1;
    int i = 0;
    while(i < a){
        ans = ans * p + 1;
        ans %= 1000000007;
        i++;
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        getPrimes(x);
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
    return gcd(b, a % b);
}
```

##### 8. 最小公倍数
```CPP
int lcm(int a, int b){
    return a / gcd(a, b) * b;
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
        if(x != 1)
            ans = ans / x * (x-1);
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
        if(n & 1){
            ans = ans * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans;
}
```

```CPP
// 递归
int quickPow(int a, int n, int mod){
    if(n==0)
        return 1;
    if(n % 2 == 1)
        return (long long)a * quickPow(a, n-1, mod);
    else{
        long long half = quickPow(a, n/2, mod);
        return half * half % mod;
    } 
}
```

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

int quickPow(int a, int n, int mod){
    long long ans = 0;
    while(n != 0){
        if(n & 1){
            ans = ans * a % mod;
        }
        a = (long long)a * a % mod;
        n >>= 1;
    }
    return ans;
}
int quickPow(int a, int n, int mod){
    if(n==0)
        return 1;
    if(n & 1)
        return (long long)a * quickPow(a, n-1, mod) % mod;
    else{
        long long half = quick(a, n/2, mod);
        return half * half % mod;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);
        cout<<quickPow(a, b, p)<<endl;
    }
    return 0;
}
```

##### 11. 快速幂求逆元
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
    // 并不是按等式顺序, 而是遍历每一项, 计算值和符号
    long long ans = 0;
    for(int i=1; i<(1<<m); i++){
        int cnt = 0;
        long long t = 1;
        for(int j=0; j<m; j++){
            if(i>>j & 1){
                cnt++;
                t *= prime[j];
                if(t > n){
                    t = -1;
                    break;
                }
            }
        }
        if(t==-1)
            continue;
        else if(cnt & 1)
            ans += t;
        else
            ans -= t;
    }
    cout<<ans<<endl;
    return 0;
}
```

##### LC223. 矩形面积
```CPP
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ay2-ay1) * (ax2-ax1);
    int area2 = (by2-by1) * (bx2-bx1);
    if(ax1>=bx2 || bx1>=ax2 || ay1>=by2 || by1>=ay2){
        return area1 + area2;
    }
    else{
        int unionArea = abs(min(ay2, by2) - max(ay1, by1)) * abs(min(ax2, bx2), max(ax1, bx1));
        return area1 + area2 - unionArea;
    }
}
```

##### LC878. 第N个神奇数字
```CPP
typedef long long LL;
int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a%b);
}
long long lcm(int a, int b){
    return a / gcd(max(a,b), min(a,b)) * b;
}
// 容斥原理 + 二分查找（左端点）
int nthMagicalNumber(int n, int a, int b) {
    LL l = 1;
    LL r = (LL)n * min(a, b);
    while(l < r){
        LL mid = (l+r)/2;
        LL magic = mid/a + mid/b - mid/(lcm(a,b));
        if(magic < n)
            l = mid + 1;
        else
            r = mid;
    }
    return l % 1000000007;
}
```

##### 13. 求组合数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 2010;
int dp[N][N];

void getCombination(){
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
    getCombination();
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        cout<<dp[a][b]<<endl;
    }
    return 0;
}
```

##### 14. 求组合数II
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
const int MOD = 1000000007;
int fact[N], infact[N];

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
}
```