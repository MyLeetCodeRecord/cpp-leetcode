#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mp;
void dividePrimes(int n;){
    for(int i=2; i<=x/i; i++){
        // 分解质因数, 每次除尽
        while(x%i==0){
            mp[i]++;
            x /= i;
        }
    }
    if(x > 1)
        mp[x]++;
}
long long getOneItem(int p, int a){
    long long ans = 1;
    for(int i=0; i<a; i++){
        ans = p * ans + 1;
        ans %= 1000000007;
    }
    return ans;
}

int main(){
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        dividePrimes(x);
    }
    // 约数总和公式
    long long sum = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        sum *= getOneItem(it->first, it->second);
        sum %= 1000000007;
    }
    cout<<sum<<endl;
    return 0;
}