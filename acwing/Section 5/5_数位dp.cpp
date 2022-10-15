#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getRange(vector<int> bits, int l, int r){
    int num = 0;
    for(int i=l; i>=r; i--){
        num *= 10;
        num += bits[i];
    }
    return num;
}
int power10(int x){
    int num = 1;
    while(x!=0){
        num *= 10;
        x--;
    }
    return num;
}
int count(int a, int x){
    if(a==0)
        return 0;
    vector<int> bits;    // 保存各个数位 (低位在前)
    while(a!=0){
        bits.push_back(a % 10);
        a /= 10;
    }
    int ans = 0;
    int n = bits.size();
    for(int i=n-1-(x==0); i>=0; i--){
        // case 1:
        // - 如果x是0, 001~abc-1,0,1000 => (abc-1)*1000
        // - 如果x非0, 000~abc-1,x,1000 => abc*1000
        if(i != n-1){
            ans += getRange(bits, n-1, i+1) * power10(i);
            if(x==0){
                ans -= power10(i);
            }
        }
        // case 2: abc,x,
        // (2-1): d<x => 0, skip.
        // (2-2): d=x => abc,x=d,efg+1
        if(bits[i] == x)
            ans += getRange(bits, i-1, 0) + 1;
        // (2-3): d>x => abc,x,0~999 => 1000
        else if(bits[i] > x)
            ans += power10(i);
    }
    return ans;
}
int main(){
    int a, b;
    while(cin>>a>>b, a||b){
        if(a > b)
            swap(a, b);
        for(int i=0; i<10; i++)
            cout<<count(b, i)-count(a-1, i)<<" ";  // 前缀和思想
        cout<<endl;
    }
    return 0;
}
