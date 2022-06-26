/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

// @lc code=start
class Solution {
public:
    // 一个很好的例子, 来说明这种问题要从后往前处理, 不要动不动就substr
    string defangIPaddr(string address) {
        int cnt = 0;
        for(char ch : address){
            if(ch=='.')
                cnt++;
        }
        int right = address.size()-1;
        address.resize(address.size() + 2*cnt);
        for(int i=address.size()-1; i>=0; ){
            if(address[right] != '.')
                address[i--] = address[right--];
            else{
                address[i--] = ']';
                address[i--] = address[right--];
                address[i--] = '[';
            }
        }
        return address;
    }
};
// @lc code=end

