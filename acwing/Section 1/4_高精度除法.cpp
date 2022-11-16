#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int b;

// 注意除法是从高位开始计算的, 得到的答案也是高位保存在数组低位
vector<int> bigDivide(vector<int> A, int b, int &r){
    vector<int> ans;
    for(int i=A.size()-1; i>=0; i--){
        r = r * 10 + A[i];
        ans.push_back(r / b);   // 注意这里是对b, 而不是10
        r %= b;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1;
    cin>>s1>>b;
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    int r = 0;
    vector<int> ans = bigDivide(A, b, r);
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    cout<<"\n"<<r<<endl;
    return 0;
}