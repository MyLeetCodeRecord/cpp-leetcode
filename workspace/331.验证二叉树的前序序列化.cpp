/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder){
        if(preorder == "#")
            return true;
        int in = 0, out = 0;
        for(int i=0; i<preorder.size(); i++){
            if(preorder[i]==',')
                continue;
            if(preorder[i]=='#')
                in += 1;
            else{
                int j = i;
                while(preorder[j]>='0' && preorder[j]<='9')
                    j++;
                if(i==0)
                    out += 2;
                else{
                    in += 1;
                    out += 2;
                }
                i = j-1;
            }
            if(i!=preorder.size()-1 && in >= out)
                return false;
        }
        return (in==out);
    }
};
// @lc code=end

