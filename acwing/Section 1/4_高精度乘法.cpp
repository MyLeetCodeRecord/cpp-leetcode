#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A;
int b;

vector<int> bigMultiply(vector<int> A, int b){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        // 不要管每一位的进位, 而是看作一个整体进位
        t += A[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    while(t!=0){
        ans.push_back(t % 10);
        t /= 10;
    }
    // 去除前导0
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1;
    cin>>s1>>b;
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    vector<int> ans = bigMultiply(A, b);
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}