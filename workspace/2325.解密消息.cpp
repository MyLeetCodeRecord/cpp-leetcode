/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> dict(26, -1);
        int idx = 0;
        for(int i=0; i<key.size(); i++){
            if((key[i]>='a' && key[i]<='z') && dict[key[i]-'a']==-1)
                dict[key[i]-'a'] = idx++;
        }
        for(int i=0; i<message.size(); i++){
            if(message[i]>='a' && message[i]<='z')
                message[i] = dict[message[i]-'a'] + 'a';
        }
        return message;
    }
};
// @lc code=end

