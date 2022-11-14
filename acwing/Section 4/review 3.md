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

##### 11. 能被整除的数 - 容斥原理

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
    long long ans = 0;
    // 1<<m = 10...0(m个0), 所以不取等号
    for(int i=0; i<(1<<m); i++){
        int cnt = 0;
        long long t = 1;
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
        // 统计个数
        if(t==-1)
            continue;
        else if(cnt & 1)
            ans += n/t;
        else
            ans -= n/t;
    }
    cout<<ans<<endl;
    return 0;
}
```