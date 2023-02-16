// 相向双指针: 两个数组都是升序的, 可以保证两个指针向中间移动不漏掉任何可能答案  133ms
#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100010;
int a[N], b[N], n, m, x;

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int j=0; j<m; j++)
        scanf("%d", &b[j]);
    int l = 0, r = m - 1;    // 相向双指针
    while(l<n && r>=0){
        int sum = a[l] + b[r];
        if(sum == x)
            break;
        else if(sum > x)
            r--;
        else if(sum < x)
            l++;
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}

/* // map映射做法: 没有有效利用升序的特点  503ms
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mpA; // val->key的反向映射
int aElement, bElement, n, m, x;

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &aElement);
        mpA[aElement] = i;
    }
    for(int j=0; j<m; j++){
        scanf("%d", &bElement);
        if(mpA.find(x-bElement)!=mpA.end()){
            printf("%d %d\n", mpA[x-bElement], j);
            break;
        }
    }
    return 0;
}
*/