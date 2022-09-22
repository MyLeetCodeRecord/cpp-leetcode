#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

/* 单调栈: 找到左边最近的小于当前元素的值(的位置) */
stack<int> sk;

int main(){
    int n, cur;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &cur);
        // 持续删除位于cur左边大于等于cur的栈顶元素, 这些元素永远不会(比cur更适合)被作为答案
        // 循环终止后的栈顶元素即为cur左边第一个小于cur的元素, 输出即可; 若栈为空则输出-1
        while(!sk.empty() && cur<=sk.top())
            sk.pop();
        if(sk.empty())
            printf("-1 ");
        else
            printf("%d ", sk.top())
        sk.push(cur);
    }
    return 0;
}