class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int ans = 0;
        for(int l=0, r=0; r < n; r++){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                    mp.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};