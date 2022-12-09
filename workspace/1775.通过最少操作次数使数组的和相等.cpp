/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] 通过最少操作次数使数组的和相等
 */

// @lc code=start
/* 题解: https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/solution/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-ocuu/ */
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // 弥补diff时使用的是cnt[], 而构造cnt[]不需要排序
        int cnt[6] = {0};     // cnt[i]的下标是最大变化量
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        int diff = abs(sum1-sum2);
        if(sum1 < sum2){
            swap(nums1, nums2);
        }
        // 交换后nums1的和更大, 越大的数变化量越大
        for(int i=0; i<nums1.size(); i++){
            cnt[nums1[i]-1]++;
        }
        // nums2的和更小, 越小的数变化量越大
        for(int j=0; j<nums2.size(); j++){
            cnt[6-nums2[j]]++;
        }
        int step = 0;
        // 最终弥补diff使用的是cnt[], 而不是遍历nums1和nums2
        for(int i=5; i>=1; i--){
            if(cnt[i] * i >= diff){
                step += (diff + i - 1)/i;   // 需要几个当前 i 足够补全diff
                return step;
            }
            else{
                diff -= cnt[i] * i;
                step += cnt[i];
            }
        }
        return (diff==0) ? step : -1;
    }
};
// @lc code=end

