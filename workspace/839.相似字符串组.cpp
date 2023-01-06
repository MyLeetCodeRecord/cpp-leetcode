/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

// @lc code=start
const int N = 310;
class Solution {
public:
    int father[N];
    void init(int n){
        for(int i=0; i<n; i++)
            father[i] = i;
    }
    void union_2(int u, int v){
        int fu = find(u);
        int fv = find(v);
        if(fu!=fv)
            father[fu] = fv;
    }
    int find(int u){
        if(father[u]!=u)
            father[u] = find(father[u]);
        return father[u];
    }
    // 题目前提已经是「字母异位词」, 不需要考虑长度、字符不同
    bool isSimilar(string &s, string &t){   // 不加引用差十倍...
        int diff = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] != t[i]){
                diff++;
                if(diff > 2)
                    return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        init(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int fi = find(i);
                int fj = find(j);
                if(fi==fj)
                    continue;
                if(isSimilar(strs[i], strs[j]))
                    union_2(fi, fj);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(father[i]==i)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

