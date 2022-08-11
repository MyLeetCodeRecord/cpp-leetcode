#include <cstdio>
#include <iostream>
using namespace std;

// 单调队列: 保持队列内元素单调性(递增/递减)
// “比你年轻(新加进队列的)又比你强(更满足条件), 你就永远没有出头之日”

const int N = 1000010;
int a[N];

// 模拟队列
int q[N];
int h = 0, t = -1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    h = 0;
    t = -1;
    for(int i=0; i<n; i++){
        // 检查 head 是不是滑出了窗口
        if(h<=t && i - q[h] + 1 > k)
            h++;
        // 弹出"older & worse"队尾元素
        while(h<=t && a[i] <= a[q[t]])
            t--;
        // 插入当前元素(无论如何都需要插入)
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    printf("\n");
    h = 0;
    t = -1;
    for(int i=0; i<n; i++){
        // 检查 head 是不是滑出了窗口
        if(h<=t && i - q[h] + 1 > k)
            h++;
        // 弹出"older & worse"队尾元素
        while(h<=t && a[i] >= a[q[t]])
            t--;
        // 插入当前元素(无论如何都需要插入)
        q[++t] = i;
        if(i >= k-1)
            printf("%d ", a[q[h]]);
    }
    return 0;
}