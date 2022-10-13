#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int a[N];
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        dp[i] = 1;
    }
    int ans = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}