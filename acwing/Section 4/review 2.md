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