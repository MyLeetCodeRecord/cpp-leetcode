#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

/* 多重背包之朴素解法 —— 可以在0-1背包的基础上修改
 * foreach i in items:
 *     foreach j in C reverse:
 *         dp[j] = max(dp[j], dp[j-w[i]] + v[i], dp[j-2*w[i]] + 2*v[i] ... , dp[j-s[i]*w[i]] + s[i]*v[i] )
 * 相当于在0-1背包的最内层多加一层对num[i]的遍历
 */

const int N = 110;
int w[N], v[N], s[N];
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=C; j>=0; j--){
            for(int k=1; k<=s[i] && j>=k*w[i]; k++){ // k是有实际意义的, 表示采用的item i的数量; 并且对rest capacity的判断要挪到这一层
                dp[j] = max(dp[j], dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}