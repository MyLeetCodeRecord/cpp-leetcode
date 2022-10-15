#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string s1, s2;
int dp[N][N];

int main(){
    int len1, len2;
    cin>>len1>>s1;
    cin>>len2>>s2;
    dp[0][0] = 0;
    // 别忘了初始化dp[i][0]和dp[0][j]
    for(int i=1; i<=len1; i++)
        dp[i][0] = i;
    for(int j=1; j<=len2; j++)
        dp[0][j] = j;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}