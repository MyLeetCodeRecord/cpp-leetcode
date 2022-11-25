#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
int dp[N][N];

int main(){
    string A, B;
    int len1, len2;
    cin>>len1>>len2;
    cin>>A>>B;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}