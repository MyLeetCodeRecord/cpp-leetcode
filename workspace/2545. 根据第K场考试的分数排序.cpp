class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        sort(score.begin(), score.end(), [&](const vector<int> &l, const vector<int> &r){
            return l[k] > r[k];
        });
        return score;
    }
};