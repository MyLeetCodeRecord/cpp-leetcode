#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int A[N], bElement;

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    int idxA = 0;
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(bElement==A[idxA])
            idxA++;
        if(idxA == n)   // 提前终止(一方面是时间因素, 另一方面A[]末尾有0填充, 会出现错误)
            break;
    }
    if(idxA==n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}