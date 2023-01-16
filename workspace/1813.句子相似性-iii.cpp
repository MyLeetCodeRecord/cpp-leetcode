/*
 * @lc app=leetcode.cn id=1813 lang=cpp
 *
 * [1813] 句子相似性 III
 */

// @lc code=start
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> list1, list2;
        string word;
        stringstream ss(sentence1);
        stringstream ss2(sentence2);
        while(ss >> word)
            list1.push_back(word);
        while(ss2 >> word)
            list2.push_back(word);

        // 让list2是更长的句子
        if(list1.size() > list2.size())
            swap(list1, list2);
        int len1 = list1.size();
        int len2 = list2.size();
        // 从左到右
        int i = 0;
        for(i=0; i<len1; i++){
            if(list1[i] != list2[i])
                break;
        }
        // 从右向左
        int j = 0;
        for(j=0; len1-j-1>=i; j++){
            if(list1[len1-j-1] != list2[len2-j-1])
                return false;
        }
        return true;
    }
};
// @lc code=end

