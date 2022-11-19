#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

bool compareBig(string A, string B){
    if(A.size() == B.size())
        return A >= B;
    return A.size() > B.size();
}
vector<int> bigMinus(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t += A[i];
        if(i<B.size())
            t -= B[i];
        ans.push_back((t+10)%10);
        if(t < 0)
            t = -1;
        else
            t = 0;
    }
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    // 去除前导0, 因为减法前需要比较大小
    // 这里最好用指针找位置, 别一直substr
    while(s1.size()>1 && s1[0]=='0')
        s1 = s1.substr(1, s1.size()-1);
    while(s2.size()>1 && s2[0]=='0')
        s2 = s2.substr(1, s2.size()-1);
    if(compareBig(s1, s2)==false){
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