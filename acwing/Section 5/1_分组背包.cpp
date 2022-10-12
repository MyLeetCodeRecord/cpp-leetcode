#include <cstdio>
#include <iostream>
using namespace std;

const int N = 110;
int n, C;
int s[N], w[N], v[N];
int dp[N];

int main(){
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d", &s[i]);
        for(int j=0; j<s[i]; j++){
            scanf("%d %d", &w[j], &v[j]);
        }
        for(int j=C; j>=0; j--){
            for(int k=0; k<s[i]; k++){
                if(j>=w[k]){
                    dp[j] = max(dp[j], dp[j-w[k]] + v[k]);
                }
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}