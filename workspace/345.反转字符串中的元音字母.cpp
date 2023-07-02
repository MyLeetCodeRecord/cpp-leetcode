/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
    string reverseVowels(string s) {
        unordered_set<int> st = {'a','e','i','o','u','A','E','I','O','U'};
        int n = s.size();
        int l = 0, r = n-1;
        while(l < r){
            while(l<r && st.find(s[l])==st.end())
                l++;
            while(l<r && st.find(s[r])==st.end())
                r--;
            if(l < r)
                swap(s[l++], s[r--]);
        }
        return s;
    }
// @lc code=end

