#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > ans;
vector<int> path;
vector<bool> existed;  // 全局变量或者作为backtrack的&参数都可以

// 检查对角线
bool isLegal(int x){
    // 已有皇后的坐标(i, path[i])
    // 新放入皇后坐标(path.size(), x)
    for(int i=0; i<path.size(); i++){
        // 左上到右下的对角线
        if(path.size()-i == abs(path[i]-x))
            return false;
    }
    return true;
}
// 回溯
void backtrack(int n){
    if(path.size()==n){
        ans.push_back(path);
        return ;
    }
    for(int i=0; i<n; i++){
        if(!existed[i] && isLegal(i)){
            existed[i] = true;
            path.push_back(i);
            backtrack(n);
            path.pop_back();
            existed[i] = false;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    existed.resize(n);
    fill(existed.begin(), existed.end(), false);
    backtrack(n);
    for(vector<int> pth: ans){
        // 输出一个方案
        for(int i=0; i<pth.size(); i++){
            // 输出一行
            for(int j=0; j<n; j++){
                if(j!=pth[i])
                    printf(".");
                else
                    printf("Q");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}