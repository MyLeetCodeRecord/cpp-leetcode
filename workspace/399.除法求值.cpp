/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
// CV
class UnionFind{
    vector<int> f;
    vector<double> weight;
    public:
    UnionFind(int n){
        for(int i=0;i<n;i++){
            f.push_back(i);
            weight.push_back(1.0);
        }
    }
    int find(int x){
        if(x==f[x]) return x;
        int origin=f[x];
        f[x]=find(f[x]);
        weight[x]=weight[x]*weight[origin];
        return f[x];
    }
    void Union(int x,int y,double value){
        int rootx=find(x),rooty=find(y);
        if(rootx == rooty) return;
        f[rootx]=rooty;
        weight[rootx]=value*weight[y]/weight[x];
    } 
    double isConnect(int x,int y){
        int rootx=find(x),rooty=find(y);
        if(rootx!=rooty){
            return -1.0;
        }
        else return weight[x]/weight[y];
    }
};
class Solution {
    unordered_map<string,int> str2idx;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int idx=0;
        for(vector<string> &tmp:equations){
            string a=tmp[0],b=tmp[1];
            if(!str2idx.count(a))str2idx[a]=idx++;
            if(!str2idx.count(b))str2idx[b]=idx++;
        }
        UnionFind Uf(idx);
        for(int i=0;i<equations.size();i++){
            string a=equations[i][0],b=equations[i][1];
            Uf.Union(str2idx[a],str2idx[b],values[i]);
        }
        vector<double> ans;
        for(vector<string> &tmp:queries){
            string a=tmp[0],b=tmp[1];
            if(!str2idx.count(a)||!str2idx.count(b)){
                ans.push_back(-1.0);
                continue;
            }
            ans.push_back(Uf.isConnect(str2idx[a],str2idx[b]));
        }
        return ans;
    }
};
// @lc code=end

