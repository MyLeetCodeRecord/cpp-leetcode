#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct TrieNode{
    TrieNode* child[26];
    int times;
    TrieNode(){
        for(int i=0; i<26; i++)
            child[i] = NULL;
        times = 0;
    }
};
// 本题中作为全局变量或者函数参数都可以
TrieNode* trie;

void insert(string word){
    TrieNode* t = trie;
    for(int i=0; i<(int)word.size(); i++){
        if(t->child[word[i]-'a'] == NULL)
            t->child[word[i]-'a'] = new TrieNode();
        t = t->child[word[i]-'a'];
    }
    t->times++;
}
int search(string word){
    TrieNode* t = trie;
    for(int i=0; i<(int)word.size(); i++){
        if(t->child[word[i]-'a'] == NULL)
            return 0;
        t = t->child[word[i]-'a'];
    }
    return t->times;
}
int main(){
    int n;
    cin>>n;
    string op, word;
    trie = new TrieNode();
    for(int i=0; i<n; i++){
        cin>>op>>word;
        if(op=="I")
            insert(word);
        else if(op=="Q")
            printf("%d\n", search(word));
    }
    return 0;
}