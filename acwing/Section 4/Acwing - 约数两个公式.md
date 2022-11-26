#### 约数的两个公式
> 先求质因数分解, 然后用质因数次数计算两个公式
> 
> ![约数公式](/appendix/acwing-%E7%BA%A6%E6%95%B0%E6%80%BB%E5%92%8C.png)

##### 1. 约数个数 ➡️ [推导](https://www.acwing.com/video/296/)

> [Acwing870. 约数个数](https://www.acwing.com/problem/content/872/)的题意是给了几个数`Xi`, 求乘积的约数个数
> 
> **Step 1**: 对每个数字`Xi`的乘积求[质因数分解](/acwing/Section%204/1_%E5%88%86%E8%A7%A3%E8%B4%A8%E5%9B%A0%E6%95%B0.cpp) 🟰 对每个数字`Xi`分别求质因数分解, 用`map`对次数进行累计即可
> 
> **Step 2**: 使用**约数个数公式**求`ans`
> 
> ![约数个数公式](/appendix/acwing-%E7%BA%A6%E6%95%B0%E4%B8%AA%E6%95%B0.png)

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
        // 对x进行质因数分解
        for(int j=2; j<=x/j; j++){
            while(x%j==0){
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1)
            mp[x]++;
    }
    long long ans = 1;
    for(unordered_map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans = ans*(1+it->second);
        ans %= 1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
```

##### 2. 约数总和

> 同样先进行[质因数分解](/acwing/Section%204/1_%E5%88%86%E8%A7%A3%E8%B4%A8%E5%9B%A0%E6%95%B0.cpp), 然后套用公式
> 
> ![约数公式](/appendix/acwing-%E7%BA%A6%E6%95%B0%E6%80%BB%E5%92%8C.png)

```CPP
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

// 一项: Pi^0 + Pi^1 + Pi^2 + ... +Pi^ai = Pi(...(Pi(Pi+1)+1)...)+1
long long getOneItem(int p, int a){
    int i = 0;
    long long ans = 1;
    while(i<a){
        ans = p*ans + 1;
        ans %= 1000000007;
        i++; 
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    unordered_map<int, int> mp;  // prime2freq
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        for(int j=2; j<=x/j; j++){
            // 分解质因数, 每次除尽
            while(x%j==0){
                mp[j]++;
                x /= j;
            }
        }
        if(x > 1)
            mp[x]++;
    }
    // 约数总和公式
    long long ans = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        ans *= getOneItem(it->first, it->second);
        ans %= 1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
```
