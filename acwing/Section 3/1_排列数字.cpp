#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > ans;
vector<int> path;

void backtrack(int n, vector<bool> &visited){
    if((int)path.size() == n){
        ans.push_back(path);
        return ;
    }
    for(int i=1; i<=n; i++){
        if(visited[i]==false){
            visited[i] = true;
            path.push_back(i);
            backtrack(n, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    vector<bool> visited(n+1, false);
    backtrack(n, visited);
    for(vector<int> pth: ans){
        for(int x: pth){
            printf("%d ", x);
        }
        printf("\n");
    }
    return 0;
}