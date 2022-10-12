#include <cstdio>
#include <iostream>
using namespace std;

/* 多重背包之朴素解法 —— 将s[i]的 K 维压缩到 lgK 维
 * 一个数字n可以由"二进制数组"表示, 即{1,2,4, ...}
 * 那么最少需要的数字数量就是, 1+2+...+2^(x+1) >= n, 1+2+...+2^x < n   =>   x
 * 取前{1, 2, ... , 2^x} 以及 剩余部分n-sum(1, 2, ... , 2^x)
 * 一共(x+1+1)个数
 */

int N = 1010, M = 2010;
int w[N], v[N], s[N];
int dp[M];
int n, C;

int main(){
    scanf("%d %d", &n, &C);
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &w[i], &v[i], &s[i]);
    }
    vector<pair<int, int> > goods;
    // 这里只是在"表示 / 重新组织"items, 没有capacity的事情
    for(int i=0; i<n; i++){
        for(int k=1; k<=s[i]; k*=2){
            s[i] -= k;
            goods.push_back({w[i]*k, v[i]*k);
        }
        if(s[i] > 0)
            goods.push_back({w[i]*s[i], v[i]*s[i]});
    }
    // 0-1背包
    for(auto good : goods){
        for(int j=C; j>=good[0]; j--){
            dp[j] = max(dp[j], dp[j-good[0]]+good[1]);
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}