#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int sk[N];
int top = 0;    // 下一个可使用位置

void insert(int val){
    sk[top++] = val;
}
bool isEmpty(){
    return (top==0);
}
void pop(){
    top = max(0, top-1);
}
int main(){
    int n = 0;
    cin>>n;
    string op;
    int x;
    for(int i=0; i<n; i++){
        cin>>op;
        if(op == "push"){
            cin>>x;
            insert(x);
        }
        else if(op == "pop"){
            pop();
        }
        else if(op == "empty"){
            cout<<(isEmpty()?"YES":"NO")<<endl;
        }
        else{
            cout<<sk[top-1]<<endl;
        }
    }
    return 0;
}