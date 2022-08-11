#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

// 找到左边最近的小于当前元素的值(的位置)
int main(){
    int n, cur;
    stack<int> sk;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        // 持续删除位于cur左边且大于等于cur的栈顶元素, 这些元素永远不会被作为答案
        // 循环终止后的栈顶元素即为cur左边第一个小于cur的元素, 输出即可
        while(!sk.empty() && cur<=sk.top()){
            sk.pop();
        }
        if(sk.empty())
            printf("-1 ");
        else
            printf("%d ", sk.top())
        sk.push(cur);
    }
    return 0;
}