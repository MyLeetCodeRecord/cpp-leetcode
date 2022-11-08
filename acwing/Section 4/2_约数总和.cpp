#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

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
    // 约数总和公式
    long long sum = 1;
    for(unordered_map<int, int>::iterator it=mp.begin(); it!=mp.end(); it++){
        sum *= getOneItem(it->first, it->second);
        sum %= 1000000007;
    }
    cout<<sum<<endl;
    return 0;
}