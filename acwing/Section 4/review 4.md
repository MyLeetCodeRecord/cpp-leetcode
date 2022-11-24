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

```
