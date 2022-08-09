#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int n, m, target;
int A[N];
int bElement;
unordered_map<int, int> mpA;    // value -> index

int main(){
    scanf("%d %d %d", &n, &m, &target);
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
        mpA[A[i]] = i;
    }
    for(int i=0; i<m; i++){
        scanf("%d", &bElement);
        if(mpA.find(target-bElement) != mpA.end()){
            cout<<mpA[target-bElement]<<" "<<i<<endl;
            break;
        }
    }
    return 0;
}