#include <cstdio>
#include <iostream>
using namespace std;

/* 分组背包: n个物品组, 每个物品组最多选一个(选一个或者不选)
 * 整体上是 0-1 背包框架
 * - 外层遍历 0～n 物品组
 *     - 内层遍历 C~0 容量
 *         - 最内层选择组内物品
 *               if(j >= w[k])
 *                   dp[j] = max(dp[j], dp[j-w[k]]+v[k])
 */

const int N = 110;
int s, w[N], v[N];      // s[N]是每组物品数量, 每组选择结束后即可清空, 所以可以使用int变量
                        // w[N][N],v[N][N]每组用后清空, 所以只使用一维w[N],v[N]即可
                        // 但这样要求读入和dp计算在一个循环内完成
int dp[N];

int main(){
    int n, C;
    scanf("%d %d", &n, &C);
    // 0-1背包中的物品 => 分组背包中的组
    for(int i=0; i<n; i++){
        scanf("%d", &s);
        // 记录当前第i组的w[N], v[N];
        for(int j=0; j<s; j++){
            scanf("%d %d", &w[j], &v[j]);
        }
        // 0-1背包中的容量(倒序) => 分组背包中的容量(倒序)
        for(int j=C; j>=0; j--){
            // 分组背包: 当前组内选一个或者不选, 求最优解
            for(int k=0; k<s; k++){
                if(j>=w[k]){
                    dp[j] = max(dp[j], dp[j-w[k]]+v[k]);
                }
            }
        }
    }
    cout<<dp[C]<<endl;
    return 0;
}