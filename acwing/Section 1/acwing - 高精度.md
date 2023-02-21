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


##### 5. 高精度自增 - [剑指offer17. 打印从1](https://leetcode.cn/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/)

> 两种解法: 全排列(回溯法) / 大整数加法


```CPP
// 回溯法: 把int类型的path换成string就可以了
vector<int> ans;
int path;
void backtrack(int n, int cur, vector<bool>& visited){
    if(cur == n){
        if(path!=0)
            ans.push_back(path);
        return ;
    }
    for(int i=0; i<=9; i++){
        path = path*10 + i;
        backtrack(n, cur+1, visited);
        path /= 10;
    }
}
vector<int> printNumbers(int n) {
    vector<bool> visited(10, false);
    backtrack(n, 0, visited);
    return ans;
}
```

```CPP
// 大整数加法, 在循环中调用bigAdd, 直到到达「9...9」为止
vector<int> bigAdd(vector<int> A){
    int carry = 0;
    int i = 0;
    do {
        carry = (A[i] + 1);
        A[i] = carry % 10;
        carry /= 10;
        i++;
    } while(i<A.size() && carry != 0);
    if(carry != 0){
        cout<<":>L"<<endl;
        A.push_back(carry);
    }
    return A;
}
```