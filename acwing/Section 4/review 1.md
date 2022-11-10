##### 1. 试除法判定质数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

bool isPrime(int x){
    if(n==1)
        return false;
    for(int i=2; i<=x/i; i++){
        if(x%i==0)
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


##### 2. 分解质因数
```CPP
#include <cstdio>
#include <iostream>
using namespace std;

void divide(int x){
    for(int i=2; i<=x/i; i++){
        if(x % i == 0){
            int times = 0;
            while(x % i == 0){
                x /= i;
                times++;
            }
            printf("%d %d\n", i, times);
        }
    }
    // 可能剩余
    if(x!=1)
        printf("%d 1\n", x);
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
> 会一个得了

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1000010;
bool st[N];  // true: 合数  false: 质数
int prime[N], idx;

int main(){
    int n;
    scanf("%d", &n);
    // 埃氏筛法
    for(int i=2; i<=n; i++){
        if(st[i]==false){
            prime[idx++] = i;
            for(int j=2*i; j<=n; j+=i){
                st[j] = true;
            }
        }
    }
    cout<<idx<<endl;
    return 0;
}
```


##### 4. 试除法求约数
```CPP
#include <cstdio>
#include <stack>
using namespace std;

void get_divisors(int n){
    stack<int> sk;
    // left直接输出
    for(int i=1; i<=n/i; i++){
        if(n%i==0){
            printf("%d ", i);
            if(i!=n/i)
                sk.push(n/i);
        }
    }
    // right存到栈中, 然后倒序输出
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
        get_divisors(x);
    }
    return 0;
}
```


##### 5. 最大公约数 - 辗转相除法

```CPP
#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b>a)
            swap(b, a);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
```