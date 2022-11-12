#### 质数
##### 1. 试除法判定质数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n==1)
        return false;
    for(int i=2; i<=n/i; i++){
        if(n % i == 0)
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
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
```

##### 2. 分解质因数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

void divide(int n){
    for(int i=2; i<=n/i; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            printf("%d %d", i, cnt);
        }
    }
    if(n!=1)
        printf("%d 1", x);
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        divide(x);
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
bool notPrime[N];

void getPrimes(int n){
    for(int i=2; i<=n; i++){
        if(!notPrime[i]){
            prime[idx++] = i;
            for(int j=2*i; j<=n; j+=i){
                notPrime[i] = true;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    getPrimes(n);
    printf("%d", idx);
    return 0;
}
```

#### 约数
##### 4. 试除法求约数
```CPP
#include <cstdio>
#include <stack>
using namespace std;

void getDivisor(int n){
    stack<int> sk;
    for(int i=1; i<=n/i; i++){
        if(n % i == 0){
            printf("%d ", i;)
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
        getDivisor(x);
    }
    return 0;
}
```

##### 5. 约数个数 [质因数分解 => 公式]
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
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1)
            mp[x]++;
    }
    long long ans = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans *= it->second;
        ans %= 1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 6. 约数总和 [质因数分解 => 公式]
```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int getOneItem(int p, int a){
    long long ans = 1;
    for(int i=0; i<a; i++){
        ans = ans * p + 1;
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
            while(x % j == 0){
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
#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, b % a);   // !!!mod, 不是”-“
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b > a)
            swap(a, b);
        cout<<gcd(a, b)<<endl;
    }
    return 0;
}
```

##### 8. 欧拉函数
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
                while(x % j == 0){
                    x /= j;
                }
            }
        }
        if(x > 1)
            ans = ans / x * (x-1);
        cout<<ans<<endl;
    }
    return 0;
}
```

##### 9. 快速幂
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

// 迭代
int quickPow(int a, int n, int mod){
    long long ans = 1;
    while(n != 0){
        if(n & 1){      // 如果n的当前末位为1
            ans *= a;   // ans乘上当前的a
            ans %= mod;
        }
        a = a * a % mod;// a自乘
        n >>= 1;        // n往右移一位, 表示除以2
    }
    return ans;
}
// 递归
int quickPow(int a, int n, int mod){
    if(n==0)
        return 1;
    if(n & 1)
        return (long long)a * quickPow(a, n-1, mod) % mod;
    else{
        long long half = quickPow(a, n/2, mod);
        return (half * half) % mod;
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


##### 10. 组合数 - 小范围
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 2010;
int dp[N][N];

void calcCombination(){
    for(int i=1; i<N; i++){
        dp[i][0] = 1;
        for(int j=1; j<=i; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j-1];
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    calcCombination(n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        
    }
    return 0;
}
```