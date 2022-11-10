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