#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int times[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &times[i]);
    }
    sort(time, time+n);
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (times[i] * (n-i-1));
    }
    cout<<sum<<endl;
    return 0;
}
