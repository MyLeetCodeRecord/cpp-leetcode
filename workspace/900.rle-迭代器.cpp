/*
 * @lc app=leetcode.cn id=900 lang=cpp
 *
 * [900] RLE 迭代器
 */

// @lc code=start
typedef pair<int, int> PII;
class RLEIterator {
    vector<PII> arr;
    int idx;
public:
    RLEIterator(vector<int>& encoding) {
        int n = encoding.size();
        for(int i=0; i+1<n; i+=2){
            arr.push_back({encoding[i], encoding[i+1]});
        }
        idx = 0;
    }
    
    int next(int n) {
        while(n > 0 && idx < arr.size()){
            if(n <= arr[idx].first){
                arr[idx].first -= n;
                return arr[idx].second;
            }
            else{
                n -= arr[idx++].first;
            }
        }
        return -1;
    }
};
// @lc code=end

