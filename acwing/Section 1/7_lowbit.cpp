#include <cstdio>
#include <iostream>
using namespace std;

// lowbit: 只保留最低位1
int lowbit(int x){
    return x&(-x);
}
int main(){
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        int cnt = 0;
        while(x!=0){
            x -= lowbit(x);
            cnt++;
        }
        cout<<cnt<<" ";
    }
    return 0;
}