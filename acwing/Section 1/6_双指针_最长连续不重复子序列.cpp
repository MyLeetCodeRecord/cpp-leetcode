#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int n;
int a[N];
unordered_map<int, int> mp;

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    // 双指针
    int ans = 1;
    for(int i=0, j=0; i<n; i++){
        // 逐个"+" i
        mp[a[i]]++;
        // 持续"-" j
        while(j<=i && mp[a[i]] > 1){
            mp[a[j]]--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    printf("%d\n", ans);
    return 0;
}
