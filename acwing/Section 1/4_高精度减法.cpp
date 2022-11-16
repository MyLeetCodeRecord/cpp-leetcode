#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

bool compareBig(string s1, string s2){
    if(s1.size()>s2.size())
        return true;
    return s1 > s2;
}
vector<int> bigMinus(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t = A[i] - B[i] + t;
        ans.push_back((t+10) % 10);
        if(t < 0)
            t = -1;
    }
    // 去除前导0, 去掉的是数组尾部的0
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    // 去除前导0, 因为减法前需要比较大小, 注意这里去掉字符串头部的0
    while(s1.size()>1 && s1.back()=='0')
        s1.pop_back();
    while(s2.size()>1 && s2.back()=='0')
        s2.pop_back();
    if(compareBig(s1, s2)==false)
        swap(s1, s2);
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    for(int i=s2.size()-1; i>=0; i--)
        B.push_back(s2[i]-'0');
    vector<int> ans;
    ans = bigMinus(A, B);
    for(int i=ans.size(); i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> A, B;

bool compareBig(string s1, string s2){
    if(s1.size()>s2.size())
        return true;
    return s1 > s2;
}
vector<int> bigMinus(vector<int> A, vector<int> B){
    vector<int> ans;
    int t = 0;
    for(int i=0; i<A.size(); i++){
        t = A[i] - B[i] + t;
        ans.push_back((t+10) % 10);
        if(t < 0)
            t = -1;
    }
    // 去除前导0, 去掉的是数组尾部的0
    while(ans.size()>1 && ans.back()==0)
        ans.pop_back();
    return ans;
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    // 去除前导0, 因为减法前需要比较大小, 注意这里去掉字符串头部的0
    while(s1.size()>1 && s1.back()=='0')
        s1.pop_back();
    while(s2.size()>1 && s2.back()=='0')
        s2.pop_back();
    if(compareBig(s1, s2)==false)
        swap(s1, s2);
    for(int i=s1.size()-1; i>=0; i--)
        A.push_back(s1[i]-'0');
    for(int i=s2.size()-1; i>=0; i--)
        B.push_back(s2[i]-'0');
    vector<int> ans;
    ans = bigMinus(A, B);
    for(int i=ans.size(); i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}