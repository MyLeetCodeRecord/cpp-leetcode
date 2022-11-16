#### 高精度计算

> 数组低位存储数字低位比较好, 方便对齐并模拟进位, 即`bits[0]=个位数字`

##### 1. 高精度加法

```CPP
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
        A.push_back(str1[i]);
    for(int i=str2.size()-1; i>=0; i--)
        B.push_back(str2[i]);
    vector<int> ans = bigAdd(A, B);
    for(int i=ans.size()-1; i>=0; i--)
        printf("%d", ans[i]);
    return 0;
}
```


##### 2. 高精度减法

```CPP
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
}
```


##### 3. 高精度乘法

```CPP
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
```


##### 4. 高精度除法
> 注意除法的`计算顺序`和`ans保存顺序`

```CPP
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
```