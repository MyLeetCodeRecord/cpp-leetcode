/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
/* Trie:
 * - child[]: 指向子节点的指针数组, 本题为小写英文字母的数量
 * - isEnd: 该节点是否为字符串的结尾
 * - 三个函数其实都是类似的, 按字符串的每个字符移动指针即可
 */
private:
    Trie* child[26];
    bool isEnd;
public:
    Trie() {
        for(int i=0; i<26; i++)
            child[i] = NULL;
        isEnd = false;
    }
    /* insert (遇到不存在的节点则创建, 终点节点设为isEnd=true)
     * 1. 子节点存在, 沿着指针移动到子节点, 继续处理下一个字符。
     * 2. 子节点不存在, 创建一个新的子节点, 记录在child数组的对应位置上, 然后沿着指针移动到子节点, 继续搜索下一个字符。
     */
    void insert(string word) {
        Trie* t = this;
        for(char ch: word){
            if(t->child[ch-'a'] == NULL){
                t->child[ch-'a'] = new Trie();
            }
            t = t->child[ch-'a'];
        }
        t->isEnd = true;
    }
    /* search (是否存在某单词, 终点节点必须isEnd=true)
     * 1. 子节点存在, 沿着指针移动到子节点, 继续处理下一个字符。
     * 2. 子节点不存在, 返回false。
     */
    bool search(string word) {
        Trie* t = this;
        for(char ch: word){
            if(t->child[ch-'a'] == NULL){
                return false;
            }
            t = t->child[ch-'a'];
        }
        return t->isEnd;
    }
    /* startWith (是否存在给定前缀)
     * 1. 子节点存在, 沿着指针移动到子节点, 继续搜索下一个字符。
     * 2. 子节点不存在, 说明字典树中不包含该前缀, 返回空指针。
     */
    bool startsWith(string prefix) {
        Trie* t = this;
        for(char ch: prefix){
            if(t->child[ch-'a'] == NULL){
                return false;
            }
            t = t->child[ch-'a'];
        }
        return true;
    }
};
// @lc code=end

