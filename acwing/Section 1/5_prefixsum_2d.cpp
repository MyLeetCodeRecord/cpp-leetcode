#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], prefixSum[N][N];

// 二维前缀和a[][]和prefixSum[][]可以相同起点（0 or 1）
// 如果下标从0开始(比如leetcode直接用vector<vector<int>>表示a[][]), 要对左上角点坐标为0进行单独判断
// 如果下标从1开始, 则a[][]和prefixSum[][]可以对齐使用, 并且不需要单独处理边界(相当于padding 0)
int main(){
    scanf("%d %d %d", &n, &m, &q);
    // 构造prefixSum
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            prefixSum[i][j] = a[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
    // 使用prefixSum
    int x1, y1, x2, y2;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", prefixSum[x2][y2]-prefixSum[x1-1][y2]-prefixSum[x2][y1-1]+prefixSum[x1-1][y1-1]);
    }
    return 0;
}