#include <cstdio>
#include <iostream>
using namespace std;

const int N = 50010;
int father[N];
int generation[N];

void init_ufs(int n){
    for(int i=1; i<=n; i++){
        father[i] = i;
    }
}
int find_ufs(int u){
    if(father[u] != u){
        int tmp = find_ufs(father[u]);
        generation[u] += generation[father[u]];
        father[u] = tmp;
    }
    return father[u];
}
int main(){
    int n, k, ans = 0;
    scanf("%d %d", &n, &k);
    init_ufs(n);
    for(int i=0; i<k; i++){
        int relation, x, y;
        scanf("%d %d %d", &relation, &x, &y);
        if(x>n || y>n){
            ans++;
        }
        else{
            int px = find_ufs(x);
            int py = find_ufs(y);
            // 同类
            if(relation==1){
                // 已经在同一个集合, x和y是同类, 需要两者差 mod 3为0
                if(px==py && (generation[x]-generation[y])%3!=0){
                    ans++;
                }
                // 尚未在同一个集合=> 合并使py作为统一的根节点, 并保证 distance{x->px->py} = distance{y->py} + 3x
                else if(px != py){
                    father[px] = py;
                    generation[px] = generation[y]-generation[x];
                }
            }
            // 非同类, x吃y
            else{
                // 已经在同一个集合, x吃y应表示为 (d[x]-d[y]-1)%3==0, 否则为假话
                if(px==py && (generation[x]-generation[y]-1)%3!=0){
                    ans++;
                }
                // 尚未在同一个集合=> 合并使py作为统一的根节点, 并保证(distance{x->px->py} - distance{y->py} - 1)%3 == 0
                else if(px != py){
                    father[px] = py;
                    generation[px] = generation[y] - generation[x] + 1;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}