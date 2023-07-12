#include <cstdio>
#include <vector>
using namespace std;

// 约数是成对出现的
void get_divisors(int n){
    vector<int> rev;
    // left直接输出
    for(int i=1; i<=n/i; i++){
        if(n % i == 0){
            printf("%d ", i);
            if(i!=n/i)
                rev.push_back(n/i);
        }
    }
    // right存到栈中, 然后倒序输出
    for(int i=rev.size()-1; i>=0; i--)
        printf("%d ", rev[i]);
    printf("\n");
}

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &m);
        get_divisors(m);
    }
    return 0;
}