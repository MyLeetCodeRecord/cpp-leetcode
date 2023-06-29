/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
private:
    vector<int> father;
public:
    void init_ufs(int n){
        father.resize(n);
        for(int i=0; i<n; i++){
            father[i] = i;
        }
    }
    int find(int u){
        return (u==father[u]) ? u : find(father[u]);
    }
    void union_2(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv)
            return ;
        father[pu] = pv;
    }
    bool inSame(int u, int v){
        return find(u)==find(v);
    }
    bool equationsPossible(vector<string>& equations) {
        init_ufs(26);
        for(string eq: equations){
            if(eq[1] == '='){
                union_2(eq[0]-'a', eq[3]-'a');
            }
        }
        for(string eq: equations){
            if(eq[1] == '!'){
                if(inSame(eq[0]-'a', eq[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

