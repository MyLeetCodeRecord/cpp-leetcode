// 双指针做法
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int A[N], B[N], n, m, x;

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    for(int j=0; j<m; j++)
        scanf("%d", &B[j]);
    for(int i=0, j=m-1; i<n, j>=0; i++){
        while(j>=0 && A[i]+B[j]>x){
            j--;
        }
        if(A[i]+B[j]==x){
            printf("%d %d", i, j);
            break;
        }
    }
    return 0;
}

/* // map映射做法
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mpA; // val->key的反向映射
int aElement, bElement, n, m, x;

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &aElement);
        mpA[aElement] = i;
    }
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(mpA.find(x-bElement)!=mpA.end()){
            printf("%d %d\n", mpA[x-bElement], j);
            break;
        }
    }
    return 0;
}
*/