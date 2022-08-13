/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
struct TrieNode{
    TrieNode* child[2]; // '0' or '1', 用数组索引起来比较方便
    TrieNode(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
    TrieNode* trie;
public:
    // 按二进制位从高到低对齐, 构建Trie
    void add(int num){
        TrieNode* t = trie;
        for(int k=30; k>=0; k--){
            int cur = (num>>k) & 1; // 取倒数第k个二进制位
            if(t->child[cur] == NULL){
                t->child[cur] = new TrieNode();
            }
            t = t->child[cur];
        }
    }
    // 没有递归search, 因为本题中Trie的每个分支都是等高的(h=31)
    int search(TrieNode* trie, int num){
        TrieNode* t = trie;
        int ans = 0;
        for (int k = 30; k >= 0; k--) {
            int cur = (num >> k) & 1;
            // 下面的cur=0和cur=1不需要分开讨论, 可以用cur和not_cur统一表示, 详见acwing_6.cpp
            // num的当前位为0, 则应该向Trie的1的方向搜索, 这样可以获得高位异或为1的贪心结果
            if(cur == 0){
                // 存在与cur异或为1的分支 => 移位+1
                if(t->child[1]!=NULL){
                    t = t->child[1];
                    ans = ans*2+1;
                }
                // 不存在与cur异或为1的分支 => 移位
                else{
                    t = t->child[0];
                    ans = ans*2;
                }
            }
            else{
                // 存在与cur异或为1的分支 => 移位+1
                if(t->child[0]!=NULL){
                    t = t->child[0];
                    ans = ans*2+1;
                }
                // 不存在与cur异或为1的分支 => 移位
                else{
                    t = t->child[1];
                    ans = ans*2;
                }
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        // 构建Trie
        trie = new TrieNode();
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            // 这里add和search的顺序和下标没问题的, 因为一个数和它本身异或=0, 不会影响结果
            add(nums[i]);
            ans = max(ans, search(trie, nums[i]));
        }
        return ans;
    }
};
// @lc code=end
