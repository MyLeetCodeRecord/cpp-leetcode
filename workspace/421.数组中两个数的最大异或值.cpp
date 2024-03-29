/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
struct Trie{
    Trie* child[2]; // 0 or 1
    Trie(){
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
private:
    Trie* trie;
public:
    void insert(int x){
        Trie* t = trie;
        int ans = 0;
        for(int k=31; k>=0; k--){
            int cur = (x>>k)&1;
            if(t->child[cur]==NULL)
                t->child[cur] = new Trie();
            t = t->child[cur];
        }
    }
    int search(int x){
        Trie* t = trie;
        int ans = 0;
        for(int k=31; k>=0; k--){
            int cur = (x>>k)&1;
            int not_cur = (cur==1) ? 0 : 1;
            // 如果存在, 选different分支
            if(t->child[not_cur] != NULL){
                t = t->child[not_cur];
                ans *= 2;
                ans += 1;
            }
            // 否则, 选same分支, 不存在则建立节点
            else{
                t = t->child[cur];
                ans *= 2;
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        trie = new Trie();
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for(int x: nums){
            insert(x);
            ans = max(ans, search(x));
        }
        return ans;
    }
};
// @lc code=end
