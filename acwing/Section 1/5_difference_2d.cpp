#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], diff[N][N];

// 差分数组の初始化: 只需要将a[][]是为全0, 然后逐个元素地插入1*1的矩阵即可
void diff_operation(int x1, int y1, int x2, int y2, int c){
    diff[x1][y1] += c;
    diff[x1][y2+1] -= c;
    diff[x2+1][y1] -= c;
    diff[x2+1][y2+1] += c;
}
int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%d", &a[i][j]);
            // 二维差分的初始化: 执行1*1范围的diff_operation
            diff_operation(i, j, i+1, j+1, a[i][j]);
        }
    }
    // 执行q次操作, 计算差分数组
    int x1, y1, x2, y2, c;
    for(int i=0; i<q; i++){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        diff_operation(x1, y1, x2, y2, c);
    }
    // 求前缀和, 还原到a[][]
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            a[i][j] = diff[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}