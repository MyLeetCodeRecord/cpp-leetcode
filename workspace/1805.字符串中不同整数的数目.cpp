/*
 * @lc app=leetcode.cn id=1805 lang=cpp
 *
 * [1805] 字符串中不同整数的数目
 */

// @lc code=start
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int j = 0;
        for(int i=0; i<word.size(); i++){
            if(!isdigit(word[i]))
                continue;
            int j = i;
            while(j<word.size() && isdigit(word[j])){
                j++;
            }
            // 别转为int, 就用string保存即可, 只不过记得去除前导0
            string num = word.substr(i, j-i);
            int k = 0;
            while(num[k]=='0' && k<num.size()-1){   // 注意对000...0留一个0
                k++;
            }
            st.insert(num.substr(k));
            i = j-1;
        }
        return st.size();
    }
};
// @lc code=end

