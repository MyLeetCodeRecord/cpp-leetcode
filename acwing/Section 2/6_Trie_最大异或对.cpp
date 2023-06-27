#include <cstdio>
#include <iostream>
using namespace std;

struct Trie{
    Trie* child[2];
    Trie(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
void insert(Trie* trie, int x){
    Trie* t = trie;
    // 注意"对齐"
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & 1;
        if(t->child[cur]==NULL)
            t->child[cur] = new Trie();
        t = t->child[cur];
    }
}
int search(Trie* trie, int x){
    Trie* t = trie;
    int ans = 0;
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & 1;
        int not_cur = (cur==0);
        if(t->child[not_cur] != NULL){
            t = t->child[not_cur];
            ans = ans * 2 + 1;
        }
        else{
            t = t->child[cur];
            ans = ans * 2;
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    Trie* trie = new Trie();
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        // 注意先insert再search, 否则第一个x会扫描到两个分支都为空
        // 并且 x XOR x = 0, 不会影响结果
        insert(trie, x);
        ans = max(ans, search(trie, x));
    }
    cout<<ans<<endl;
    return 0;
}