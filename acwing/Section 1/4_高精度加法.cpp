#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

vector<int> bigAdd(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size() || i<B.size(); i++){
        if(i<A.size())
            t += A[i];
        if(i<B.size())
            t += B[i];
        ans.push_back(t % 10);
        t /= 10;
    }
    if(t > 0)
        ans.push_back(t);
    return ans;
}
int main(){
    string str1, str2;
    cin>>str1>>str2;
    for(int i=str1.size()-1; i>=0; i--)
        A.push_back(str1[i]-'0');
    for(int i=str2.size()-1; i>=0; i--)
        B.push_back(str2[i]-'0');
    vector<int> ans = bigAdd(A, B);
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}