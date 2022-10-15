#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int editDistance(string& s1, string& s2){
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
        dp[i][0] = i;
    for(int j=0; j<=n; j++)
        dp[0][j] = j;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }
    return dp[m][n];
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    string list[n];
    for(int i=0; i<n; i++)
        cin>>list[i];
    for(int j=0; j<m; j++){
        string query;
        int thershold;
        int cnt = 0;
        cin>>query>>thershold;
        for(int i=0; i<n; i++){
            if(editDistance(list[i], query) <= thershold){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}