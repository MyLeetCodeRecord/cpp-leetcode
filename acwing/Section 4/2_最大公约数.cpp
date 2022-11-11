#include <cstdio>
#include <cmath>
using namespace std;

// 最大公约数 - 辗转相除法
// gcd(a, b) = gcd(b, a%b)
int gcd(int a, int b){
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(b > a)
            swap(a, b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}