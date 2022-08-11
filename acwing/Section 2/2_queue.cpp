#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int que[N];
int head = 0, tail = 0;

void insert(int val){
    que[tail++] = val;
}
bool isEmpty(){
    return (head == tail);
}
void pop(){
    head = min(head+1, tail);
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
            cout<<que[head]<<endl;
        }
    }
    return 0;
}