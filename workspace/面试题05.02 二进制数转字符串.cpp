class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() <= 32 && num != 0) {
            num *= 2;
            int cur = (num >= 1);
            ans += (cur + '0');
            num -= cur;
        }
        return ans.size() <= 32 ? ans : "ERROR";
    }
};
