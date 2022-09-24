#include <cstdio>
#include <iostream>
using namespace std;

struct TrieNode{
    TrieNode* child[2];
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
TrieNode* trie;

void insert(int x){
    TrieNode* t = trie;
    // 所有叶节点都在第32层
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & 1;
        if(t->child[cur]==NULL)
            t->child[cur] = new TrieNode();
        t = t->child[cur];
    }
}
int search(int x){
    TrieNode* t = trie;
    int xor = 0;
    for(int i=30; i>=0; i--){
        int cur = (x>>i) & i;
        int not_cur = (cur==0) ? 1 : 0;
        if(t->child[not_cur]!=NULL){
            t = t->child[not_cur];
            xor = xor*2+1;
        }
        else{
            t = t->child[cur];
            xor = xor*2;
        }
    }
    return xor;
}
int main(){
    int n, x;
    cin>>n;
    trie = new TrieNode();
    int ans = 0;
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        ans = max(ans, search(x));
        insert(x);
    }
    printf("%d", ans);
    return 0;
}