#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

vector<int> bigMinus(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){  // 对每一位A[i]进行处理, 才能完全处理借位
        t += A[i];
        if(i<B.size())
            t -= B[i];
        ans.push_back((t+10)%10);
        if(t < 0)
            t = -1;
        else
            t = 0;
    }
    // 注意ans为0的情况, 至少保留一位
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    // 比较大小, 令s1更大
    if(s1.size() < s2.size() || (s1.size()==s2.size() && s1<s2)){
        swap(s1, s2);
        printf("-");
    }
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    for(int i=s2.size()-1; i>=0; i--)
        B.push_back(s2[i]-'0');

    vector<int> ans = bigMinus(A, B);
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i];
    return 0;
}